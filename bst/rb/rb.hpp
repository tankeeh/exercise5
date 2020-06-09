
#ifndef RB_HPP
#define RB_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class RB : public BST<Data>{ // Should extend BST<Data>

private:

  // ...

protected:

    enum Colori{Red,Black,DeepBlack};
  // using BST<Data>::???;

  // ...

public:

struct RBNode : protected BST<Data>::BSTNode{ // Should extend BSTNode

protected:
    RBNode() = default;
    RBNode(const Data&);
    RBNode(Data&& );

    Colori color = 0;

public:
    friend class RB<Data>;

  };

  /* ************************************************************************ */

  // Default constructor
  RB() = default;

  // Copy constructor
  RB(const RB&) ;

  // Move constructor
  RB(RB&&) ;

  /* ************************************************************************ */

  // Destructor
  ~RB() = default;

  /* ************************************************************************ */

  // Copy assignment
  RB& operator=(const RB& tree);

  // Move assignment
  RB& operator=(RB && tree) ;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const RB&) const noexcept ;
  bool operator!=(const RB&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  RBNode& Root() override ; // Override BinaryTree member (might throw std::length_error)
  void NewRoot(const Data& key) override ; // Override BinaryTree member (Copy of the value)
  void NewRoot(Data&& key) override ;  // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data& key) override; // Copy of the value
  void Insert(Data&& key) override;  // Move of the value
  void Remove(const Data& key) override;

  Data MinNRemove() override; // (might throw std::length_error)
  void RemoveMin() override; // (might throw std::length_error)

  Data MaxNRemove() override; // (might throw std::length_error)
  void RemoveMax() override; // (might throw std::length_error)

  Data PredecessorNRemove(const Data& key) override; // (might throw std::length_error)
  void RemovePredecessor(const Data& key) override; // (might throw std::length_error)

  Data SuccessorNRemove(const Data& key) override; // (might throw std::length_error)
  void RemoveSuccessor(const Data& key) override; // (might throw std::length_error)

  /* ************************************************************************ */

};




}

/* ************************************************************************** */

#include "rb.cpp"

/* ************************************************************************** */

#endif
