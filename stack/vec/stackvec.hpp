
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>,virtual protected Vector<Data> {

private:


protected:

  using Vector<Data>::size;
  using Vector<Data>::elem;
  unsigned int index = 0;
  // ...

public:

  // Default constructor
  StackVec();

  // Copy constructor
  StackVec(const StackVec& stack);


  // Move constructor
  StackVec(StackVec&& stack) noexcept;


    /* ************************************************************************ */

  // Destructor
  ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec &operator=(const StackVec& stack);


    // Move assignment
  StackVec &operator=(StackVec&& stack);


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec& stack)const;
  bool operator!=(const StackVec& stack)const;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

    Data Top() const override ; // Override Stack member (might throw std::length_error)
    void Pop() override ; // Override Stack member (might throw std::length_error)
    Data TopNPop() override ; // Override Stack member (might throw std::length_error)
    void Push(const Data& item)  override; // Override Stack member
    void Push(Data&& item) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty()const noexcept override ; // Override Container member

  int Size()const noexcept override ;// Override Container member

  void Clear() override; // Override Container member


  protected:

  void Expand(); // Accessory function
  void Reduce(); // Accessory function


};

/* ************************************************************************** */

#include "stackvec.cpp"

}

#endif
