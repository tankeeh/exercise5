//
// Created by Antonio on 23/04/2020.
//

#ifndef EXERCISE2_UTILS_HPP
#define EXERCISE2_UTILS_HPP
#include "./commons/commons.hpp"
void DuplicateInt(Data& elem, void*);
template <typename Data>
void DuplicateIntVectorPreOrder(lasd::Vector<Data> &vettore);
template <typename Data>
void DuplicateIntListPreOrder(lasd::List<Data> &list);


template <typename Data>
void VectorPrintPreorder(lasd::Vector<Data> &vettore);

template <typename Data>
void VectorPrintPostorder(lasd::Vector<Data> &vettore);

template <typename Data>
void ListPrintPreOrder(lasd::List<Data> &list);

template <typename Data>
void  ListPrintPostOrder(lasd::List<Data> &list);

//FUNZIONE QUADRATO PER VETTORI E LISTE
template <typename Data>
void SquaredFloat(Data& elem, void* par);
template <typename Data>
void SquareFloatVectorPreOrder(lasd::Vector<Data> &vettore);
template <typename Data>
void SquareFloatListPreOrder(lasd::List<Data> &list);




//FUNZIONE DI UPPER CASE PER VETTORI E LISTE
template <typename Data>
void UpperCase(Data& elem, void* par);
template <typename Data>
void UppercaseVectorPreOrder(lasd::Vector<Data> &vettore);
template <typename Data>
void UppercaseListPreOrder(lasd::List<Data> &list);





/**FUNZIONI DI FOLD BY ME**/

//FOLD PER INTERI
template <typename Data>
void Sum(const Data & dat, const void* par, void *acc);
template <typename Data>
Data FoldIntVectorSumLowerThan(const Data par, lasd::Vector<Data> &vettore);
template <typename Data>
Data FoldIntListSumLowerThan(const Data par, lasd::List<Data> &list);



//FOLD PER FLOAT
template <typename Data>
void MoltiplicateFloat(const Data & dat, const void* par, void *acc);
template <typename Data>
Data FoldFloatVectorMoltiplicateBiggerThan(const Data par, lasd::Vector<Data> &vettore);
template <typename Data>
Data FoldFloatListMoltiplicateBiggerThan(const Data par, lasd::List<Data> &list);





//FOLD PER STRINGHE
template <typename Data>
void StringConcat(const Data & dat, const void* par, void *acc);


template <typename Data>
Data FoldStringVectorConcatLowerEquals(const int par, lasd::Vector<Data> &vettore);


template <typename Data>
Data FoldStringListConcatLowerEquals(const int par, lasd::List<Data> &list);



#include "Utils.cpp"
#endif //EXERCISE2_UTILS_HPP
