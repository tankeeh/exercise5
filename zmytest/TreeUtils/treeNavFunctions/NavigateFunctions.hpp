//
// Created by Antonio on 10/05/2020.
//

#ifndef EXERCISE2_NAVIGATEFUNCTIONS_HPP
#define EXERCISE2_NAVIGATEFUNCTIONS_HPP

#include "../../../binarytree/lnk/binarytreelnk.hpp"

template <typename Data>
void intTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree);
template <typename Data>
void floatTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree);

template <typename Data>
void stringTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree);
/*
template <typename Data>
void intTreeVecNavigation(lasd::BinaryTreeVec<Data>* tree);

template <typename Data>
void floatTreeVecNavigation(lasd::BinaryTreeVec<Data>* tree);

template <typename Data>
void stringTreeVecNavigation(lasd::BinaryTreeVec<Data>* tree);
*/
#include "NavigateFunctions.cpp"
#endif //EXERCISE2_NAVIGATEFUNCTIONS_HPP

