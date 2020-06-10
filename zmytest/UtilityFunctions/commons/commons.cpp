//
// Created by Antonio on 09/05/2020.
//


/**FUNS ESERCIZIO 1/2 **/

template <typename Data>
void Sum(const Data & dat, const void* par, void *acc) {
    if (dat < *(int*)par){
        *(int*)acc += dat;
    }
}

template <typename Data>
void MoltiplicateFloat(const Data & dat, const void* par, void *acc) {
    if (dat > *(Data*)par){
        *(Data*)acc *= dat;
    }
}

template <typename Data>
void StringConcat(const Data & dat, const void* par, void *acc) {
    if (dat.length() <= *(int*)par){
        *(Data*)acc += dat;
    }
}

template <typename Data>
void UpperCase(Data& elem, void* par){
    std::transform(elem.begin(), elem.end(),elem.begin(), ::toupper);
}

template <typename Data>
void PrintElement(Data& elem, void* par){
    std::cout<<elem<<"    --    ";
}

/*
template <typename Data>
void RBPrintElement(Data& elem, void* par){
    std::cout<<elem<<" "<<"    --    ";
}
 */

template <typename Data>
void SquaredFloat(Data& elem, void* par){
    elem *= elem;
    elem = round(elem*1000)/1000;
}

template <typename Data>
void DuplicateInt(Data& elem, void*){
    elem = elem*2;
}


/**FUNS ESERCIZIO 3 **/

template <typename Data>
void InitialConcatString(Data& elem, void* par){
elem = (*(std::string*)par) + elem;
}

template <typename Data>
void CubedFloat(Data& elem, void* par){
    elem *= elem;
    elem = round(elem*1000)/1000;
}


template <typename Data>
void TriplicateInt(Data& elem, void*){
    elem = elem*3;
}

template <typename Data>
void MoltiplicateInt(const Data& dat, const void* par, void *acc) {
    if (dat < *(Data*)par){
        *(Data*)acc *= dat;
    }
}

template <typename Data>
void SumFloatBiggerThan(const Data & dat, const void* par, void *acc) {
    if (dat > *(Data*)par){
        *(Data*)acc += dat;
    }
}


/**FUNS ESERCIZIO 4 **/

template <typename Data>
void MapFunIntEx4(Data & dat,void* par) {
    dat *= (pow(-1,dat));
}

template <typename Data>
void NegatifyData(Data & dat,void* par) {
    dat = dat*(-1);
}


