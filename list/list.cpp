



/* ************************************************************************** */



/**FUNZIONI NODO**/

//COSTRUTTORE NODO
template <typename Data>
lasd::List<Data>::Node::Node(const Data& item){
    this->elem = item;
    this->next = nullptr;
}

//COPY CONSTRUCTOR NODO
template <typename Data>
lasd::List<Data>::Node::Node(const Node & newnode){
    this->elem = newnode.elem;
    this->next = newnode.next;
}

//MOVE CONSTRUCTOR NODO (che prende Data)
template <typename Data>
lasd::List<Data>::Node::Node( Data && newnode){
    std::swap(this->elem,newnode);
    this->next= nullptr;
}

template <typename Data>
lasd::List<Data>::Node:: Node(Node && newnode){
    std::swap(this->elem,newnode.elem);
    std::swap(this->next,newnode.next);
}



//OPERATORE DI UGUAGLIANZA DA NODI
template  <typename Data>
bool List<Data>::Node:: operator==(const Node& node)const noexcept{
    return this->elem == node.elem;
}


//OPERATORE DI DISUGUAGLIANZA DA NODI
template  <typename Data>
bool List<Data>::Node:: operator!=(const Node& node)const noexcept{
    return !(this==node);
}







//OPERATORE DI ACCESSO ALLA LISTA
template <typename Data>
Data& List<Data>:: operator[](const unsigned int position)const {
    if (position >= this->size) throw std::length_error("Sei fuori dal range della lista! \n");
    else {
        Node *nodo = this->node;
        int i = 0;
        while (i < position && nodo != nullptr) {
            nodo = nodo->next;
            i++;
        }
        return nodo->elem;
    }

}





/**FUNZIONI LISTA**/

//COPY CONSTRUCTOR LISTA
template <typename Data>
lasd::List<Data>:: List(const List<Data>& list){
    Node* sentinel = list.node;
    while(sentinel != nullptr){
        InsertAtBack(sentinel->elem);
        sentinel = sentinel->next;
    }
    this->size= list.size;
    delete sentinel;
}


//MOVE CONSTRUCTOR LISTA
template <typename Data>
lasd::List<Data>:: List(List<Data>&& list){
    std::swap((this->node),list.node);
    std::swap(this->size,list.size);
    std::swap((this->tail),list.tail);

}

//DISTRUTTORE LISTA
template <typename Data>
List<Data>:: ~List() noexcept {

while(this->node!= nullptr){

    Node* temp(this->node);
    this->node=this->node->next;
    delete temp;
}

    this->size=0;
}

//INSERIMENTO IN TESTA (COPY)
template <typename Data>
void lasd::List<Data>:: InsertAtFront(const Data& item) {
    Node* newnode = new Node(item);

    if (this->node != nullptr) {
        newnode->next = this->node;
        this->node=newnode;
    }else{
        this->node=newnode;
    }

    this->size++;
    if(this->size == 1) this->tail = this->node;
}

//INSERIMENTO IN TESTA (MOVE)
template <typename Data>
void lasd::List<Data>::InsertAtFront(Data&& item){
    Node* newnode = new Node(std::move(item));

    if (this->node != nullptr) {
        newnode->next = this->node;
        this->node=newnode;
    }else{
        this->node=newnode;
    }

    this->size++;
    if(this->size == 1) this->tail = this->node;

}


//FUNZIONE FRONT
template <typename Data>
Data List<Data>::Front() const {
    if (this->node != nullptr)
        return this->node->elem;
    else {
        throw std::length_error("NON CI SONO VALORI");
    }
}

//FUNZIONE FRONTNREMOVE
template <typename Data>
Data List<Data>::FrontNRemove() {
    Data data = Front();
    RemoveFromFront();
    return data;
}


//FUNZIONE BACK
template <typename Data>
Data List<Data>:: Back() const{
    if (this->node != nullptr)
        return this->tail->elem;
    else {
        throw std::length_error("NON CI SONO VALORI");
    }
}

//INSERIMENTO IN CODA (COPY)
template <typename Data>
void lasd::List<Data>:: InsertAtBack(const Data& item){

    if(this->node == nullptr){
        this->InsertAtFront(item);
    }
    else{
        Node* newnode = new Node(item);
        this->tail->next = newnode;
        this->tail = newnode;
        this->size++;
    }

}


