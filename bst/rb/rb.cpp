
#include "rb.hpp"

namespace lasd {

/* ************************************************************************** */


    //COPY CONSTRUCTOR DEL NODO
    template<typename Data>
    RB<Data>::RBNode::RBNode(const Data& item){
        this->val = new Data(item);
        this->color = Red;
        this->sx = nullptr;
        this->dx = nullptr;
    }

    //MOVE CONSTRUCTOR DEL NODO
    template<typename Data>
    RB<Data>::RBNode::RBNode(Data &&item){
        this->val = new Data(std::move(item));
        this->color = Red;
        this->sx = nullptr;
        this->dx = nullptr;
    }

    //COSTRUTTORE RICORSIVO DI RBNODE
    template <typename Data>
    RB<Data>::RBNode:: RBNode(RBNode& node){
        this->val = new Data(*node.val);
        this->color = node.color;
        if(node.sx != nullptr) this->sx = new RBNode((RBNode&)*node.sx);
        if(node.dx != nullptr) this->dx = new RBNode((RBNode&)*node.dx);
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::RBNode::Left() {
        if(this->HasLeftChild())
            return const_cast<RBNode*>(const_cast<const RB<Data>::RBNode*>(this)->Left());
        else
            return nullptr;
    }

    //INCAPSULAMENTO DI LEFTCHILD DA BTLINK
    template <typename Data>
    typename RB<Data>::RBNode const* RB<Data>::RBNode:: Left() const{
        if(this->HasLeftChild())
            return static_cast<const RBNode *>(&BinaryTreeLnk<Data>::NodeLnk::LeftChild());
        else
            return nullptr;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::RBNode::Right() {
        if(this->HasRightChild())
            return const_cast<RBNode*>(const_cast<const RB<Data>::RBNode*>(this)->Right());
        else
            return nullptr;
    }

    //INCAPSULAMENTO DI RIGHTCHILD DA BTLINK
    template <typename Data>
    typename RB<Data>::RBNode const* RB<Data>::RBNode:: Right() const{
        if(this->HasRightChild())
            return static_cast<const RBNode *>(&BinaryTreeLnk<Data>::NodeLnk::RightChild());
        else
            return nullptr;
    }



    //COPY CONSTRUCTOR RB
    template<typename Data>
    RB<Data>::RB(const RB& tree){
        const RBNode* root = new RBNode(const_cast<RB&>(tree).Root());
        this->Node = const_cast<RBNode*>(root);
        this->size = tree.size;
    }

    //MOVE CONSTRUCTOR RB
    template<typename Data>
    RB<Data>::RB(RB&& tree){
        std::swap(this->Node,tree.Node);
        std::swap(this->size,tree.size);
    }

    template<typename Data>
    const typename RB<Data>::RBNode& RB<Data>::Root() const{
        return static_cast<const RBNode&>(BinaryTreeLnk<Data>::Root());
        //return (*(this->Node));
    }

    //ROOT (MUTABLE PER NECESSITA' DI ALCUNE FUNZIONI)
    template<typename Data>
    typename RB<Data>::RBNode& RB<Data>::Root() {
        return static_cast<RBNode&>(BinaryTreeLnk<Data>::Root());
    }


    template<typename Data>
    void RB<Data>::NewRoot(const Data &key) noexcept {
        if(!this->Empty())
            BinaryTreeLnk<Data>::Clear();

        this->Node = new RBNode(key);
        static_cast<RBNode*>(this->Node)->color = Black;
        this->size++;
    }

    template<typename Data>
    void RB<Data>::NewRoot(Data&& key) noexcept {
        if(!this->Empty())
            BinaryTreeLnk<Data>::Clear();

        this->Node = new RBNode(std::move(key));
        static_cast<RBNode*>(this->Node)->color = Black;
        this->size++;
    }


    //OPERATORE DI UGUAGLIANZA (CHE RICHIAMA QUELLO DI BST)
    template<typename Data>
    bool RB<Data>::operator==(const RB &tree) const noexcept {
        return BST<Data>::operator==(tree);
    }

    //OPERATORE DI DISUGUAGLIANZA (CHE RICHIAMA QUELLO DI BST)
    template<typename Data>
    bool RB<Data>::operator!=(const RB &tree) const noexcept {
        return BST<Data>::operator!=(tree);
    }




    //DOPPIA ROTAZIONE A SINISTRA
    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::SxDoubleRotate(RBNode* node){
        node->sx = DxRotate(node->Left());
        return SxRotate(node);
    }

    //ROTAZIONE A SINISTRA
    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::SxRotate(RBNode* node) {
        RBNode* root = node->Left();
        node->sx = root->Right();
        root->dx = node;
        return root;
    }

    //ROTAZIONE A DESTRA
    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::DxRotate(RBNode* node) {
        RBNode* root = node->Right();
        node->dx = root->Left();
        root->sx = node;
        return root;
    }

    //DOPPIA ROTAZIONE A DESTRA
    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::DxDoubleRotate(RBNode* node){
        node->dx = SxRotate(node->Right());
        return DxRotate(node);
    }

    //COPY ASSIGNMENT RB
    template<typename Data>
    RB<Data>& RB<Data>::operator=(const RB &tree) {
        this->Clear();
        this->Node = new RBNode((RBNode&)*tree.Node);
        this->size = tree.size;
        return *this;
    }

    //MOVE ASSIGNMENT RB
    template<typename Data>
    RB<Data>& RB<Data>::operator=(RB&& tree) {
        this->Clear();
        std::swap(this->Node, tree.Node);
        std::swap(this->size, tree.size);
        return *this;
    }

    template<typename Data>
    void RB<Data>::Insert(const Data& key) {
        Data item = key;
        if(this->Empty()) NewRoot(std::move(item));
        else this->Node = Insert(std::move(item),&this->Root());
    }

    template<typename Data>
    void RB<Data>::Insert(Data&& key) {
        if(this->Empty()) NewRoot(std::move(key));
        else this->Node = Insert(std::move(key),&this->Root());
    }

    template <typename Data>
    typename RB<Data>::RBNode* RB<Data>::Insert(Data&& key,RBNode* node){
        if(node != nullptr){
            if(key > node->Element()){
                node->dx = Insert(std::move(key),node->Right());
                node = DxBalance(node);
            }
            else if(key < node->Element()){
                node->sx = Insert(std::move(key),node->Left());
                node = SxBalance(node);
            }
        }
        else{
            node = new RBNode(std::move(key));
            this->size++;
        }
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::SxBalance(RB::RBNode *node) {
        int vcase;
        if (!(node->Left()->IsLeaf())) {
            vcase = Vcase_sx(node->Left(), node->Right());
            if (vcase == 1)
                node = SxBalance_Case1(node);
            else if (vcase == 2) {
                node = SxBalance_Case2(node);
                node = SxBalance_Case3(node);
            } else if (vcase == 3)
                node = SxBalance_Case3(node);

        }
        return node;
    }



    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::SxBalance_Case1(RBNode *node) {
        if(node != this->Node)node->color = Red;
        else node->color = Black;
        node->Right()->color = Black;
        node->Left()->color = Black;

        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::SxBalance_Case2(RBNode *node) {
        node->sx = DxRotate(node->Left());
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::SxBalance_Case3(RBNode *node) {
        node = SxRotate(node);
        node ->color = Black;
        node->Right()->color = Red;
        return node;
    }

    template<typename Data>
    int RB<Data>::Vcase_sx(RBNode* sx,RBNode* dx) {
        int v = 0;
        if(sx->color == Red && (dx != nullptr ? dx->color == Red : 0)){
            if((sx->Left() != nullptr ? sx->Left()->color == Red : 0) || (sx->Right() != nullptr ? sx->Right()->color == Red : 0))
                v = 1;
        }
        else{
            if(sx->color == Red){
                if(sx->Right() != nullptr ? sx->Right()->color == Red : 0){
                    v = 2;
                }else{
                    if(sx->Left() != nullptr ? sx->Left()->color == Red : 0)
                        v = 3;
                }
            }
        }
        return v;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::DxBalance(RB::RBNode *node) {
        int vcase;
        if (!(node->Right()->IsLeaf())) {
            vcase = Vcase_dx(node->Left(), node->Right());
            if (vcase == 1)
                node = DxBalance_Case1(node);
            else if (vcase == 2) {
                node = DxBalance_Case2(node);
                node = DxBalance_Case3(node);
            } else if (vcase == 3)
                node = DxBalance_Case3(node);

        }
        return node;
    }

    template<typename Data>
    int RB<Data>::Vcase_dx(RB::RBNode *sx, RB::RBNode *dx) {
        int v = 0;
        if((sx != nullptr ? sx->color == Red : 0) && dx->color == Red){
            if((dx->Left() != nullptr ? dx->Left()->color == Red : 0) || (dx->Right() != nullptr ? dx->Right()->color == Red : 0))
                v = 1;
        }
        else{
            if(dx->color == Red){
                if(dx->Left() != nullptr ? dx->Left()->color == Red : 0){
                    v = 2;
                }else{
                    if( dx->Right() != nullptr ? dx->Right()->color == Red : 0)
                        v = 3;
                }
            }
        }
        return v;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::DxBalance_Case1(RBNode *node) {
        if(node != this->Node)node->color = Red;
        else node->color = Black;

        node->Left()->color = Black;
        node->Right()->color = Black;

        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::DxBalance_Case2(RBNode *node) {
        node->dx = SxRotate(node->Right());
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::DxBalance_Case3(RBNode *node) {
        node = DxRotate(node);
        node ->color = Black;
        node->Left()->color = Red;
        return node;
    }




    template<typename Data>
    void RB<Data>::Remove(const Data &key) noexcept {
        this->Node = Remove(&this->Root(),key);
    }

    template<typename Data>
    Data RB<Data>::MinNRemove() {
        if(!(this->Empty())) {
            Data min = this->Min();
            this->Remove(min);
            return min;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }

    template<typename Data>
    void RB<Data>::RemoveMin() {
        if(!(this->Empty())) {
            Remove(this->Min());
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }

    template<typename Data>
    Data RB<Data>::MaxNRemove() {
        if(!(this->Empty())) {
            Data max = this->Max();
            this->Remove(max);
            return max;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    template<typename Data>
    void RB<Data>::RemoveMax() {
        if(!(this->Empty())) {
            Remove(this->Max());
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    template<typename Data>
    Data RB<Data>::PredecessorNRemove(const Data &key) {
        Data ret = this->Predecessor(key);
        Remove(ret);
        return ret;
    }

    template<typename Data>
    void RB<Data>::RemovePredecessor(const Data &key) {
        Remove(this->Predecessor(key));
    }

    template<typename Data>
    Data RB<Data>::SuccessorNRemove(const Data &key) {
        Data ret = this->Successor(key);
        Remove(ret);
        return ret;
    }

    template<typename Data>
    void RB<Data>::RemoveSuccessor(const Data &key) {
        Remove(this->Successor(key));
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove(RB::RBNode *node,const Data& key) {
        if(node != nullptr){
            if(node->Element() < key){
                node->dx = Remove(node->Right(),key);
                node = Remove_DxBalance(node);
            }
            else if(node->Element() > key){
                node->sx = Remove(node->Left(),key);
                node = Remove_SxBalance(node);
            }
            else
                node = RemoveNode(node);
        }
        return node;
    }


    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::RemoveNode(RB::RBNode *node) {
        RBNode* temp;
        if( node->Left() == nullptr || node->Right() == nullptr){
            temp = node;

            if(!node->HasLeftChild())
                node = node->Right();
            else if(!node->HasRightChild())
                node = node->Left();


            if(temp->color == Black && node != nullptr)
                BlackPropagate(node);
        }
        else{
            temp = StaccaMin(node->Right(),node);
            node->Element() = temp->Element();
            node = Remove_DxBalance(node);
        }

        this->size--;
        return node;
    }

    template<typename Data>
    void RB<Data>::BlackPropagate(RBNode *node) {
        if(node->color == Red)
            node->color = Black;
        else
            node->color = DeepBlack;
    }


    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::StaccaMin(RBNode *node, RBNode *parent) {
        RBNode* temp = nullptr;
        if(node != nullptr){
            if(node->HasLeftChild()){
                temp = StaccaMin(node->Left(),node);
                if(node == parent->Left())
                    parent->sx = Remove_SxBalance(node);
                else
                    parent->dx = Remove_DxBalance(node);

                node = temp;
            }
            else{
                temp = node;
                if(node == parent->Left())
                    parent->sx = node->Right();
                else
                    parent->dx = node->Right();

                if(node->color == Black && node->Right()!= nullptr)
                    BlackPropagate(node->Right());
            }
        }
        return temp;
    }


    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_SxBalance(RBNode *node) {
        if(!(node->IsLeaf())){
            int vcase = Remove_Vcase_sx(node->Left(),node->Right());

            if (vcase == 1) {
                node = Remove_SxBalance_Case1(node);
                node->sx = Remove_SxBalance(node->Left());
            }
            else if (vcase == 2)
                node = Remove_SxBalance_Case2(node);
            else if (vcase == 3)
                node = Remove_SxBalance_Case3(node);
            else if (vcase == 4)
                node = Remove_SxBalance_Case4(node);
        }
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_SxBalance_Case1(RBNode *node) {
        node = DxRotate(node);
        node->color = Black;
        node->Left()->color = Red;
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_SxBalance_Case2(RBNode *node) {
        if(node->HasRightChild())node->Right()->color = Red;
        if(node->HasLeftChild())node->Left()->color = Black;
        BlackPropagate(node);
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_SxBalance_Case3(RBNode *node) {
        node->dx = SxRotate(node->Right());
        node->Right()->color = Black;
        node->Right()->Right()->color = Red;
        node = Remove_SxBalance_Case4(node);
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_SxBalance_Case4(RBNode *node) {
        node = DxRotate(node);
        node->Right()->color = node->color;
        node->color = node->Left()->color;
        node->Left()->color = Black;
        if(node->Left()->HasLeftChild()) node->Left()->Left()->color = Black;
        return node;
    }

    template<typename Data>
    int RB<Data>::Remove_Vcase_sx(RBNode *sx,RBNode *dx) {
        int v = 0;
        if((sx!= nullptr ? sx->getColor() : DeepBlack) == DeepBlack){
        //if(sx != nullptr && sx->color == DeepBlack ) { //&& al posto di || ??
            if(dx != nullptr) {
                if (dx->color == Red)
                    v = 1;
                else if ((dx->Right() == nullptr || dx->Right()->color == Black)  &&
                         (dx->Left() == nullptr || dx->Left()->color == Black ))
                    v = 2;
                else if (dx->Right() == nullptr || dx->Right()->color == Black )
                    v = 3;
                else
                    v = 4;
            }
        }
        return v;
    }

    template<typename Data>
    int RB<Data>::Remove_Vcase_dx(RBNode *sx,RBNode *dx) {
        int v = 0;
        if((dx != nullptr ? dx->getColor() : DeepBlack) == DeepBlack ) {
            if(sx != nullptr){
                if ( sx->color == Red)
                    v = 1;
                else if ((sx->Left() == nullptr || sx->Left()->color == Black ) && (sx->Right() == nullptr || sx->Right()->color == Black ))
                    v = 2;
                else if(sx->Left() == nullptr || sx->Left()->color == Black )
                    v = 3;
                else
                    v = 4;
            }
        }
        return v;
    }



    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_DxBalance(RBNode *node) {
        if(!(node->IsLeaf())){
            int vcase = Remove_Vcase_dx(node->Left(),node->Right());

            if (vcase == 1) {
                node = Remove_DxBalance_Case1(node);
                node->dx = Remove_DxBalance(node->Right());
            }
            else if (vcase == 2)
                node = Remove_DxBalance_Case2(node);
            else if (vcase == 3)
                node = Remove_DxBalance_Case3(node);
            else if (vcase == 4)
                node = Remove_DxBalance_Case4(node);
        }
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_DxBalance_Case1(RBNode *node) {
        node = SxRotate(node);
        node->color = Black;
        node->Right()->color = Red;
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_DxBalance_Case2(RBNode *node) {
        if(node->HasLeftChild())node->Left()->color = Red;
        if(node->HasRightChild())node->Right()->color = Black;
        BlackPropagate(node);
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_DxBalance_Case3(RBNode *node) {
        node->Left()->Right() != nullptr ? node->sx = DxRotate(node->Left()): 0;
        node->Left()->color = Black;
        node->Left()->Left()->color = Red;
        node = Remove_DxBalance_Case4(node);
        return node;
    }

    template<typename Data>
    typename RB<Data>::RBNode* RB<Data>::Remove_DxBalance_Case4(RBNode *node) {
        node = SxRotate(node);
        if(node->HasLeftChild())node->Left()->color = node->color;
        if(node->HasRightChild()) {
            node->color = node->Right()->color;
            node->Right()->color = Black;
            if(node->Right()->HasRightChild())node->Right()->Right()->color = Black;
        }
        return node;
    }





    template<typename Data>
    void RB<Data>::RBCoolTree(typename lasd::RB<Data>::RBNode &node, int depth, const std::string &prefix) {
        std::cout << std::string(depth*2, ' ') << ((depth > 0)? prefix : "Tree Root") << ": [" << node.Element() << "]"<<" -- ";
        if(node.getColor() == lasd::Colori::Red) std::cout<<"Red \n"; else std::cout<<"Black \n";
        if(node.HasLeftChild()) RBCoolTree(*node.Left(), depth+1, prefix + "S");
        if(node.HasRightChild()) RBCoolTree(*node.Right(), depth+1, prefix + "D");
    }








/* ************************************************************************** */

}
