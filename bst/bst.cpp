
#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */

/** FUNZIONI NODO **/

    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode:: Left(){
       if(this->HasLeftChild())
           return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->Left());
       else
           return nullptr;
    }

    template <typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode:: Left() const{
        if(this->HasLeftChild())
           return static_cast<const BSTNode *>(&BinaryTreeLnk<Data>::NodeLnk::LeftChild());
        else
            return nullptr;
    }

    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode:: Right(){
        if(this->HasRightChild())
           return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->Right());
        else
            return nullptr;
    }

    template <typename Data>
    typename BST<Data>:: BSTNode const* BST<Data>::BSTNode:: Right()const{
        if(this->HasRightChild())
           return static_cast<const BSTNode *>(&BinaryTreeLnk<Data>::NodeLnk::RightChild());
        else
            return nullptr;
    }


    template <typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode::Find(const Data& key)const{
        const BSTNode* temp = this;
        while(temp != nullptr && temp->Element() != key){
            if(key < temp->Element()) temp = temp->Left();
            if(key > temp->Element()) temp = temp->Right();
        }
        return temp;
    }


    template <typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode::FindParent(const Data& key)const {
        const BSTNode* temp = this;
        const BSTNode* parent = nullptr;

        if (temp->Element() == key) return nullptr;
        else {
            while (temp->Element() != key && !temp->IsLeaf() && parent!=temp) {
                if (key < temp->Element()) {
                    parent = temp;
                    if(temp->HasLeftChild())temp = temp->Left();
                } else {
                    parent = temp;
                    if(temp->HasRightChild())temp = temp->Right();
                }

            }
            if(temp->Element() == key)return parent;
            else return nullptr;
        }
    }

    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::FindParent(const Data &key){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->FindParent(key));
    }

    template<typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode::MinParent() const {
        const BSTNode *tempnode = this;
        const BSTNode* father;
        while (tempnode->HasLeftChild()) {
            father = tempnode;
            tempnode = tempnode->Left();
        }
        return father;
    }

    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::MinParent(){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->MinParent());
    }


    template<typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode::MaxParent() const {
        const BSTNode *tempnode = this;
        const BSTNode* father;
        while (tempnode->HasRightChild()) {
            father = tempnode;
            tempnode = tempnode->Right();
        }
        return father;
    }

    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::MaxParent(){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->MaxParent());
    }



    /** FUNZIONI BST **/

    //COPY CONSTRUCTOR BST
    template<typename Data>
    BST<Data>::BST(const BST& tree):BinaryTreeLnk<Data>(tree){}

    //MOVE CONSTRUCTOR BST
    template<typename Data>
    BST<Data>::BST(BST&& tree):BinaryTreeLnk<Data>(std::move(tree)){}

    //COPY ASSIGNMENT
    template<typename Data>
    BST<Data>& BST<Data>::operator=(const BST & tree){
        BinaryTreeLnk<Data>::operator=(tree);
        return *this;
    }

    //MOVE ASSIGNMENT
    template<typename Data>
    BST<Data>& BST<Data>::operator=(BST && tree){
        BinaryTreeLnk<Data>::operator=(std::move(tree));
        return *this;
    }

    template <typename Data>
    void BST<Data>::InOrderEnqueueNodes(QueueLst<Data>& queue,const BSTNode* node)const {
            if (node->HasLeftChild()) InOrderEnqueueNodes(queue,node->Left());
            queue.Enqueue(node->Element());
            if (node->HasRightChild()) InOrderEnqueueNodes(queue,node->Right());
    }

    //COMPARISON OPERATOR ==
    template<typename Data>
    bool BST<Data>::operator==(const BST& tree) const noexcept {
        QueueLst<Data> queue1;
        QueueLst<Data> queue2;
        const BSTNode* tempnode = &this->Root();

        if(this->size == tree.size){
            InOrderEnqueueNodes(queue1,tempnode);
            tempnode = &tree.Root();
            InOrderEnqueueNodes(queue2,tempnode);

        }else return false;

        return queue1 == queue2;
    }

    template<typename Data>
    bool BST<Data>::operator!=(const BST& tree) const noexcept {
        return (!(BST<Data>::operator==(tree)));
    }

    template<typename Data>
    const typename BST<Data>::BSTNode& BST<Data>::Root() const {
        return *((BSTNode*)BinaryTreeLnk<Data>::Node);
    }

    template<typename Data>
    typename BST<Data>::BSTNode& BST<Data>::Root(){
        return *((BSTNode*)BinaryTreeLnk<Data>::Node);
    }

    template<typename Data>
    void BST<Data>::NewRoot(const Data& item) noexcept {
        BinaryTreeLnk<Data>::Clear();
        this->Node = new BSTNode(item);
        this->size++;
    }

    template<typename Data>
    void BST<Data>::NewRoot(Data&& item) noexcept {
        BinaryTreeLnk<Data>::Clear();
        this->Node = new BSTNode(std::move(item));
        this->size++;
    }

    template<typename Data>
    void BST<Data>::Insert(const Data& newitem) {
        BSTNode* tempnode = this->Root();
        if(this->Empty()) {
            this->Node = new BSTNode(newitem);
            this->size++;
        }
        else {
            while (tempnode->Element() != newitem) {
                if (newitem < tempnode->Element()) {
                    if (tempnode->HasLeftChild())
                        tempnode = tempnode->Left();
                    else {
                        tempnode->Left() = new BSTNode(newitem);
                        tempnode = tempnode->Left();
                        this->size++;
                    }

                } else {
                    if (tempnode->HasRightChild())
                        tempnode = tempnode->Right();
                    else {
                        tempnode->Right() = new BSTNode(newitem);
                        tempnode = tempnode->Right();
                        this->size++;
                    }
                }
            }
        }
    }

    template<typename Data>
    void BST<Data>::Insert(Data&& newitem) {
        BSTNode* tempnode = &this->Root();
        if(this->Empty()) this->Node = new BSTNode(std::move(newitem));
        else {
            while (tempnode->Element() != newitem) {
                if (newitem < tempnode->Element()) {
                    if (tempnode->HasLeftChild())
                        tempnode = tempnode->Left();
                    else {
                        tempnode->sx = new BSTNode(std::move(newitem));
                        tempnode = tempnode->Left();
                        this->size++;
                    }

                } else {
                    if (tempnode->HasRightChild())
                        tempnode = tempnode->Right();
                    else {
                        tempnode->dx = new BSTNode(std::move(newitem));
                        tempnode = tempnode->Right();
                        this->size++;
                    }
                }
            }
        }
    }



    template<typename Data>
    bool BST<Data>::Exists(const Data& item) const noexcept {
        return this->Root().Find(item) != nullptr;
    }



    template<typename Data>
    void BST<Data>::Remove(const Data& del_item) noexcept {

        BSTNode *father = this->Root().FindParent(del_item);
        BSTNode *tempnode;
        if (father == nullptr && del_item == this->Root().Element())
            tempnode = &this->Root();
        else if(father != nullptr){
            if (del_item < father->Element())
                tempnode = father->Left();
            else
                tempnode = father->Right();
        }else return;


        if (tempnode->IsLeaf()){
            if(tempnode->Element() < father->Element()){
                father->sx = nullptr;
            }
            else{
                father->dx = nullptr;
            }
            delete tempnode;
        }
        else if (tempnode->HasLeftChild() && !tempnode->HasRightChild()) {
            if (tempnode->Left()->IsLeaf()) {
                std::swap(tempnode->Element(), tempnode->Left()->Element());
                delete tempnode->Left();
            } else SkipOnLeft(father,tempnode);

        } else if (!tempnode->HasLeftChild() && tempnode->HasRightChild()) {
            if (tempnode->Right()->IsLeaf()) {
                std::swap(tempnode->Element(), tempnode->Right()->Element());
                delete tempnode->Right();
            } else SkipOnRight(father,tempnode);
        }else{ //ha entrambe i sottoalberi e bisogna discriminare i vari casi...
            if (tempnode->Left()->IsLeaf()) {
                std::swap(tempnode->Element(), tempnode->Left()->Element());
                delete tempnode->Left();
            }else if (tempnode->Right()->IsLeaf()) {
                std::swap(tempnode->Element(), tempnode->Right()->Element());
                delete tempnode->Right();
            }
            else{ //(entrambi i nodi non sono foglie)
            //prende il min del sotto albero sinistro e lo mette al posto del nodo che si sta Eliminando
            RemoveMin(tempnode,tempnode->Right());
            }
        }
        this->size--;
    }

    template<typename Data>
    void BST<Data>::RemoveMin(BSTNode* node,BSTNode *startnode) {
        BSTNode* cercamin = startnode;
        BSTNode* father = startnode;
        while (cercamin->HasLeftChild()) {
            father = cercamin;
            cercamin = cercamin->Left();
        }
        if(cercamin->Element() != startnode->Element()){
            node->Element() = cercamin->Element();
            if(cercamin->HasRightChild())SkipOnRight(father,cercamin);
            else{
                delete cercamin;  //prova a toglierlo e testa con valgrind
                father->sx = nullptr;
            }
        }
        else{
            node->Element() = cercamin->Element();
            SkipOnRight(node,cercamin);
        }
    }


