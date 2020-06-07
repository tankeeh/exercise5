
#include "avl.hpp"

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    AVL<Data>::AVLNode::AVLNode(const Data &item):BST<Data>::BSTNode(item) {}

    template<typename Data>
    AVL<Data>::AVLNode::AVLNode(Data &&item):BST<Data>::BSTNode(std::move(item)) {}

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

    template <typename Data>
    AVL<Data>::AVLNode:: AVLNode(AVLNode& node){
        this->val = new Data(*node.val);
        this->height = node.height;
        if(node.sx != nullptr) this->sx = new AVLNode((AVLNode&)*node.sx);
        if(node.dx != nullptr) this->dx = new AVLNode((AVLNode&)*node.dx);
    }

    template<typename Data>
    void AVL<Data>::NewRoot(const Data &item) noexcept {
        BinaryTreeLnk<Data>::Clear();
        this->Node = new AVLNode(item);
        this->size++;
    }

    template<typename Data>
    void AVL<Data>::NewRoot(Data&& item) noexcept {
        BinaryTreeLnk<Data>::Clear();
        this->Node = new AVLNode(std::move(item));
        this->size++;
    }

    template<typename Data>
    AVL<Data>::AVL(const AVL& tree):BinaryTreeLnk<Data>(tree){}

    template<typename Data>
    AVL<Data>::AVL(AVL&& tree):BinaryTreeLnk<Data>(std::move(tree)){}



    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::SxBalance(AVLNode* currnode) {
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
    typename AVL<Data>::AVLNode* AVL<Data>::DxBalance(AVLNode* currnode) {
        if(Height(currnode->Left()) - Height(currnode->Right()) == 2) {
            if (Height(currnode->Right()->Right()) > Height(currnode->Right()->Left())) {
                currnode = DxRotate(currnode);
            } else {
                currnode = DxDoubleRotate(currnode);
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
        node->sx = DxRotate(node->Left());
        return SxRotate(node);
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::DxRotate(AVLNode* node) {
        AVLNode* root = node->Right();
        node->dx = root->Left();
        root->sx = node;
        node->height = 1 + std::max(Height(node->Left()),Height(node->Right()));
        return root;
    }


    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::DxDoubleRotate(AVLNode* node){
        node->dx = SxRotate(node->Right());
        return DxRotate(node);
    }

    template<typename Data>
    void AVL<Data>::Insert(const Data& newitem) {
        this->Node = Insert(newitem,&this->Root());
    }

    template<typename Data>
    void AVL<Data>::Insert(Data &&newitem) {
        Data item = newitem;
        this->Node = Insert(std::move(item),&this->Root());
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
        return -1;
        else return node->height;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::Insert(Data key,AVLNode* node) {
        if (node != nullptr) {
            if (node->Element() == key) {
                return node;
            } else if (node->Element() > key) {
                node->sx = Insert(key,node->Left());
                node = SxBalance(node);
            }
            else{
                node->dx = Insert(key,node->Right());
                node = DxBalance(node);
            }
        }
        else{
            node = new AVLNode(key);
            this->size++;
        }
        return node;
    }

    template<typename Data>
    AVL<Data>& AVL<Data>::operator=(const AVL& tree) {
        this->Clear();
        this->Node = new AVLNode((AVLNode&)*tree.Node);
        this->size = tree.size;
        return *this;
    }

    template<typename Data>
    AVL<Data>& AVL<Data>::operator=(AVL&& tree) {
        this->Clear();
        std::swap(this->Node,tree.Node);
        std::swap(this->size,tree.size);
        return *this;
    }




    template<typename Data>
    void AVL<Data>::Remove(const Data &key) noexcept {
        this->Node = Remove(key,&this->Root());
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::Remove(Data key,AVLNode *node){
        if(node != nullptr){
            if(node->Element() > key){
                node->sx = Remove(key,node->Left());
                node = DxBalance(node);
            }
            else if(node->Element() < key){
                node->dx = Remove(key,node->Right());
                node = SxBalance(node);
            } else
                node = RemoveNode(node);

            return node;
        }
        return nullptr;
    }




    template<typename Data>
    typename AVL<Data>::AVLNode *AVL<Data>::RemoveNode(AVLNode* node) {
        AVLNode* temp;
        if(node != nullptr){
            if(node->Left() == nullptr || node->Right() == nullptr){
                temp = node;
                if(node->Left() == nullptr)
                    node = node->Right();
                else
                    node = node->Left();
            }
            else{
                temp = StaccaMin(node->Right(),node);
                node->Element() = temp->Element();
                node = SxBalance(node);
            }
            return node;
        }
        else return nullptr;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::StaccaMin(AVLNode *node, AVL::AVLNode* parent) {
        AVLNode* ret;
        AVLNode* newroot;
        if(node != nullptr){
            if(node->Left() != nullptr) {
                ret = StaccaMin(node->Left(), node);
                newroot = DxBalance(node);
            }
            else{
                ret = node;
                newroot = node->Right();
                if(parent->Left() == node)
                    parent->sx = newroot;
                else
                    parent->dx = newroot;
            }
            return ret;
        }
        return nullptr;
    }

    template<typename Data>
    typename AVL<Data>::AVLNode* AVL<Data>::StaccaMax(AVLNode *node, AVL::AVLNode* parent) {
        AVLNode* ret;
        AVLNode* newroot;
        if(node != nullptr){
            if(node->Right() != nullptr) {
                ret = StaccaMax(node->Right(), node);
                newroot = SxBalance(node);
            }
            else{
                ret = node;
                newroot = node->Left();
                if(parent->Right() == node)
                    parent->dx = newroot;
                else
                    parent->sx = newroot;
            }
            return ret;
        }
        return nullptr;
    }

    template<typename Data>
    const Data AVL<Data>::MinNRemove() {
        if(!(this->Empty())) {
            AVLNode* curr = &this->Root() ;
            this->size--;
            return StaccaMin(curr->Left(),curr)->Element();
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }


    template<typename Data>
    const Data AVL<Data>::MaxNRemove() {
        if(!(this->Empty())) {
            AVLNode* curr = &this->Root() ;
            this->size--;
            return StaccaMax(curr->Right(),curr)->Element();
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    template<typename Data>
    void AVL<Data>::RemoveMin() {
        if(!(this->Empty())) {
            AVLNode* curr = &this->Root() ;
            this->size--;
            AVLNode* uselessNode = StaccaMin(curr->Left(),curr);
            delete uselessNode; //e' legit?
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un minimo.");
    }


    template<typename Data>
    void AVL<Data>::RemoveMax() {
        if(!(this->Empty())) {
            AVLNode* curr = &this->Root() ;
            this->size--;
            AVLNode* uselessNode = StaccaMax(curr->Right(),curr);
            delete uselessNode;
        }
        else throw std::length_error("L'albero e' vuoto, pertanto non e' presente un massimo.");
    }

    template<typename Data>
    bool AVL<Data>::operator==(const AVL &tree) const noexcept {
        return BST<Data>::operator==(tree);
    }

    template<typename Data>
    bool AVL<Data>::operator!=(const AVL &tree) const noexcept {
        return BST<Data>::operator!=(tree);
    }


// ...

/* ************************************************************************** */


}
