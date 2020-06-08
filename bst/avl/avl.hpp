
#ifndef AVL_HPP
#define AVL_HPP

/* ************************************************************************** */

#include "../bst.hpp"
#include<algorithm>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class AVL : public BST<Data>{

private:

  // ...

protected:

  // using BST<Data>::???;

  // ...

public:

struct AVLNode : public BST<Data>::BSTNode { // make public for test with beauty tree but has to be protected

protected:

    //using BinaryTreeLnk<Data>::NodeLnk::NodeLnk;

    AVLNode* Left(); // Mutable access to the element
    AVLNode const* Left() const; // Immutable access to the element
    AVLNode* Right(); // Mutable access to the element
    AVLNode const* Right() const; // Immutable access to the element

    AVLNode const* MaxParent() const override;

    int height = 0;
    // ...
public:
    AVLNode() = default;

    AVLNode(const Data& item); //COPY CONSTRUCTOR

    AVLNode(Data&& item); //MOVE CONSTRUCTOR

    AVLNode(AVLNode& node); //REC CONSTRUCTOR

    friend AVL<Data>;
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
  AVL& operator=(AVL&& tree);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const AVL&) const noexcept ;
  bool operator!=(const AVL&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const AVLNode& Root() const override; // Override BinaryTree member (might throw std::length_error)
  void NewRoot(const Data& key) noexcept override ; // Override BinaryTree member (Copy of the value)
  void NewRoot(Data&& key) noexcept override ; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data& key) override ; // Copy of the value
  void Insert(Data&& key) override ;  // Move of the value
  void Remove(const Data& key) noexcept override ;

  const Data MinNRemove() override ; // (might throw std::length_error)
  void RemoveMin() override ; // (might throw std::length_error)

  const Data MaxNRemove() override ; // (might throw std::length_error)
  void RemoveMax() override ; // (might throw std::length_error)

  Data PredecessorNRemove(const Data& key) override ; // (might throw std::length_error)
  void RemovePredecessor(const Data& key) override ; // (might throw std::length_error)

  Data SuccessorNRemove(const Data& key) override ; // (might throw std::length_error)
  void RemoveSuccessor(const Data& key) override ; // (might throw std::length_error)

  /* ************************************************************************ */


    AVLNode& Root();

protected:

    AVLNode* SxBalance(AVLNode* node);
    AVLNode* SxRotate(AVLNode* node);
    AVLNode* SxDoubleRotate(AVLNode* node);

    AVLNode* DxBalance(AVLNode* node);
    AVLNode* DxRotate(AVLNode* node);
    AVLNode* DxDoubleRotate(AVLNode* node);

    AVLNode* Remove(Data key,AVLNode*);
    AVLNode* RemoveNode(AVLNode*);
    AVLNode* StaccaMin(AVLNode* node,AVLNode* parent);
    AVLNode* StaccaMax(AVLNode *node,AVLNode* parent);

    AVLNode* Insert(Data key,AVLNode*);
    int Height(AVLNode* node);

    AVLNode*  AVLSubtreeMax(const AVLNode* node) const;
    AVLNode*  AVLSubtreeMin(const AVLNode* node) const;

    const AVLNode* PredecessorNode(const Data &key) const;

};



}

/* ************************************************************************** */

#include "avl.cpp"

/* ************************************************************************** */

#endif
