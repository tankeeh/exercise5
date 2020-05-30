
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../queue/vec/queuevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data>{

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;

  // ...

public:

struct BSTNode : protected BinaryTreeLnk<Data>::NodeLnk {

  private:

    // ...

  protected:
    using BinaryTreeLnk<Data>::NodeLnk::NodeLnk;

    BSTNode* Left(); // Mutable access to the element
    BSTNode const* Left() const; // Immutable access to the element
    BSTNode* Right(); // Mutable access to the element
    BSTNode const* Right() const; // Immutable access to the element

    BSTNode const* Find(const Data&)const;
    BSTNode const* FindParent(const Data&) const;
    BSTNode* FindParent(const Data&);


    BSTNode* MinParent() const;
    BSTNode* MaxParent() const;

    BSTNode* PredecessorParent(const Data) const;
    BSTNode* SuccessorParent(const Data) const;

    // ...

  public:
      friend class BST<Data>;

    // ...

  };

  /* ************************************************************************ */

  // Default constructor
  BST() = default;

  // Copy constructor
  BST(const BST& tree);

  // Move constructor
  BST(BST&& tree);

  /* ************************************************************************ */

  // Destructor
  ~BST()= default;

  /* ************************************************************************ */

  // Copy assignment
  BST& operator=(const BST& tree);

  // Move assignment
  BST& operator=(BST&& tree);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST& ) const noexcept;
  bool operator!=(const BST& ) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const BSTNode& Root() const override ; // Override BinaryTree member (might throw std::length_error)
  void NewRoot(const Data&) noexcept override; // Override BinaryTree member (Copy of the value)
  void NewRoot(Data&&) noexcept override; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data&); // Copy of the value
  void Insert(Data&&);; // Move of the value
  void Remove(const Data& del_item) noexcept ;

  const Data& Min() const; // (might throw std::length_error)
  const Data& MinNRemove()  ; // (might throw std::length_error)
  void RemoveMin(); // (might throw std::length_error)

  const Data& Max() const; // (might throw std::length_error)
  const Data& MaxNRemove() ; // (might throw std::length_error)
  void RemoveMax(); // (might throw std::length_error)

  const Data& Predecessor(const Data&) const; // (might throw std::length_error)
  const Data& PredecessorNRemove(const Data&); // (might throw std::length_error)
  void RemovePredecessor(const Data&); // (might throw std::length_error)

  const Data& Successor(const Data&) const; // (might throw std::length_error)
  const Data& SuccessorNRemove(const Data&); // (might throw std::length_error)
  void RemoveSuccessor(const Data&); // (might throw std::length_error)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  //
  bool Exists(const Data&) const noexcept override ; // Override TestableContainer member

protected:

  //void Remove(const Data& del_item) noexcept ;
  //void RemoveMin(argument) specifiers;
  // type RemoveMax(argument) specifiers;
  // type SkipOnLeft(argument) specifiers;
  // type SkipOnRight(argument) specifiers;

  using BinaryTreeLnk<Data>::Node;

protected:
    void InOrderEnqueueNodes(QueueVec<Data>& queue,const BSTNode* node)const;
    BSTNode& Root() override ;
};



}

/* ************************************************************************** */

#include "bst.cpp"

/* ************************************************************************** */

#endif
