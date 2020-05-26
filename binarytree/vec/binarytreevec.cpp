
// ...

//Funzione Custom per calcolare l'altezza di un nodo
template <typename Data>
int BinaryTreeVec<Data>::NodeVec:: GetNodeHeight(){
    return (std::log2(this->curr_index + 1));
}

/** COSTRUTTORI DEL NODO **/

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec(const Data& item,lasd::Vector<NodeVec*> *tree){
    this->val = new Data(item);
    this->treevec = tree;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec(Data&& item,lasd::Vector<NodeVec*> *tree){
    this->val = new Data(std::move(item));
    this->treevec = tree;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: ~NodeVec(){
    delete this->val;
}

template <typename Data>
int BinaryTreeVec<Data>::NodeVec:: getIndex(){
    return this->curr_index;
}

template <typename Data>
void BinaryTreeVec<Data>::NodeVec:: setIndex(int i){
    this->curr_index = i;
}


template<typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return (*this->val);
}

template<typename Data>
Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return (*this->val);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    lasd::Vector<NodeVec*> temp = *(lasd::Vector<NodeVec*>*)(this->treevec);
    if(this->curr_index*2 + 1 >= this->treevec->Size()) return false;
    else return ((NodeVec*)temp[(this->curr_index*2)+1] != nullptr);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    lasd::Vector<NodeVec*> temp = *(lasd::Vector<NodeVec*>*)(this->treevec);
    if(this->curr_index*2 + 2 >= this->treevec->Size()) return false;
    else return ((NodeVec*)temp[(this->curr_index*2)+2] != nullptr);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return (this->HasLeftChild() && this->HasRightChild());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasParent() const noexcept{
    lasd::Vector<NodeVec*> temp = *(lasd::Vector<NodeVec*>*)(this->treevec);
    return ((NodeVec*)temp[(this->curr_index-1)/2] != nullptr && this->curr_index != 0);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftSibling() const noexcept{
    if( this->curr_index != 0 && (this->curr_index%2 != 1)){
        return (*this->treevec)[this->curr_index - 1] != nullptr;

    }else return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightSibling() const noexcept{
    if( this->curr_index != 0 && (this->curr_index%2 != 0)){
        return (*this->treevec)[this->curr_index + 1] != nullptr;
    }else return false;
}


template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::Parent() const {
   if(this->HasParent()) {
       lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
       return *(NodeVec*)vett[(this->curr_index-1)/2];
   }
   else throw std::length_error("Tale nodo non ha un genitore.");
}


template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::NodeVec:: LeftSibling() const{
    if(this->HasLeftSibling()) {
        lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
        return *(NodeVec*)vett[this->curr_index-1];
    }
    else throw std::length_error("Tale nodo non ha un fratello sinistro.");
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::NodeVec:: RightSibling() const{
    if(this->HasRightSibling()){
        lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
        return *(NodeVec*)vett[this->curr_index+1];
    }
    else throw std::length_error("Tale nodo non ha un fratello destro.");
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
    if(this->HasLeftChild())return *(NodeVec*)vett[(this->curr_index*2)+1];
    else throw std::out_of_range("Errore. Tentativo di accesso ad un nodo sinistro non presente.");
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+2];
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+1];
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::RightChild() const {
    lasd::Vector<NodeVec*> vett = *(lasd::Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+2];
}


/** FUNCTIONS PER TREEVEC**/




template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    for (int i=0; i<this->tree.Size();i++){
        if (this->tree[i] != nullptr) delete this->tree[i];
    }
}


//COPY CONSTRUCTOR TREEVEC ON A GIVEN ROOT DATA
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(const Data& item){
    this->NewRoot(item);
}

//MOVE CONSTRUCTOR TREEVEC ON A GIVEN ROOT DATA
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(Data&& item){
    this->NewRoot(std::move(item));
}

//COPY CONSTRUCTOR
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(const BinaryTreeVec& newtree){
    this->size = newtree.size;
    this->treeHeight = newtree.treeHeight;
    this->tree.Resize(newtree.tree.Size());

    for(int j=0; j<this->tree.Size();j++){
        if(newtree.tree[j] != nullptr){
            this->tree[j] = new NodeVec(newtree.tree[j]->Element(),&this->tree);
            this->tree[j]->curr_index = j;
        }
        else this->tree[j] = nullptr;
    }

}

//MOVE CONSTRUCTOR
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(BinaryTreeVec&& newtree){

    std::swap(this->tree,newtree.tree);
    std::swap(this->size,newtree.size);
    std::swap(this->treeHeight,newtree.treeHeight);

    for(int i=0;i<this->tree.Size();i++) if(this->tree[i] != nullptr)this->tree[i]->treevec = &this->tree;
}

//COPY ASSIGNMENT
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>:: operator=(const BinaryTreeVec& newtree) noexcept{
    this->Clear();
    this->size = newtree.size;
    this->treeHeight = newtree.treeHeight;
    this->tree.Resize(newtree.tree.Size());

    for(int j=0; j<this->tree.Size();j++){
        if(newtree.tree[j] != nullptr){
            this->tree[j] = new NodeVec(newtree.tree[j]->Element(),&this->tree);
            this->tree[j]->curr_index = j;
        }
        else this->tree[j] = nullptr;
    }
    return *this;
}

//MOVE ASSIGNMENT
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>:: operator=(BinaryTreeVec&& newtree) noexcept{

    this->Clear();
    std::swap(this->tree,newtree.tree);
    std::swap(this->size,newtree.size);
    std::swap(this->treeHeight,newtree.treeHeight);

    for(int i=0;i<this->tree.Size();i++) if(this->tree[i] != nullptr)this->tree[i]->treevec = &this->tree;
    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& tree2) const noexcept{

    if(this->tree.Size() == tree2.tree.Size() && this->tree.Size()!=0){
        bool temp = true;
        int i = 0;
        while(i<this->Size() && temp) {
            if(this->tree[i] != nullptr && tree2.tree[i] != nullptr) {
                if (this->tree[i]->Element() != tree2.tree[i]->Element()) temp = false;
                i++;
            }else if(this->tree[i] == nullptr && tree2.tree[i] == nullptr) i++;
            else temp = false;
        }
        return temp;
    }else {
        return (this->tree.Size() == tree2.tree.Size() && this->tree.Size() == 0);
    }

}

template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& tree2) const noexcept{
return (!(this->operator==(tree2)));
}

template <typename Data>
void BinaryTreeVec<Data>::NewRoot(const Data& item) noexcept {
    if(!(this->Empty())) this->Clear();
    this->tree.Resize(3);
    this->tree[0] = new NodeVec(item,&tree);
    this->size++;

    this->treeHeight.Resize(2);
    this->treeHeight[0] = 1;
}

template <typename Data>
void BinaryTreeVec<Data>::NewRoot(Data&& item)noexcept {
    if(!(this->Empty())) this->Clear();
    this->tree.Resize(3);
    this->tree[0] = new NodeVec(std::move(item),&tree);
    this->size++;

    this->treeHeight.Resize(2);
    this->treeHeight[0] = 1;
}


template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if(!(this->Empty()))return *this->tree[0];
    else throw std::length_error("L'albero e' vuoto, cioe' non ha una radice.");
}


