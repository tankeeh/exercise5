
#ifndef AVL_HPP
#define AVL_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class AVL : public BST<Data> { // Should extend BST<Data>

private:

  // ...

protected:

  // using BST<Data>::???;

  // ...

public:

struct AVLNode : protected BST<Data>::BSTNode { // Should extend BSTNode

      int height = 0;
    // ...

  };

  /* ************************************************************************ */

  // Default constructor
  AVL() = default;

  // Copy constructor
  AVL(const AVL& tree) ;

  // Move constructor
  AVL(AVL&& tree);

  /* ************************************************************************ */

  // Destructor
  ~AVL() = default;

  /* ************************************************************************ */

  // Copy assignment
  AVL& operator=(const AVL& tree);

  // Move assignment
  AVL& operator=(AVLE&& tree);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const AVL&) const noexcept ;
  bool operator!=(const AVL&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (might throw std::length_error)
  // type NewRoot(argument) specifiers; // Override BinaryTree member (Copy of the value)
  // type NewRoot(argument) specifiers; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data& key) noexcept ; // Copy of the value
  void Insert(Data&& key) noexcept ;  // Move of the value
  // type Remove(argument) specifiers;

  // type MinNRemove() specifiers; // (might throw std::length_error)
  // type RemoveMin() specifiers; // (might throw std::length_error)

  // type MaxNRemove() specifiers; // (might throw std::length_error)
  // type RemoveMax() specifiers; // (might throw std::length_error)

  // type PredecessorNRemove(argument) specifiers; // (might throw std::length_error)
  // type RemovePredecessor(argument) specifiers; // (might throw std::length_error)

  // type SuccessorNRemove(argument) specifiers; // (might throw std::length_error)
  // type RemoveSuccessor(argument) specifiers; // (might throw std::length_error)

  /* ************************************************************************ */

};

}

/* ************************************************************************** */

#include "avl.cpp"

/* ************************************************************************** */

#endif
