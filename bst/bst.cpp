
#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */


/** FUNZIONI NODO **/

    //INCAPSULAMENTO DI LEFTCHILD DA BTLINK (NON CONST)
    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode:: Left(){
       if(this->HasLeftChild())
           return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->Left());
       else
           return nullptr;
    }

    //INCAPSULAMENTO DI LEFTCHILD DA BTLINK
    template <typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode:: Left() const{
        if(this->HasLeftChild())
           return static_cast<const BSTNode *>(&BinaryTreeLnk<Data>::NodeLnk::LeftChild());
        else
            return nullptr;
    }

    //INCAPSULAMENTO DI RIGHTCHILD DA BTLINK (NON CONST)
    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode:: Right(){
        if(this->HasRightChild())
           return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->Right());
        else
            return nullptr;
    }

    //INCAPSULAMENTO DI RIGHTCHILD DA BTLINK
    template <typename Data>
    typename BST<Data>:: BSTNode const* BST<Data>::BSTNode:: Right()const{
        if(this->HasRightChild())
           return static_cast<const BSTNode *>(&BinaryTreeLnk<Data>::NodeLnk::RightChild());
        else
            return nullptr;
    }

    //FUNZIONE DI RICERCA DI UN NODO
    template <typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode::Find(const Data& key)const{
        const BSTNode* temp = this;
        while(temp != nullptr && temp->Element() != key){
            if(key < temp->Element()) temp = temp->Left();
            if(key > temp->Element()) temp = temp->Right();
        }
        return temp;
    }


    //RICERCA DEL PADRE DI UN NODO
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

    //RICERCA DEL PADRE DI UN NODO(VERSIONE NON CONST)
    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::FindParent(const Data &key){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->FindParent(key));
    }

    //RICERCA DEL PADRE DEL MINIMO DI UN ALBERO
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

    //RICERCA DEL PADRE DEL MINIMO DI UN ALBERO (NON CONST)
    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::MinParent(){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->MinParent());
    }


    //RICERCA DEL PADRE DEL MASSIMO DI UN ALBERO
    template<typename Data>
    typename BST<Data>::BSTNode const* BST<Data>::BSTNode::MaxParent() const {
        const BSTNode *tempnode = this;
        const BSTNode* father = tempnode;
        while (tempnode->HasRightChild()) {
            father = tempnode;
            tempnode = tempnode->Right();
        }
        return father;
    }

    //RICERCA DEL PADRE DEL MINIMO DI UN ALBERO (NON CONST)
    template <typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::MaxParent(){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->MaxParent());
    }

    //RICERCA DEL PADRE DEL PREDECESSORE DI UN NODO DATA UNA CHIAVE
    template<typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::PredecessorParent(const Data& key) const {
        const BSTNode *currnode = this;
        const BSTNode* temp = nullptr;
        const BSTNode* grandpa= nullptr;
        bool flag = true;

        while(flag && currnode != nullptr && currnode->Element() != key){
            if(currnode->Element() < key){
                if(!currnode->HasRightChild())
                    flag = false;

                grandpa = temp;

                if(flag){
                    temp = currnode;
                    currnode = currnode->Right();
                }
            }

            else {
                if(!currnode->HasLeftChild())
                    flag = false;

                if(flag){
                    temp = currnode;
                    currnode = currnode->Left();
                }
            }
        }

        if(currnode->HasLeftChild()){
            if( !currnode->Left()->HasRightChild())
                return const_cast<BSTNode*>(currnode);
            else {
                const BSTNode *temp2 = currnode->Left()->MaxParent();
                return const_cast<BSTNode*>(temp2);
            }
        }
        else return const_cast<BSTNode*>(grandpa);


    }

    //RICERCA DEL PADRE DEL SUCCESSORE DI UN NODO DATA UNA CHIAVE
    template<typename Data>
    typename BST<Data>::BSTNode* BST<Data>::BSTNode::SuccessorParent(const Data& key) const {
        const BSTNode *currnode = this;
        const BSTNode* temp = nullptr;
        const BSTNode* grandpa= nullptr;
        bool flag = true;

        while(flag && currnode != nullptr && currnode->Element() != key){
            if(currnode->Element() < key){
                if(!currnode->HasRightChild())
                    flag = false;


                if(flag){
                    temp = currnode;
                    currnode = currnode->Right();
                }
            }

            else {
                if(!currnode->HasLeftChild())
                    flag = false;

                grandpa = temp;

                if(flag){
                    temp = currnode;
                    currnode = currnode->Left();
                }
            }
        }

        if(currnode->HasRightChild()){
            if( !currnode->Right()->HasLeftChild())
                return const_cast<BSTNode*>(currnode);
            else {
                const BSTNode *temp2 = currnode->Right()->MinParent();
                return const_cast<BSTNode*>(temp2);
            }
        }
        else return const_cast<BSTNode*>(grandpa);

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
    BST<Data>& BST<Data>::operator=(const BST& tree){
        BinaryTreeLnk<Data>::operator=(tree);
        return *this;
    }

    //MOVE ASSIGNMENT
    template<typename Data>
    BST<Data>& BST<Data>::operator=(BST && tree){
        BinaryTreeLnk<Data>::operator=(std::move(tree));
        return *this;
    }

    //FUNZIONE RICORSIVA CHE RIEMPIE STRUTTURE PER IL CONFRONTO DI ALBERI
    template <typename Data>
    void BST<Data>::InOrderEnqueueNodes(QueueLst<Data>& queue,const BSTNode* node)const {
            if (node->HasLeftChild()) InOrderEnqueueNodes(queue,node->Left());
            queue.Enqueue(node->Element());
            if (node->HasRightChild()) InOrderEnqueueNodes(queue,node->Right());
    }

    //OPERATORE DI UGUAGLIANZA
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

    //DISUGUAGLIANZA
    template<typename Data>
    bool BST<Data>::operator!=(const BST& tree) const noexcept {
        return (!(BST<Data>::operator==(tree)));
    }

    // ROOT (IMMUTABLE)
    template<typename Data>
    const typename BST<Data>::BSTNode& BST<Data>::Root() const {
        return static_cast<const BSTNode&>(BinaryTreeLnk<Data>::Root());
    }

    // ROOT MUTABLE (PER NECESSITA' DI ALCUNE FUNZIONI)
    template<typename Data>
    typename BST<Data>::BSTNode& BST<Data>::Root(){
        return static_cast<BSTNode&>(BinaryTreeLnk<Data>::Root());
    }

    //FUNZIONE DI NEWROOT PER COPY
    template<typename Data>
    void BST<Data>::NewRoot(const Data& item) noexcept {
        if(!(this->Empty()))
        BinaryTreeLnk<Data>::Clear();

        this->Node = new BSTNode(item);
        this->size++;
    }

    //FUNZIONE DI NEWROOT PER MOVE
    template<typename Data>
    void BST<Data>::NewRoot(Data&& item) noexcept {
        if(!(this->Empty()))
            BinaryTreeLnk<Data>::Clear();

        this->Node = new BSTNode(std::move(item));
        this->size++;
    }


    //FUNZIONE DI INSERT PER COPY
    template<typename Data>
    void BST<Data>::Insert(const Data& newitem) {
        if(this->Empty()) {
            this->Node = new BSTNode(newitem);
            this->size++;
        }
        else {
            BSTNode* tempnode = &this->Root();
            while (tempnode->Element() != newitem) {
                if (newitem < tempnode->Element()) {
                    if (tempnode->HasLeftChild())
                        tempnode = tempnode->Left();
                    else {
                        tempnode->sx = new BSTNode(newitem);
                        tempnode = tempnode->Left();
                        this->size++;
                    }

                } else {
                    if (tempnode->HasRightChild())
                        tempnode = tempnode->Right();
                    else {
                        tempnode->dx = new BSTNode(newitem);
                        tempnode = tempnode->Right();
                        this->size++;
                    }
                }
            }
        }
    }


    //FUNZIONE DI INSERT PER MOVE
    template<typename Data>
    void BST<Data>::Insert(Data&& newitem) {
        if(this->Empty()){
            this->Node = new BSTNode(std::move(newitem));
            this->size++;
        }
        else {
            BSTNode* tempnode = &this->Root();
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


    //FUNZIONE EXISTS
    template<typename Data>
    bool BST<Data>::Exists(const Data& item) const noexcept {
        return this->Root().Find(item) != nullptr;
    }

    //FUNZIONE DI RIMOZIONE DI UN NODO
    template<typename Data>
    void BST<Data>::Remove(const Data& del_item) noexcept {
    if(!(this->Empty())){
        BSTNode *father = this->Root().FindParent(del_item);
        BSTNode *tempnode;
        if (father == nullptr && del_item == this->Root().Element())
            tempnode = &this->Root();
        else if (father != nullptr) {
            if (del_item < father->Element())
                tempnode = father->Left();
            else
                tempnode = father->Right();
        }else return;

        Remove(tempnode,father);
    }
    }


    template<typename Data>
    void BST<Data>::Remove(BSTNode* currnode,BSTNode* father) noexcept {

        if (currnode->IsLeaf()) {
            if (father == nullptr) {
                delete this->Node;
                this->Node = nullptr;
            } else {
                if (currnode->Element() < father->Element()) {
                    father->sx = nullptr;
                } else {
                    father->dx = nullptr;
                }
                delete currnode;
            }
        } else if (currnode->HasLeftChild() && !currnode->HasRightChild()) {
            if (currnode->Left()->IsLeaf()) {
                std::swap(currnode->Element(), currnode->Left()->Element());
                delete currnode->Left();
            } else SkipOnLeft(father, currnode);

        } else if (!currnode->HasLeftChild() && currnode->HasRightChild()) {
            if (currnode->Right()->IsLeaf()) {
                std::swap(currnode->Element(), currnode->Right()->Element());
                delete currnode->Right();
            } else SkipOnRight(father, currnode);
        } else { //ha entrambe i sottoalberi e bisogna discriminare i vari casi...
            if (currnode->Left()->IsLeaf()) {
                std::swap(currnode->Element(), currnode->Left()->Element());
                delete currnode->Left();
                currnode->sx = nullptr;
            } else if (currnode->Right()->IsLeaf()) {
                std::swap(currnode->Element(), currnode->Right()->Element());
                delete currnode->Right();
                currnode->dx = nullptr;
            } else { //(entrambi i nodi non sono foglie)
                //prende il min del sotto albero sinistro e lo mette al posto del nodo che si sta Eliminando
                RemoveMin(currnode, currnode->Right());
            }
        }
        this->size--;


    }


    //FUNZIONE DI RIMOZIONE DEL MINIMO
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




    //RICERCA E RESTITUISCE IL MINIMO
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

    //FUNZIONE CUSTOM CHE RESTITUISCE IL MINIMO DI UN SOTTOALBERO
    template<typename Data>
    const Data& BST<Data>::SubtreeMin(const BSTNode* node) const {
        const BSTNode *tempnode = node;
        while (tempnode->HasLeftChild())
            tempnode = tempnode->Left();
        return tempnode->Element();
    }

    //FUNZIONE CHE CERCA E RESTITUISCE IL MASSIMO
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

    //FUNZIONE CUSTOM CHE RESTITUISCE IL MASSIMO DI UN SOTTOALBERO
    template<typename Data>
    const Data& BST<Data>::SubtreeMax(const BSTNode* node) const {
        const BSTNode *tempnode = node;
        while (tempnode->HasRightChild())
            tempnode = tempnode->Right();
        return tempnode->Element();
    }

    //FUNZIONE CHE COLLEGA PADRE E FIGLIO SINISTRO DEL NODO RIMOSSO
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


    //FUNZIONE CHE COLLEGA PADRE E FIGLIO DESTRO DEL NODO RIMOSSO
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

    //FUNZIONE CHE RESTITUISCE IL SUCCESSORE DI UN DATO NODO
    template<typename Data>
    const Data& BST<Data>::Successor(const Data &key) const{
        const BSTNode *currnode = &this->Root();
        const BSTNode *temp = nullptr;
        if(!this->Empty())
            if (currnode->Element() == key){
            if (currnode->HasRightChild())return SubtreeMin(currnode->Right());
            else throw std::length_error("Non e' presente un successore per questo elemento.");
        }else {
            while (currnode != nullptr && currnode->Element() != key) {
                if (currnode->Element() < key)
                    currnode = currnode->Right();
                else {
                    temp = currnode;
                    currnode = currnode->Left();
                }
            }

            if (currnode != nullptr && currnode->HasRightChild()) {
                if(currnode->Right()->HasLeftChild())
                    temp = currnode->Right()->MinParent()->Left();
                else
                    temp = currnode->Right();
            }

            if (temp != nullptr)
                return temp->Element();
            else throw std::length_error("Non e' presente un successore per questo elemento.");
        }
        else throw std::length_error("Albero vuoto. Non e'possibile trovare un successore.");
    }


    //FUNZIONE CHE RESTITUISCE IL PREDECESSORE DI UN DATO NODO
    template<typename Data>
    const Data& BST<Data>::Predecessor(const Data &key) const{
        const BSTNode *currnode = &this->Root();
        const BSTNode *temp = nullptr;
        if(!this->Empty()) {
            if (currnode->Element() == key) {
                if (currnode->HasLeftChild())return SubtreeMax(currnode->Left());
                else throw std::length_error("Non e' presente un predecessore per questo elemento.");
            } else {
                while (currnode != nullptr && currnode->Element() != key) {
                    if (currnode->Element() < key) {
                        temp = currnode;
                        currnode = currnode->Right();
                    } else {
                        currnode = currnode->Left();
                    }
                }

                if (currnode != nullptr && currnode->HasLeftChild()) {
                    if (currnode->Left()->HasRightChild())
                        temp = currnode->Left()->MaxParent()->Right();
                    else temp = currnode->Left();
                }


                if (temp != nullptr)
                    return temp->Element();
                else throw std::length_error("Non e' presente un predecessore per questo elemento.");
            }
        }
        else throw std::length_error("Albero vuoto. Non e'possibile trovare un predecessore.");
    }

    //FUNZIONE CHE RESTITUISCE IL PREDECESSORE DI UN NODO E LO RIMUOVE
    template<typename Data>
    Data BST<Data>::PredecessorNRemove(const Data &key) {
        if(!(this->Empty())) {
            Data ret;
            BSTNode *toDeleteNodeFather = this->Root().PredecessorParent(key);
            if (toDeleteNodeFather != nullptr) {
                if (key > toDeleteNodeFather->Element()) {
                    ret = toDeleteNodeFather->Right()->Element();
                    Remove(toDeleteNodeFather->Right(), toDeleteNodeFather);
                } else {
                    ret = toDeleteNodeFather->Left()->Element();
                    Remove(toDeleteNodeFather->Left(), toDeleteNodeFather);
                }

            } else if (toDeleteNodeFather == nullptr && this->Root().Element() < key) {
                ret = this->Root().Element();
                Remove(&this->Root(), nullptr);
            } else
                throw std::length_error("Probabilmente il nodo di cui vuoi il predecessore e' piu' piccolo del minimo dell' albero");

            return ret;
        }else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un predecessore per la chiave richiesta.");
    }


    //FUNZIONE CHE RESTITUISCE IL MINIMO DI UN SOTTOALBERO E LO RIMUOVE
    template<typename Data>
    Data BST<Data>::MinNRemove(){
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
            this->size--;
            return min;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }

    //RIMOZIONE DEL MINIMO
    template<typename Data>
    void BST<Data>::RemoveMin() {
        if(!(this->Empty())) {
            BSTNode *todeleteMin;
            todeleteMin = this->Root().MinParent();
            if(!(todeleteMin->Left()->IsLeaf()))SkipOnRight(todeleteMin, todeleteMin->Left());
            else{
                delete todeleteMin->Left();
                todeleteMin->sx = nullptr;
            }
            this->size--;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }

    //FUNZIONE CHE RESTITUISCE IL MASSIMO DI UN SOTTOALBERO E LO RIMUOVE
    template<typename Data>
    Data BST<Data>::MaxNRemove(){
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

            this->size--;
            return max;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    //FUNZIONE DI RIMOZIONE DI UN MAX
    template<typename Data>
    void BST<Data>::RemoveMax() {
        if(!(this->Empty())) {
            BSTNode *todeleteMin;
            todeleteMin = this->Root().MaxParent();
            if(!(todeleteMin->Right()->IsLeaf()))SkipOnLeft(todeleteMin, todeleteMin->Right());
            else{
                delete todeleteMin->Right();
                todeleteMin->dx = nullptr;
            }
            this->size--;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    //RIMOZIONE DEL PREDECESSORE DI UN NODO
    template<typename Data>
    void BST<Data>::RemovePredecessor(const Data &key) {
        if(!(this->Empty())) {
            BSTNode *toDeleteNodeFather = this->Root().PredecessorParent(key);
            if (toDeleteNodeFather != nullptr) {
                if (key > toDeleteNodeFather->Element()) {
                    Remove(toDeleteNodeFather->Right(), toDeleteNodeFather);
                } else {
                    Remove(toDeleteNodeFather->Left(), toDeleteNodeFather);
                }

            } else if (toDeleteNodeFather == nullptr && this->Root().Element() < key) {
                Remove(&this->Root(), nullptr);
            } else
                throw std::length_error("Probabilmente il nodo di cui vuoi il predecessore e' piu' piccolo del minimo dell' albero");

        }else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un predecessore per la chiave richiesta.");

    }

    //RESTITUISCE E RIMUOVE IL SUCCESSORE DI UN NODO
    template<typename Data>
    Data BST<Data>::SuccessorNRemove(const Data &key) {
        if(!(this->Empty())) {
            Data ret;
            BSTNode *toDeleteNodeFather = this->Root().SuccessorParent(key);
            if (toDeleteNodeFather != nullptr) {
                if (key > toDeleteNodeFather->Element()) {
                    ret = toDeleteNodeFather->Right()->Element();
                    Remove(toDeleteNodeFather->Right(), toDeleteNodeFather);
                } else {
                    ret = toDeleteNodeFather->Left()->Element();
                    Remove(toDeleteNodeFather->Left(), toDeleteNodeFather);
                }

            } else if (toDeleteNodeFather == nullptr && this->Root().Element() > key) {
                ret = this->Root().Element();
                Remove(&this->Root(), nullptr);
            } else
                throw std::length_error("Probabilmente il nodo di cui vuoi il successore e' piu' piccolo del minimo dell' albero");

            return ret;
        }else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un successore per la chiave richiesta.");
    }

    //RIMOZIONE DEL SUCCESSORE DI UN NODO
    template<typename Data>
    void BST<Data>::RemoveSuccessor(const Data &key) {
        if(!(this->Empty())) {
            BSTNode *toDeleteNodeFather = this->Root().SuccessorParent(key);
            if (toDeleteNodeFather != nullptr) {
                if (key > toDeleteNodeFather->Element()) {
                    Remove(toDeleteNodeFather->Right(), toDeleteNodeFather);
                } else {
                    Remove(toDeleteNodeFather->Left(), toDeleteNodeFather);
                }

            } else if (toDeleteNodeFather == nullptr && this->Root().Element() > key) {
                Remove(&this->Root(), nullptr);
            } else
                throw std::length_error("Probabilmente il nodo di cui vuoi il successore e' piu' piccolo del minimo dell' albero");

        }else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un successore per la chiave richiesta.");

    }

    template<typename Data>
    void BST<Data>::BeautyTree(typename lasd::BST<Data>::BSTNode &node, int depth, const std::string &prefix) {
        std::cout << std::string(depth*2, ' ') << ((depth > 0)? prefix : "Tree Root") << ": [" << node.Element() << "]\n";
        if(node.HasLeftChild()) BeautyTree(*node.Left(), depth+1, prefix + "S");
        if(node.HasRightChild()) BeautyTree(*node.Right(), depth+1, prefix + "D");
    }













/* ************************************************************************** */

}