template<typename Data>
 typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    if(!(this->Empty())) return *this->tree[0];
    else throw std::length_error("L'albero e' vuoto, cioe' non ha una radice.");
}


template<typename Data>
void BinaryTreeVec<Data>::AddLeftChild(BinaryTreeVec::NodeVec &node, Data &&item) noexcept {
    if(this->tree[node.curr_index]->HasLeftChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 1) >= tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 1)] = new NodeVec(std::move(item),&tree);
        this->tree[(node.curr_index*2 + 1)]->curr_index = node.curr_index*2 + 1;
        this->size++;

        this->treeHeight[node.LeftChild().GetNodeHeight()] += 1;
    }

}

template<typename Data>
void BinaryTreeVec<Data>::AddLeftChild(BinaryTreeVec::NodeVec &node, const Data &item) noexcept {
    if(this->tree[node.curr_index]->HasLeftChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 1) >= tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 1)] = new NodeVec(item,&tree);
        this->tree[(node.curr_index*2 + 1)]->curr_index = node.curr_index*2 + 1;
        this->size++;

        this->treeHeight[node.LeftChild().GetNodeHeight()] += 1;
    }
}


template<typename Data>
void BinaryTreeVec<Data>::AddRightChild(BinaryTreeVec::NodeVec &node, const Data &item) noexcept {
    if(this->tree[node.curr_index]->HasRightChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) >= tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 2)] = new NodeVec(item,&tree);
        this->tree[(node.curr_index*2 + 2)]->curr_index = node.curr_index*2 + 2;
        this->size++;

        this->treeHeight[node.RightChild().GetNodeHeight()] += 1;
    }
}


