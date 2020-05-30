
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
            while (temp->Element() != key && temp != nullptr) {
                if (key < temp->Element()) {
                    parent = temp;
                    temp = temp->Left();
                } else {
                    parent = temp;
                    temp = temp->Right();
                }

                if(temp->Element() == key)return parent;
            }
        }
    }

    template <typename Data>
    typename BST<Data>::BSTNode * BST<Data>::BSTNode::FindParent(const Data &d){
        return const_cast<BSTNode*>(const_cast<const BST<Data>::BSTNode*>(this)->FindParent(d));
    }

    /** FUNZIONI BST **/

    //COPY CONSTRUCTOR BST
    template<typename Data>
    BST<Data>::BST(const BST& tree):BinaryTreeLnk<Data>(tree){}

    //MOVE CONSTRUCTOR
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
    void BST<Data>::InOrderEnqueueNodes(QueueVec<Data>& queue,const BSTNode* node)const {
       //if(queue.Size() != this->Size()) {
            if (node->HasLeftChild()) InOrderEnqueueNodes(queue,node->Left());
            queue.Enqueue(node->Element());
            if (node->HasRightChild()) InOrderEnqueueNodes(queue,node->Right());

    }

    //COMPARISON OPERATOR ==
    template<typename Data>
    bool BST<Data>::operator==(const BST& tree) const noexcept {
        QueueVec<Data> queue1;
        QueueVec<Data> queue2;
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

    BSTNode* father = this->Root().FindParent(del_item);
    BSTNode* tempnode;
    if(father == nullptr)
        tempnode = &this->Root();
    else {
        if(del_item < father->Element())
        tempnode = father->Left();
        else
            tempnode = father->Right();
    }


            if(tempnode->IsLeaf()) delete tempnode;
            else if(tempnode->HasLeftChild() && !tempnode->HasRightChild()){
                if(tempnode->Left()->IsLeaf()) {
                    std::swap(tempnode->Element(), tempnode->Left()->Element());
                    delete tempnode->Left();
                }else //RemoveMin

            }
            else if(!tempnode->HasLeftChild() && tempnode->HasRightChild()){
                if(tempnode->Right()->IsLeaf()) {
                    std::swap(tempnode->Element(), tempnode->Right()->Element());
                    delete tempnode->Right();
            }else //removeMin
            if(tempnode->HasLeftChild() && tempnode->HasRightChild()){


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
        const BSTNode* tempnode = &this->Root();
        while(tempnode->HasLeftChild())
            tempnode = tempnode->Left();

        return tempnode->Element();
    }

    template<typename Data>
    const Data &BST<Data>::Max() const {
        const BSTNode* tempnode = &this->Root();
        while(tempnode->HasRightChild())
            tempnode = tempnode->Right();

        return tempnode->Element();
    }











/* ************************************************************************** */

}
