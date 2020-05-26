



/* ************************************************************************** */

// ...

template <typename Data>
bool BinaryTree<Data>::NodeEquality(const typename BinaryTree<Data>::Node& Node,const typename BinaryTree<Data>::Node& Node2)const{
    if(Node.IsLeaf() && Node2.IsLeaf()){
        return Node.Element() == Node2.Element();
    }
    else{
        bool temp1 = false;
        bool temp2 = false;
        if(Node.Element() == Node2.Element()){
            if(Node.HasLeftChild() && Node2.HasLeftChild()) temp1 =  NodeEquality(Node.LeftChild(),Node2.LeftChild());
            if(Node.HasRightChild() && Node2.HasRightChild())  temp2 = NodeEquality(Node.RightChild(),Node2.RightChild());
            return temp1 && temp2;
        }
        return false;
    }
}


template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree2) const noexcept{
    if(this->size == tree2.size && this->size!=0){
        return NodeEquality(this->Root(),tree2.Root());
    }else return (this->size == tree2.size && this->size==0);
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& tree2) const noexcept{
return (!(this->operator==(tree2)));
}


//MAP
template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor functor, void *par){
    if(!(this->Empty())) MapPreOrder(functor,par,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor functor, void *par){
    if(!(this->Empty())) MapInOrder(functor,par,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor functor, void *par){
    if(!(this->Empty())) MapPostOrder(functor,par,&this->Root());
}

template <typename Data>
void BinaryTree<Data>:: MapBreadth(MapFunctor functor, void *par){
    if(!(this->Empty())) MapBreadth(functor,par,&this->Root());
}


//FOLD

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor functor,const void *par,void* acc)const{
    if(!(this->Empty())) FoldPreOrder(functor,par,acc,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor functor,const void *par,void* acc)const{
    if(!(this->Empty())) FoldInOrder(functor,par,acc,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor functor,const void *par,void* acc)const{
    if(!(this->Empty())) FoldPostOrder(functor,par,acc,&this->Root());
}



template <typename Data>
void BinaryTree<Data>:: FoldBreadth(FoldFunctor functor,const void *par, void* acc)const{
    if(!(this->Empty())) FoldBreadth(functor,par,acc,&this->Root());
}










/** PROTECTED FUNCTIONS **/


template <typename Data>
void BinaryTree<Data>:: MapBreadth(MapFunctor functor, void *par,Node* node){
    Node* temp = nullptr;
    lasd::QueueVec<Node*> queuetemp;
    queuetemp.Enqueue(node);

    while(!(queuetemp.Empty())){
        temp = queuetemp.HeadNDequeue();
        functor(temp->Element(),par);
        if(temp->HasLeftChild())queuetemp.Enqueue(&temp->LeftChild());
        if(temp->HasRightChild())queuetemp.Enqueue(&temp->RightChild());
    }
}




template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor functor, void *par,Node* temp){
    functor(temp->Element(), par);
        if(temp->HasLeftChild()) MapPreOrder(functor, par, &temp->LeftChild());
        if(temp->HasRightChild())MapPreOrder(functor, par, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor functor, void *par,Node* temp){
    if(temp->HasLeftChild()) MapInOrder(functor, par, &temp->LeftChild());
    functor(temp->Element(), par);
    if(temp->HasRightChild())MapInOrder(functor, par, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor functor, void *par,Node* temp){
    if(temp->HasLeftChild()) MapPostOrder(functor, par, &temp->LeftChild());
    if(temp->HasRightChild())MapPostOrder(functor, par, &temp->RightChild());
    functor(temp->Element(), par);
}











template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor functor,const void *par,void* acc,const Node* node)const{
    const Node* temp = nullptr;
    lasd::QueueVec<const Node*> queuetemp;
    queuetemp.Enqueue(node);

    while(queuetemp.Size() != 0){
        temp = queuetemp.HeadNDequeue();
        functor(temp->Element(),par,acc);
        if(temp->HasLeftChild())queuetemp.Enqueue(&temp->LeftChild());
        if(temp->HasRightChild())queuetemp.Enqueue(&temp->RightChild());
    }
}



template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor functor,const void *par,void* acc,const Node* temp)const{
    functor(temp->Element(), par,acc);
    if(temp->HasLeftChild()) FoldPreOrder(functor, par,acc, &temp->LeftChild());
    if(temp->HasRightChild())FoldPreOrder(functor, par,acc, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor functor,const void *par,void* acc,const Node* temp)const{
    if(temp->HasLeftChild()) FoldInOrder(functor, par,acc, &temp->LeftChild());
    functor(temp->Element(), par,acc);
    if(temp->HasRightChild())FoldInOrder(functor, par,acc, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor functor,const void *par,void* acc,const Node* temp)const{
    if(temp->HasLeftChild()) FoldPostOrder(functor, par,acc, &temp->LeftChild());
    if(temp->HasRightChild())FoldPostOrder(functor, par,acc, &temp->RightChild());
    functor(temp->Element(), par,acc);
}