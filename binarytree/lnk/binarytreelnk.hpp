
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: virtual public BinaryTree<Data> {

private:


protected:

  using BinaryTree<Data>::size;


public:


struct NodeLnk : public  BinaryTree<Data>::Node{

    private:

        // ...

    protected:

        Data* val = nullptr;
        NodeLnk* sx = nullptr;
        NodeLnk* dx = nullptr;

    public:

      NodeLnk() = default;

      NodeLnk(const Data& item); //COPY CONSTRUCTOR

      NodeLnk(Data&& item); //MOVE CONSTRUCTOR

      NodeLnk(NodeLnk& node); //RECURSIVE CONSTRUCTOR

      ~NodeLnk();



    friend class BinaryTreeLnk<Data>;

    /* ********************************************************************** */

    bool operator==(NodeLnk&) const noexcept ;
    bool operator!=(NodeLnk& node2) const noexcept;

    // Specific member functions (inherited from Node)

    const Data& Element() const noexcept override; // Override Node member Mutable access to the element
    Data& Element()noexcept override; // Override Node member Immutable access to the element

    bool IsLeaf() const noexcept override; // Override Node member
    bool HasLeftChild() const noexcept override; // Override Node member
    bool HasRightChild() const noexcept override; // Override Node member

    NodeLnk& LeftChild()  override; // Override Node member (might throw std::out_of_range)
    NodeLnk& RightChild()  override; // Override Node member (might throw std::out_of_range)

    //di seguito i metodi con il const per il corretto utilizzo di Element()
    const NodeLnk& LeftChild() const override; // Override Node member (might throw std::out_of_range)
    const NodeLnk& RightChild() const override; // Override Node member (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  NodeLnk* Node = nullptr;



  // Default constructor
  BinaryTreeLnk() = default;

  // Specific constructors
  BinaryTreeLnk(const Data& item) ; // Construct a tree with a given root data (Copy of the value)
  BinaryTreeLnk(Data&& item) ; // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept ;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk&operator=(const BinaryTreeLnk&) noexcept ;

  // Move assignment
  BinaryTreeLnk&operator=(BinaryTreeLnk&&) noexcept ;


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept ;

  bool operator!=(const BinaryTreeLnk&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeLnk& Root() override; // Override Node member (might throw std::length_error)
  const NodeLnk& Root() const override; // Override Node member (might throw std::length_error)

  void NewRoot(const Data&)noexcept override ; // Override Node member (Copy of the value)
  void NewRoot(Data&&) noexcept override ; // Override Node member (Move of the value)

  void AddLeftChild(NodeLnk& node,const Data& item); // Add a child to a given node (Copy of the value)
  void AddLeftChild(NodeLnk& node,Data&& item); // Add a child to a given node (Move of the value)
  void AddRightChild(NodeLnk& node,const Data& item); // Add a child to a given node (Copy of the value)
  void AddRightChild(NodeLnk& node,Data&& item); // Add a child to a given node (Move of the value)

  void RemoveLeftChild(NodeLnk& node) noexcept ; // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild(NodeLnk& node) noexcept ; // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override ; // Override Container member

  using SearchableContainer<Data>::Exists;

protected:

  // ...

};

/* ************************************************************************** */

#include "binarytreelnk.cpp"

}

#endif
