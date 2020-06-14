
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../queue/lst//queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : public BinaryTreeLnk<Data>{

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;

  // ...

public:

struct BSTNode : protected BinaryTreeLnk<Data>::NodeLnk{ //make prot

private:

  protected:
    using BinaryTreeLnk<Data>::NodeLnk::NodeLnk;

     BSTNode* Left(); // Mutable access to the element
     BSTNode const* Left() const; // Immutable access to the element
     BSTNode* Right(); // Mutable access to the element
     BSTNode const* Right() const; // Immutable access to the element
     BSTNode const* Find(const Data&)const;
     BSTNode const* FindParent(const Data&) const;
     BSTNode* FindParent(const Data&);



    BSTNode const* MinParent() const;
    BSTNode* MinParent();

    virtual BSTNode const* MaxParent() const;
    BSTNode* MaxParent();

    BSTNode* PredecessorParent(const Data&) const;
    BSTNode* SuccessorParent(const Data&) const;

    //i constructor del nodo non sono presenti ma sono implicitamente richiamati quelli della superclasse "BinaryTreeLnk"
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

  virtual void Insert(const Data&); // Copy of the value
  virtual void Insert(Data&& );; // Move of the value
  virtual void Remove(const Data& del_item) noexcept ;

  const Data& Min() const; // (might throw std::length_error)
  virtual Data MinNRemove()  ; // (might throw std::length_error)
  virtual void RemoveMin(); // (might throw std::length_error)

  const Data& Max() const; // (might throw std::length_error)
  virtual Data MaxNRemove() ; // (might throw std::length_error)
  virtual void RemoveMax(); // (might throw std::length_error)

  const Data& Predecessor(const Data& key) const; // (might throw std::length_error)
  virtual Data PredecessorNRemove(const Data& key); // (might throw std::length_error)
  virtual void RemovePredecessor(const Data& key); // (might throw std::length_error)

  const Data& Successor(const Data& key) const; // (might throw std::length_error)
  virtual Data SuccessorNRemove(const Data& key); // (might throw std::length_error)
  virtual void RemoveSuccessor(const Data& key); // (might throw std::length_error)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override ; // Override TestableContainer member


    BSTNode& Root() override ; //make prot

protected:

  void Remove(BSTNode* node,BSTNode* father) noexcept ;
  void RemoveMin(BSTNode* node,BSTNode*); //questa funzione in realta' funge da "STACCAMIN"
  // type RemoveMax(argument) specifiers; //non implementata poichè non sarebbe stata utilizzata nelle mie implementazioni
  void SkipOnLeft(BSTNode* father,BSTNode* son);
  void SkipOnRight(BSTNode* father,BSTNode* son);


protected:

    const Data& SubtreeMin(const BSTNode* node) const;
    const Data& SubtreeMax(const BSTNode* node) const;

    void InOrderEnqueueNodes(QueueLst<Data>& queue,const BSTNode* node)const;
};



}

/* ************************************************************************** */

#include "bst.cpp"

/* ************************************************************************** */

#endif
