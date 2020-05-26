

/* ************************************************************************** */
/** COSTRUTTORI DI QUEUELST **/

//COPY CONSTRUCTOR DI QUEUELST
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& queue):List<Data>(queue){}  //used initializer


//MOVE CONSTRUCTOR DI QUEUELST
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& queue):List<Data>(std::move(queue)){}  //used initializer


/** ASSIGNMENT DI QUEUELST **/

//COPY ASSIGNMENT DI QUEUELST
template <typename Data>
QueueLst <Data> & QueueLst<Data>:: operator=(const QueueLst& queue){
    List<Data>::operator=(queue);
    return *this;
}

//MOVE ASSIGNMENT DI QUEUELST
template <typename Data>
QueueLst<Data>& QueueLst<Data>:: operator=(QueueLst&& queue){
    List<Data>::operator=(std::move(queue));
    return *this;
}



//FUNZIONE DI ENQUEUE NELLA QUEUE (COPY)
template  <typename Data>
void QueueLst<Data>::Enqueue(const Data& item) noexcept {
    this->InsertAtBack(item);
}



//FUNZIONE DI ENQUEUE NELLA QUEUE (MOVE)
template  <typename Data>
void QueueLst<Data>::Enqueue(Data&& item) noexcept {
    this->InsertAtBack(std::move(item));
}



//FUNZIONE DI DEQUEUE DALLA QUEUE
template  <typename Data>
void QueueLst<Data>::Dequeue(){
    if(this->size != 0) this->RemoveFromFront();
    else throw std::length_error("Non ci sono elementi nella lista");
}


//FUNZIONE DI HEAD DELLA QUEUE
template  <typename Data>
Data QueueLst<Data>::Head()const{
    if(this->size!=0 )return this->Front();
    else throw std::length_error("Non ci sono elementi nella lista");
}

//FUNZIONE DI HEADNDEQUEUE DELLA QUEUE
template  <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    return List<Data>::FrontNRemove();
}

//OPERATOR DI UGUAGLIANZA TRA QUEUE
template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst& queue)const{
    return List<Data>::operator==(queue);
}

//OPERATOR DI DISUGUAGLIANZA TRA QUEUE
template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& queue)const{
    return List<Data>::operator!=(queue);
}

// ...
// ...
