//
// Created by Antonio on 09/05/2020.
//

#ifndef EXERCISE2_COMMONS_HPP
#define EXERCISE2_COMMONS_HPP
#include <algorithm>
#include <iostream>

template <typename Data>
void Sum(const Data & dat, const void* par, void *acc);

template <typename Data>
void MoltiplicateFloat(const Data & dat, const void* par, void *acc);

template <typename Data>
void StringConcat(const Data & dat, const void* par, void *acc);

template <typename Data>
void UpperCase(Data& elem, void* par);

template <typename Data>
void SquaredFloat(Data& elem, void* par);

template <typename Data>
void DuplicateInt(Data& elem, void*);

template <typename Data>
void TriplicateInt(Data& elem, void*);

template <typename Data>
void CubedFloat(Data& elem, void* par);

template <typename Data>
void InitialConcatString(Data& elem, void* par);

template <typename Data>
void MapFunIntEx4(Data & dat,void* par);

template <typename Data>
void NegatifyData(Data & dat,void* par);

template <typename Data>
void MoltiplicateInt(const Data& dat, const void* par, void *acc);

template <typename Data>
void SumFloatBiggerThan(const Data & dat, const void* par, void *acc);



#include "./commons.cpp"
#endif //EXERCISE2_COMMONS_HPP
