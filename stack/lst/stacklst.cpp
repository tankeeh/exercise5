

/* ************************************************************************** */

/* ************************************************************************** */

// ...
/** COSTRUTTORI DI STACKLST **/

//COPY CONSTRUCTOR DI STACKLST
template <typename Data>
 StackLst<Data>::StackLst(const StackLst& stack):List<Data>(stack){}


//MOVE CONSTRUCTOR DI STACKLST
template <typename Data>
StackLst<Data>::StackLst(StackLst&& stack):List<Data>(std::move(stack)){}


/** ASSIGNMENT DI STACKLST **/

//COPY ASSIGNMENT DI STACKLST
template <typename Data>
StackLst <Data> & StackLst<Data>:: operator=(const StackLst& stack){
     List<Data>::operator=(stack);
     return *this;
}

//MOVE ASSIGNMENT DI STACKLST
template <typename Data>
StackLst<Data>& StackLst<Data>:: operator=(StackLst&& stack){
    List<Data>::operator=(std::move(stack));
    return *this;
}



//FUNZIONE DI PUSH NELLO STACK (COPY)
template  <typename Data>
void StackLst<Data>::Push(const Data& item) noexcept {
    this->InsertAtFront(item);
}



//FUNZIONE DI PUSH NELLO STACK (MOVE)
template  <typename Data>
void StackLst<Data>::Push(Data&& item) noexcept {
    this->InsertAtFront(std::move(item));
}



//FUNZIONE DI POP DALLO STACK
template  <typename Data>
void StackLst<Data>::Pop(){
    if(this->size != 0)this->RemoveFromFront();
    else throw std::length_error("Non ci sono elementi nella lista");
}


//FUNZIONE DI TOP DALLO STACK
template  <typename Data>
Data StackLst<Data>::Top()const{
    if(this->size!= 0)return this->Front();
    else throw std::length_error("Non ci sono elementi nella lista");
}

//FUNZIONE DI TOPNPOP DALLO STACK
template  <typename Data>
Data StackLst<Data>::TopNPop(){
    return this->FrontNRemove();
}

//OPERATOR DI UGUAGLIANZA TRA STACK
template <typename Data>
bool StackLst<Data>::operator==(const StackLst& stack)const{
    return List<Data>::operator==(stack);
}

//OPERATOR DI DISUGUAGLIANZA TRA STACK
template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& stack)const{
    return List<Data>::operator!=(stack);
}

// ...
