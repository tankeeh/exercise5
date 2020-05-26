

/* ************************************************************************** */


// ...




/** CONSTRUCTOR QUEUEVEC **/
//COSTRUTTORE DI DEFAULT
template <typename Data>
QueueVec<Data>:: QueueVec():Vector<Data>(2){};

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& queue):Vector<Data>(queue){
    this->head = queue.head;
    this->tail = queue.tail;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& queue) noexcept:Vector<Data>(std::move(queue)){
    std::swap(this->head,queue.head);
    std::swap(this->tail,queue.tail);
}


/**FUNZIONI DI ESPANSIONE/RIDUZIONE DELLA CODA **/

template <typename Data>
void QueueVec<Data>::Expand() {
    Vector<Data>::Resize(this->size*2);

    int index;
    for(index=0;index < this->tail;index++)
        Vector<Data>::operator[](index+this->size/2) = Vector<Data>::operator[](index);

    this->tail = index + this->size/2;

}

template <typename Data>
void QueueVec<Data>::Reduce(){

    Vector<Data> vectmp(this->size/2);
    int tmp = 0;
    int ind = this->head;

    while(ind != this->tail){
        vectmp[tmp++] = Vector<Data>::operator[](ind);
        ind = (ind+1)%this->size;
    }
    this->head = 0;
    this->tail = tmp;
    Vector<Data>::operator=(std::move(vectmp));
}

/** ASSIGNMENT QUEUEVEC **/

template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator=(const QueueVec& queue){
        this->Clear();
        Vector<Data>::operator=(queue);
        this->head = queue.head;
        this->tail = queue.tail;
        return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator=(QueueVec&& queue){
    this->Clear();
    Vector<Data>::operator=(std::move(queue));
    std::swap(this->head,queue.head);
    std::swap(this->tail,queue.tail);
    return *this;
}


/** OPERATORI DI UGUAGLIANZA/DISUGUAGLIANZA QUEUEVEC **/


template <typename Data>
bool QueueVec<Data>:: operator==(const QueueVec& queue)const{
    if(this->head == queue.head && this->Size()==queue.Size())  return Vector<Data>::operator==(queue);
    else{
        if(this->Size() == queue.Size()){
            bool temp = true;
            int i= this->head;
            int j= queue.head;
            while(temp == true && (i+1)%size!=this->tail){
                if(this->elem[i] != queue.elem[j]) temp = false;
                i=(i+1)%this->size;
                j=(j+1)%queue.size;
            }
            return temp;
        }
        else return false;
    }
}

template <typename Data>
bool QueueVec<Data>:: operator!=(const QueueVec& queue)const{
    return (!(QueueVec<Data>::operator==(queue)));
}


/**OPERAZIONI DI QUEUEVEC**/

//FUNZIONE DI ENQUEUE (COPY)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& item){

    if(this->size != 0) {

        this->elem[tail] = item;
        tail = (tail + 1) % (this->size);
        if (this->head == this->tail) Expand();

    }else Vector<Data>::Resize(2);

}

//FUNZIONE DI ENQUEUE (MOVE)
template <typename Data>
void  QueueVec<Data>::Enqueue(Data&& item){

    if(this->size != 0) {

    this->elem[tail] = std::move(item);
    tail = (tail + 1)%(this->size);
    if (this->head == this->tail) Expand();

    }else Vector<Data>::Resize(2);

}

//FUNZIONE DI DEQUEUE
template <typename Data>
void  QueueVec<Data>::Dequeue(){
    if (tail != head) {
        this->elem[this->head] = Data();
        this->head = (this->head + 1) % this->size;
        if ( Size() < this->size/4) Reduce();
    }
    else throw std::length_error("Non ci sono elementi nella queue.");
}

//FUNZIONE DI HEAD
template <typename Data>
Data QueueVec<Data>::Head() const {
        if (this->head != this->tail) {
            return this->elem[this->head];
        }
     else throw std::length_error("Non ci sono elementi nella queue.");
}

//FUNZIONE DI HEADNDEQUEUE
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
Data temp = Head();
this->Dequeue();
return temp;
}


/**OPERAZIONI OVERRIDE DA CONTAINER**/


template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
return (this->tail==this->head);
}

template <typename Data>
int QueueVec<Data>::Size() const noexcept {
return (this->size - this->head + this->tail)%this->size;
}

template <typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Clear();
    Vector<Data>::Resize(2);
    this->head=0;
    this->tail=0;
}