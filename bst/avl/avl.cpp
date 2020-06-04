
#include "avl.hpp"

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    AVL<Data>::AVLNode::AVLNode(const Data &item):BST<Data>::BSTNode(item) {}

    template<typename Data>
    AVL<Data>::AVLNode::AVLNode(Data &&item):BST<Data>::BSTNode(std::move(item)) {
    }


    template<typename Data>
    void AVL<Data>::Insert(Data &&newitem) {
        AVLNode* tempnode = &this->Roott();
        if(this->Empty()) {
            this->Node = new AVLNode(newitem);
            this->size++;
        }
        else {
            while (tempnode->Element() != newitem) {
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

        tempnode->height = std::max(tempnode->Left()->height,tempnode->Right()->height) + 1;
        if(Balance(this->Node) > 1  );

    }

    template<typename Data>
    int AVL<Data>::Balance(AVLNode* node) {
        if(node == nullptr)
        return 0;
        else return (node->Left()->height - node->Right()->height);
    }

    template<typename Data>
    void AVL<Data>::SxBalance(AVLNode* currnode) {
        //AVLNode* currnode = node;
        if(currnode->Left()->height - currnode->Right()->height == 2) {
            if (currnode->Left()->Left()->height > currnode->Left()->Right()->height) {
                currnode = SxRotate(currnode);
            } else {
                currnode = SxDoubleRotate(currnode);
            }
        }else
            currnode->height = std::max(currnode->Left()->height,currnode->Right()->height) + 1;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::SxRotate(AVLNode* node) {
        AVLNode* root = node->Left();
        node->Left() = root->Right();
        root->Right() = node;
        node->height = 1 + std::max(node->Left()->height,node->Right()->height);
        return root;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::SxDoubleRotate(AVLNode* node){

    }

    template<typename Data>
    void AVL<Data>::Insert(const Data &key) {
        BST<Data>::Insert(key);
    }

    template<typename Data>
    typename AVL<Data>::AVLNode& AVL<Data>::Root() {
        return *((AVLNode*)BinaryTreeLnk<Data>::Node);
    }

    template<typename Data>
    const typename AVL<Data>::AVLNode&  AVL<Data>::Root() const{
        return *((AVLNode*)BinaryTreeLnk<Data>::Node);
    }


// ...

/* ************************************************************************** */


}
