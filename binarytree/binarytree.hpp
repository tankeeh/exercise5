
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */
#include "../container/container.hpp"
#include "../queue/vec/queuevec.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public BreadthSearchableContainer<Data> {

private:

  // ...

protected:

  using BreadthSearchableContainer<Data>::size;

  // ...
  bool NodeEquality(const typename BinaryTree<Data>::Node& Node,const typename BinaryTree<Data>::Node& Node2)const;

public:

    struct Node{

    private:

    // ...

    protected:

        Data* val = nullptr;

    // ...

    public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element
    virtual const Data& Element() const noexcept = 0; // Immutable access to the element

    virtual bool IsLeaf() const noexcept = 0;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0 ;

    virtual Node& LeftChild() = 0; // (might throw std::out_of_range)
    virtual Node& RightChild() = 0; // (might throw std::out_of_range)

        //di seguito i metodi con il const per il corretto utilizzo di Element()
        virtual const Node& LeftChild() const = 0; // (might throw std::out_of_range)
        virtual const  Node& RightChild() const = 0; // (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  Node* TreeNode = nullptr;

  // Destructor
  ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree& tree) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree& tree) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Node& Root()  = 0; // (might throw std::length_error)
  virtual const Node& Root() const = 0; // (might throw std::length_error)

  //i due metodi successivi possono ragionevolemnte, qualora già esistesse la radice dell'albero,
  //pulire l' albero precedente e assegnarre la nuova radice passata come parametro;

  virtual void NewRoot(const Data&)noexcept = 0 ; // Copy of the value
  virtual void NewRoot(Data&&) noexcept = 0;// Move of the value

  using typename SearchableContainer<Data>::MapFunctor;
  void MapInOrder(MapFunctor functor, void *par);

  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldInOrder(FoldFunctor functor,const void *par,void* acc)const;

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  void MapPreOrder(MapFunctor functor, void *par) override; // Override SearchableContainer member
  void MapPostOrder(MapFunctor functor, void *par) override ;// Override SearchableContainer member

  void FoldPreOrder(FoldFunctor functor, const void *par, void *acc)const override; // Override SearchableContainer member
  void FoldPostOrder(FoldFunctor functor, const void *par, void *acc)const override;// Override SearchableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  void MapBreadth(MapFunctor functor, void *par) override; // Override BreadthSearchableContainer member

  void FoldBreadth(FoldFunctor functor,const void *par,void* acc)const override;// Override BreadthSearchableContainer member


protected:

  void MapBreadth(MapFunctor functor, void *par,Node* node); // Accessory function executing from one node of the tree
  void MapPreOrder(MapFunctor functor, void *par,Node* node); // Accessory function executing from one node of the tree
  void MapInOrder(MapFunctor functor, void *par,Node* node); // Accessory function executing from one node of the tree
  void MapPostOrder(MapFunctor functor, void *par,Node* node);  // Accessory function executing from one node of the tree

  void FoldBreadth(FoldFunctor functor,const void *par,void* acc,const Node* node)const; // Accessory function executing from one node of the tree
  void FoldPreOrder(FoldFunctor functor,const void *par,void* acc,const Node* node)const;  // Accessory function executing from one node of the tree
  void FoldInOrder(FoldFunctor functor,const void *par,void* acc,const Node* node)const; // Accessory function executing from one node of the tree
  void FoldPostOrder(FoldFunctor functor,const void *par,void* acc,const Node* node)const;// Accessory function executing from one node of the tree

};

/* ************************************************************************** */

#include "binarytree.cpp"

}

#endif