template<typename Data>
void BinaryTreeVec<Data>::AddRightChild(BinaryTreeVec::NodeVec &node,Data&& item) noexcept {
    if(this->tree[node.curr_index]->HasRightChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) >= tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 2)] = new NodeVec(std::move(item),&tree);
        this->tree[(node.curr_index*2 + 2)]->curr_index = node.curr_index*2 + 2;
        this->size++;

        this->treeHeight[node.RightChild().GetNodeHeight()] += 1;
    }
}

template <typename Data>
void BinaryTreeVec<Data>:: RemoveLeftChild(NodeVec& node) noexcept{
if(node.HasLeftChild()){
    this->removeSubtree(this->tree[node.curr_index*2 + 1]);
    this->Reduce();
}
}

template <typename Data>
void BinaryTreeVec<Data>:: RemoveRightChild(NodeVec& node) noexcept{
    if(node.HasRightChild()) {
        this->removeSubtree(this->tree[node.curr_index*2 +2 ]);
        this->Reduce();
    }
}

template <typename Data>
void BinaryTreeVec<Data>:: removeSubtree(NodeVec*& node){
    if(node->HasLeftChild()) removeSubtree(this->tree[node->curr_index*2 + 1]);
    if(node->HasRightChild()) removeSubtree(this->tree[node->curr_index*2 +2 ]);
    this->treeHeight[node->GetNodeHeight()]--;
    delete node;
    node = nullptr;
    this->size--;

}

template <typename Data>
void BinaryTreeVec<Data>:: Expand() noexcept{
this->tree.Resize(this->tree.Size()*2 + 1);
this->treeHeight.Resize(this->treeHeight.Size() + 1);

for(int i= 0; i<this->tree.Size();i++){
    if(this->tree[i] != nullptr) this->tree[i]->treevec = &this->tree;
}

}

template <typename Data>
void BinaryTreeVec<Data>:: Reduce() noexcept{

    int newsize;
    int i=this->treeHeight.Size() -1 ;
    while(i != 1 && (this->treeHeight[i] == 0)){
        i--;
        newsize = this->tree.Size()/2;
    }

    if(i != this->treeHeight.Size() -1 ) {
        this->treeHeight.Resize(i);
        this->tree.Resize(newsize);
    }
}

template <typename Data>
void BinaryTreeVec<Data>:: Clear() noexcept{
    if(!(this->Empty())) {
        for (int i =0; i<this->tree.Size(); i++) {
            delete this->tree[i];
            this->tree[i] = nullptr;
        }
        this->tree.Clear();
        this->treeHeight.Clear();
        this->size = 0;
    }
}






template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor fun ,void* par){
    for(int i = 0; i<this->tree.Size();i++){
        if(this->tree[i] != nullptr) fun(this->tree[i]->Element(),par);
    }
}


template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor fun,const void* par,void* acc) const{
    for(int i = 0; i<this->tree.Size();i++){
        if(this->tree[i] != nullptr) fun(this->tree[i]->Element(),par,acc);
    }
}

