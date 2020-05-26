


/* ************************************************************************** */





//FUNZIONE DISTRUTTORE
template  <typename Data>
Vector<Data>:: ~Vector() noexcept{
    delete[] this->elem;
    this->size=0;
};


//COSTRUTTORE DI DEFAULT DELLA CLASSE VECTOR
template <typename Data>
lasd::Vector<Data>::Vector() {
    this->elem= nullptr;
    this->size=0;
}




//COSTRUTTORE SPECIFICO DELLA CLASSE VECTOR
template <typename Data>
lasd::Vector<Data>::Vector(uint dimension){
    this->size=dimension;
    this->elem = new Data[this->size];
}





//COPY CONSTRUCTOR DELLA CLASSE VECTOR
template <typename Data>
lasd::Vector<Data>:: Vector(const Vector & vec){
    this->size = vec.size;
    this->elem = new Data[this->size];
    for(int i = 0; i<this->size;i++){
        this->elem[i] = vec.elem[i];
    }

}


//MOVIE CONSTRUCTOR DELLA CLASSE VECTOR
template <typename Data>
 lasd::Vector<Data>:: Vector(Vector && vec) noexcept{
    delete[] this->elem;
    
    this->size = vec.size;
    this->elem = vec.elem;
    vec.elem = nullptr;
    vec.size = 0;
}








//COPY ASSIGNMENT DELLA CLASSE VECTOR
template <typename Data>
 Vector<Data> & Vector<Data>::operator=(const Vector & vec){
    Vector::Clear();
    this->size = vec.size;
    this->elem = new Data[vec.size];
    std::copy(vec.elem+0,vec.elem+vec.size,this->elem);
    return *this;
}



//MOVE ASSIGNMENT DELLA CLASSE VECTOR
template <typename Data>
Vector<Data> & Vector<Data>::operator=(Vector && vec) noexcept {
    Vector::Clear();
    std::swap(this->size,vec.size);
    std::swap(this->elem,vec.elem);
    return *this;
}






//FUNZIONE RESIZE DELLA CLASSE VECTOR
template <typename Data>
   void Vector<Data>:: Resize(uint newSize){
    if(newSize==0)
        this->Clear();
    else {
        Data *temp;
        if (newSize > this->size) {
            temp = new Data[newSize];
            for (int i = 0; i < this->size; i++) {
                temp[i] = this->elem[i];
            }

            delete[] this->elem;
            this->elem = new Data[newSize];
            for (int i = 0; i < newSize; i++) {
                if(i< this->size) this->elem[i] = temp[i];
                else this->elem[i] = Data();
            }
            this->size = newSize;

        } else {
            temp = new Data[newSize];
            for (int i = 0; i < newSize; i++) {
                temp[i] = this->elem[i];
            }
            delete[] this->elem;
            this->elem = new Data[newSize];
            for (int i = 0; i < newSize; i++) {
                this->elem[i] = temp[i];
            }
            this->size = newSize;
        }
        delete[] temp;
    }

}



//FUNZIONE FRONT PER IL VETTORE
template <typename Data>
Data Vector<Data>::Front()const{
    if(this->size != 0)
    return (this->elem[0]);
    else throw std::length_error("NON CI SONO VALORI");
}


//FUNZIONE BACK PER IL VETTORE
template <typename Data>

Data Vector<Data>::Back()const{
    if(this->size != 0)
    return (this->elem[this->size-1]);
    else  throw std::length_error("NON CI SONO VALORI");
}




//FUNZIONE CLEAR DEL VETTORE
template <typename Data>

void Vector<Data>::Clear(){
    delete[] this->elem;
    this->elem = nullptr;
    this->size=0;
}


//FUNZIONE OPERANDO DI UGUAGLIANZA TRA VETTORI
template <typename Data>
bool Vector<Data>::operator==(const Vector & vec)const noexcept {
    if(this->size!=vec.size) return false;
    else{
        int index = 0;
        bool temp = true;

        while( temp==true && index<this->size){
            if(this->elem[index]!=vec.elem[index]){
                temp= false;
            }
            index++;
        }
        return temp;
    }

}


//FUNZIONE OPERANDO DI DISUGUAGLIANZA TRA VETTORI
template <typename Data>
bool Vector<Data>::operator!=(const Vector & vec)const noexcept {
    if(this->size!=vec.size) return true;
    else{
        int index = 0;
        bool temp = false;

        while( temp==false && index<this->size){
            if(this->elem[index] != vec.elem[index]){
                temp= true;
            }
            index++;
        }
        return temp;
    }

}


//OPERATORE D'ACCESSO AL VETTORE []
template <typename Data>
Data& Vector<Data>:: operator[](const unsigned int position)const{
    if(position > this->size) throw std::length_error("Sei fuori dal range del vettore! \n");
    else return *(this->elem + position);
};

// ...




/** FUNZIONI DI MAP E FOLD PER IL VETTORE **/



//FUNZIONI DI MAP
template <typename Data>
void Vector<Data>::MapPreOrder(MapFunctor function, void* par){
    for(int i = 0; i < this->size;i++){
        function(this->elem[i],par);
    }
};


template <typename Data>
void Vector<Data>::MapPostOrder(MapFunctor function, void* par){
    for(int i = this->size - 1; i >= 0; i--){
        function(this->elem[i],par);
    }
};




//FUNZIONI DI FOLD
template <typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor function, const void* par, void* acc) const{
    for(int i = 0; i < this->size;i++){
        function(this->elem[i],par,acc);
    }
}

template <typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor function, const void* par, void* acc) const{
    for(int i = this->size -1; i >= 0; i--){
        function(this->elem[i],par,acc);
    }
}











