
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data>{ // Should extend BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;

  // ...

public:

  struct BSTNode { // Should extend NodeLnk

  private:

    // ...

  protected:

    // type Left() specifiers; // Mutable access to the element
    // type Left() specifiers; // Immutable access to the element
    // type Right() specifiers; // Mutable access to the element
    // type Right() specifiers; // Immutable access to the element

    // type Find(argument) specifiers;
    // type FindParent(argument) specifiers;

    // type MinParent() specifiers;
    // type MaxParent() specifiers;

    // type PredecessorParent(argument) specifiers;
    // type SuccessorParent(argument) specifiers;

    // ...

  public:

    // friend class BST<Data>;

    // ...

  };

  /* ************************************************************************ */

  // Default constructor
  // BST() specifiers;

  // Copy constructor
  // BST(argument) specifiers;

  // Move constructor
  // BST(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (might throw std::length_error)
  // type NewRoot(argument) specifiers; // Override BinaryTree member (Copy of the value)
  // type NewRoot(argument) specifiers; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  // type Insert(argument) specifiers; // Move of the value
  // type Remove(argument) specifiers;

  // type Min() specifiers; // (might throw std::length_error)
  // type MinNRemove() specifiers; // (might throw std::length_error)
  // type RemoveMin() specifiers; // (might throw std::length_error)

  // type Max() specifiers; // (might throw std::length_error)
  // type MaxNRemove() specifiers; // (might throw std::length_error)
  // type RemoveMax() specifiers; // (might throw std::length_error)

  // type Predecessor(argument) specifiers; // (might throw std::length_error)
  // type PredecessorNRemove(argument) specifiers; // (might throw std::length_error)
  // type RemovePredecessor(argument) specifiers; // (might throw std::length_error)

  // type Successor(argument) specifiers; // (might throw std::length_error)
  // type SuccessorNRemove(argument) specifiers; // (might throw std::length_error)
  // type RemoveSuccessor(argument) specifiers; // (might throw std::length_error)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

protected:

  // type Remove(argument) specifiers;
  // type RemoveMin(argument) specifiers;
  // type RemoveMax(argument) specifiers;
  // type SkipOnLeft(argument) specifiers;
  // type SkipOnRight(argument) specifiers;

};

}

/* ************************************************************************** */

#include "bst.cpp"

/* ************************************************************************** */

#endif
