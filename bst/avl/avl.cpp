
#include "avl.hpp"

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    AVL<Data>::AVLNode::AVLNode(const Data &item):BST<Data>::BSTNode(item) {}

    template<typename Data>
    AVL<Data>::AVLNode::AVLNode(Data &&item):BST<Data>::BSTNode(std::move(item)) {
    }

    template<typename Data>
    typename AVL<Data>::AVLNode *AVL<Data>::AVLNode::Left() {
        if(this->HasLeftChild())
            return static_cast<typename AVL<Data>::AVLNode*>(BST<Data>::BSTNode::Left());
        else
            return nullptr;
    }

    template<typename Data>
    const typename AVL<Data>::AVLNode *AVL<Data>::AVLNode::Left() const{
        if(this->HasLeftChild())
            return static_cast<const typename AVL<Data>::AVLNode*>(const_cast<AVL<Data>::AVLNode*>(this)->Left());
        else
            return nullptr;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::AVLNode::Right() {
        if(this->HasRightChild())
            return static_cast<typename AVL<Data>::AVLNode*>(BST<Data>::BSTNode::Right());
        else
            return nullptr;
    }



    template<typename Data>
    const typename AVL<Data>::AVLNode *AVL<Data>::AVLNode::Right() const{
        if(this->HasRightChild())
            return static_cast<const typename AVL<Data>::AVLNode*>(const_cast<AVL<Data>::AVLNode*>(this)->Right());
        else
            return nullptr;
    }


    template<typename Data>
    void AVL<Data>::Insert(Data &&newitem) {
        this->Node = Insert(newitem,&this->Root());
        /*
        if(this->Empty()) {
            this->Node = new AVLNode(newitem);
            this->size++;
        }
        else {
            AVLNode* tempnode = &this->Root();
            while (tempnode->Element() != newitem) {
                tempnode->height = std::max(Height(tempnode->Left()),Height(tempnode->Right())) + 1;

                if (newitem < tempnode->Element()) {
                    if (tempnode->HasLeftChild())
                        tempnode = tempnode->Left();
                    else {
                        tempnode->sx = new AVLNode(newitem);
                        tempnode = tempnode->Left();
                        this->size++;
                        tempnode = SxBalance(tempnode);
                    }

                } else {
                    if (tempnode->HasRightChild())
                        tempnode = tempnode->Right();
                    else {
                        tempnode->dx = new AVLNode(newitem);
                        tempnode = tempnode->Right();
                        this->size++;
                    }
                }
            }

        }


*/
    }

    template<typename Data>
    int AVL<Data>::Balance(AVLNode* node) {
        if(node == nullptr)
        return 0;
        else return (node->Left()->height - node->Right()->height);
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::SxBalance(AVLNode* currnode) {
        //AVLNode* currnode = node;
        if(Height(currnode->Left()) - Height(currnode->Right()) == 2) {
            if (Height(currnode->Left()->Left()) > Height(currnode->Left()->Right())) {
                currnode = SxRotate(currnode);
            } else {
                currnode = SxDoubleRotate(currnode);
            }
        }else
            currnode->height = std::max(Height(currnode->Left()),Height(currnode->Right())) + 1;

        return currnode;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::SxRotate(AVLNode* node) {
        AVLNode* root = node->Left();
        node->sx = root->Right();
        root->dx = node;
        node->height = 1 + std::max(Height(node->Left()),Height(node->Right()));
        return root;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::SxDoubleRotate(AVLNode* node){
        return nullptr;
    }

    template<typename Data>
    void AVL<Data>::Insert(const Data &key) {
        BST<Data>::Insert(key);
    }

    template<typename Data>
    typename AVL<Data>::AVLNode& AVL<Data>::Root() {
        return static_cast<AVL<Data>::AVLNode&>(BST<Data>::Root());
    }

    template <typename Data>
    const typename AVL<Data>::AVLNode&  AVL<Data>::Root() const{
        return static_cast<const AVL<Data>::AVLNode&>(BST<Data>::Root());
    }

    template<typename Data>
    int AVL<Data>::Height(AVLNode* node) {
        if(node == nullptr)
        return 0;
        else return node->height;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::Insert(const Data &key,AVLNode* node) {
        if (node != nullptr) {
            if (node->Element() == key) {
                return node;
            } else if (node->Element() > key) {
                node->sx = Insert(key,node->Left());
                node = SxBalance(node);
            }
            else{
                node->dx = Insert(key,node->Right());
                //DxBalance()
            }
        }
        else{
            node= new AVLNode(key);
            this->size++;
        }
        return node;
    }


// ...

/* ************************************************************************** */


}