/*
    template<typename Data>
    void BST<Data>::Remove(const Data& del_item) noexcept {

            if(node != nullptr && node->Element() != del_item){
            if(del_item < node->Element()){
                father = node;
                recursiveRemove(del_item, node->Left(),father);
            }
            if(del_item > node->Element()) {
                father = node;
                recursiveRemove(del_item, node->Right(),father);
            }
        }

            if( node->Element() == del_item){
                if(node->IsLeaf()) delete node;
                else if(node->HasLeftChild() && !node->HasRightChild()){

                }
                else if(!node->HasLeftChild() && node->HasRightChild()){


                }
                if(node->HasLeftChild() && node->HasRightChild()){


                }


            }


    }
*/

    template<typename Data>
    const Data &BST<Data>::Min() const {
        if(!this->Empty()) {
            const BSTNode *tempnode = &this->Root();
            while (tempnode->HasLeftChild())
                tempnode = tempnode->Left();

            return tempnode->Element();
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }

    template<typename Data>
    const Data& BST<Data>::SubtreeMin(BSTNode* node) const {
        BSTNode *tempnode = node;
        while (tempnode->HasLeftChild())
            tempnode = tempnode->Left();
        return tempnode->Element();
    }

    template<typename Data>
    const Data &BST<Data>::Max() const {
        if(!this->Empty()) {
        const BSTNode* tempnode = &this->Root();
        while(tempnode->HasRightChild())
            tempnode = tempnode->Right();

        return tempnode->Element();
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    template<typename Data>
    const Data& BST<Data>::SubtreeMax(BSTNode* node) const {
        BSTNode *tempnode = node;
        while (tempnode->HasRightChild())
            tempnode = tempnode->Right();
        return tempnode->Element();
    }

    template<typename Data>
    void BST<Data>::SkipOnLeft(BSTNode *father, BSTNode* son) {
        if(son->Element() < father->Element()){
          std::swap(father->sx,son->sx);
          son->sx = nullptr;
          delete son;
        }
        else{
            std::swap(father->dx,son->dx);
            son->sx = nullptr;
            delete son;
        }
    }

    template<typename Data>
    void BST<Data>::SkipOnRight(BSTNode *father,BSTNode *son) {
        if(son->Element() < father->Element()){
            std::swap(father->sx,son->dx);
            son->dx = nullptr;
            delete son;
        }
        else{
            std::swap(father->dx,son->dx);
            son->dx = nullptr;
            delete son;
        }
    }

    template<typename Data>
    const Data& BST<Data>::Successor(const Data &key) {
        BSTNode* currnode = &this->Root();
        Data* temp = nullptr;
        Data val;
        while(currnode != nullptr && currnode->Element() != key){
            if(currnode->Element() < key)
                currnode = currnode->Right();
            else{
                temp = new Data(currnode->Element());
                currnode = currnode->Left();
            }
        }
        if(currnode != nullptr && currnode->HasRightChild())
            temp = new Data(SubtreeMin(currnode->Right()));

        if(temp != nullptr){
            return currnode->Element();
        }
        else throw std::length_error("Non e' presente un successore per questo elemento.");
        }


    template<typename Data>
    const Data& BST<Data>::Predecessor(const Data &key) {
        BSTNode* currnode = &this->Root();
        Data* temp = nullptr;
        /*
        Data temp = 0;
        bool flag = false;
        while(currnode != nullptr && currnode->Element() != key){
            if(currnode->Element() < key) {
                temp = Data(currnode->Element());
                currnode = currnode->Right();
            }else{
                currnode = currnode->Left();
            }
        }
        if(currnode == nullptr) flag = false;
        if(currnode != nullptr && currnode->HasLeftChild())
            temp = new Data(SubtreeMax(currnode->Left()));


        if(temp != nullptr)
            return *temp;
        else throw std::length_error("Non e' presente un predecessore per questo elemento.");*/
    }


    template<typename Data>
    const Data BST<Data>::MinNRemove(){
        if(!(this->Empty())) {
            BSTNode *todeleteMin;
            Data min = 0;
            todeleteMin = this->Root().MinParent();
            min = todeleteMin->Left()->Element();
            if(!(todeleteMin->Left()->IsLeaf()))SkipOnRight(todeleteMin, todeleteMin->Left());
            else{
                delete todeleteMin->Left();
                todeleteMin->sx = nullptr;
            }

            return min;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }

    template<typename Data>
    const Data BST<Data>::MaxNRemove(){
        if(!(this->Empty())) {
            BSTNode *todeleteMin;
            Data max = 0;
            todeleteMin = this->Root().MaxParent();
            max = todeleteMin->Right()->Element();
            if(!(todeleteMin->Right()->IsLeaf()))SkipOnLeft(todeleteMin, todeleteMin->Right());
            else{
                delete todeleteMin->Right();
                todeleteMin->dx = nullptr;
            }

            return max;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }









/* ************************************************************************** */

}