//INSERIMENTO IN CODA (MOVE)
template <typename Data>
void lasd::List<Data>:: InsertAtBack(Data&& item){

    if(this->node == nullptr){
        this->InsertAtFront(std::move(item));
    }
    else{
        Node* newnode = new Node(std::move(item));
        this->tail->next = newnode;
        this->tail = newnode;
        this->size++;
    }

}


//CLEAR DELLA LISTA
template <typename Data>
void lasd::List<Data>::Clear() {
    while (this->node != nullptr) {
        Node *temp(this->node);
        this->node = this->node->next;
        delete temp;
    }
    this->size = 0;
}



//FUNZIONE UGUAGLIANZA TRA LISTE
template <typename Data>
bool List<Data>:: operator==(const List<Data>& list) const noexcept{
    if(this->size != list.size){
        return false;
    }
    else{
        Node* node1 = this->node;
        Node* node2 = list.node;
       bool temp = true;
       while (temp == true && node1 != nullptr){
           if(node1->elem != node2->elem) temp = false;

           node1=node1->next;
           node2=node2->next;
       }
        return temp;
    }
}


//FUNZIONE DISUGUAGLIANZA TRA LISTE
template <typename Data>
bool List<Data>:: operator!=(const List<Data>& list) const noexcept{
return !(this->operator==(list));
}

//FUNZIONE REMOVEFROMFRONT
template <typename Data>
void List<Data>:: RemoveFromFront(){
    if(this->node == nullptr) throw std::length_error("Non e' presente un primo elemento della lista.");
    else {
        Node *temp = this->node;
        this->node = this->node->next;
        delete temp;
        this->size--;
    }
}





/**FUNZIONI ASSIGNMENT**/

//FUNZIONE DI COPY ASSIGNEMENT DELLA LISTA
template <typename Data>
List<Data> & List<Data>::operator=(const List& list){
    this->Clear();

    Node* supnode = list.node;
    List<Data> newlist;

    int j=0;
    while(j<list.size) {
        newlist.InsertAtBack(supnode->elem);
        supnode = supnode->next;
       j++;
    }
    std::swap(this->node,newlist.node);
    std::swap(this->size,newlist.size);

    return *this;
}

//FUNZIONE DI MOVE ASSIGNEMENT DELLA LISTA
template <typename Data>
List<Data> & List<Data>::operator=(List&& list){
    Clear();

    std::swap(this->node,list.node);
    std::swap(this->size,list.size);

    return *this;
}











/** FUNZIONI DI MAP E FOLD **/


/**MAP**/
template <typename Data>
void lasd::List<Data>::MapPreOrder(MapFunctor functor, void *par) {
MapPreOrder(functor,par,this->node);
}


template <typename Data>
void lasd::List<Data>::MapPreOrder(MapFunctor functor, void* par, Node* temp){

    while (temp!= nullptr){
        functor(temp->elem,par);
        temp = temp->next;
    }
}





template <typename Data>
void lasd::List<Data>::MapPostOrder(MapFunctor functor, void *par) {
    MapPostOrder(functor,par,this->node);
}

template <typename Data>
void lasd::List<Data>:: MapPostOrder(MapFunctor functor, void *par,Node* temp){

    if(temp != nullptr){
        MapPostOrder(functor,par,temp->next);
        functor(temp->elem,par);
    }

}



/**FOLD**/


template <typename Data>
void List<Data>:: FoldPreOrder(FoldFunctor functor, const void *par, void *acc) const{
    FoldPreOrder(functor,par,acc,this->node);
}

template <typename Data>
void List<Data>:: FoldPreOrder(FoldFunctor functor, const void *par, void *acc,Node*temp) const{
    while (temp!= nullptr){
        functor(temp->elem,par,acc);
        temp = temp->next;
    }
}



template <typename Data>
void lasd::List<Data>::FoldPostOrder(FoldFunctor functor, const void *par,void *acc) const {
    FoldPostOrder(functor,par,acc,this->node);
}

template <typename Data>
void lasd::List<Data>::FoldPostOrder(FoldFunctor functor, const void *par,void *acc,Node* temp) const {
    if(temp != nullptr){
       FoldPostOrder(functor,par,temp->next);
       functor(temp->elem,par,acc);
    }
}