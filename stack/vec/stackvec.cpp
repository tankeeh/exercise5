

/* ************************************************************************** */



// ...
/** RIDUZIONE ED ESPANSIONE DEL VETTORE**/

template <typename Data>
void StackVec<Data>:: Expand(){
    Vector<Data>::Resize(this->size*2);
}

template <typename Data>
void StackVec<Data>:: Reduce(){
    Vector<Data>::Resize(this->size/2);
}

/** CONSTRUCTORS DEL VETTORE **/
//COPY CONSTRUCTOR DELLO STACK VETTORE
template <typename Data>
StackVec<Data>::StackVec(const StackVec& stack):Vector<Data>(stack){
    this->index = stack.index;
}

template <typename Data>
StackVec<Data>::StackVec(StackVec&& stack) noexcept:Vector<Data>(std::move(stack)){
    std::swap(this->index,stack.index);
}


template <typename Data>
StackVec<Data>::StackVec():Vector<Data>(2){
}


template <typename Data>
void StackVec<Data>::Push(const Data& item){
    if(this->size != 0) {
        if (this->index == this->size) Expand();
    }else Vector<Data>::Resize(2);


this->elem[this->index] = item;
this->index++;

}


template <typename Data>
void StackVec<Data>::Push(Data&& item){

    if (this->size != 0){
        if(this->index == this->size ) Expand();
    }else Vector<Data>::Resize(2);

    this->elem[this->index] = std::move(item);
    this->index++;
}


template <typename Data>
void StackVec<Data>::Pop() {
    if (this->index > 0) {

        this->elem[index - 1] = Data();
        this->index--;
        if (this->index == this->size / 4) Reduce();
    }
    else throw std::length_error("Non ci sono elementi nello stack.");
}

//FUNZIONE DI TOP DALLO STACK
template  <typename Data>
Data StackVec<Data>::Top()const{
    if(this->index > 0)
    return this->elem[this->index -1];
    else throw std::length_error("Non ci sono elementi nello stack.");
}

template  <typename Data>
Data StackVec<Data>::TopNPop(){
    Data temp = Top();
    this->Pop();
    return temp;
}



/**OPERATORI DI ASSIGNMENT**/


template <typename Data>
StackVec<Data>& StackVec<Data>:: operator=(const StackVec& stack){
    Vector<Data>::operator=(stack);
    this->index = stack.index;
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>:: operator=(StackVec&& stack){
    Vector<Data>::operator=(std::move(stack));
    std::swap(this->index,stack.index);
    return *this;
}



/**OPERATORI DI CONFRONTO**/

template <typename Data>
bool StackVec<Data>:: operator==(const StackVec& stack)const{
    return Vector<Data>::operator==(stack);
}

template <typename Data>
bool StackVec<Data>:: operator!=(const StackVec& stack)const{
    return Vector<Data>::operator!=(stack);
}


/**OPERAZIONI OVERRIDE DA CONTAINER**/


template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return ( this->index == 0);
}

template <typename Data>
int StackVec<Data>::Size() const noexcept {
    return this->index;
}


template <typename Data>
void StackVec<Data>::Clear(){
    Vector<Data>::Clear();
    this->index = 0;
}



