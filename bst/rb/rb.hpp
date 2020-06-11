
#ifndef RB_HPP
#define RB_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */
    enum Colori{Red,Black,DeepBlack};

template <typename Data>
class RB : public BST<Data>{ // Should extend BST<Data>

private:

  // ...

protected:

  // using BST<Data>::???;

  // ...

public:

struct RBNode : protected BST<Data>::BSTNode{ // Should extend BSTNode

protected:

    RBNode* Left(); // Mutable access to the element
    RBNode const* Left() const; // Immutable access to the element
    RBNode* Right(); // Mutable access to the element
    RBNode const* Right() const; // Immutable access to the element

    RBNode() = default;

    RBNode(const Data& item);

    RBNode(Data&& item);

    RBNode(RBNode& node); //REC CONSTRUCTOR

    Colori color = Red;

public:
    friend class RB<Data>;
    using BinaryTreeLnk<Data>::NodeLnk::Element;
    using BinaryTreeLnk<Data>::NodeLnk::HasLeftChild;
    using BinaryTreeLnk<Data>::NodeLnk::HasRightChild;
    Colori getColor(){return this->color;};


  };

  /* ************************************************************************ */

  //static RBNode* NILNode;

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

  const RBNode& Root() const override ; // Override BinaryTree member (might throw std::length_error)
  void NewRoot(const Data& key) noexcept override ; // Override BinaryTree member (Copy of the value)
  void NewRoot(Data&& key) noexcept override ;  // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data& key) override; // Copy of the value
  void Insert(Data&& key) override;  // Move of the value
  void Remove(const Data& key) noexcept override;

  Data MinNRemove() override; // (might throw std::length_error)
  void RemoveMin() override; // (might throw std::length_error)

  Data MaxNRemove() override; // (might throw std::length_error)
  void RemoveMax() override; // (might throw std::length_error)

  Data PredecessorNRemove(const Data& key) override; // (might throw std::length_error)
  void RemovePredecessor(const Data& key) override; // (might throw std::length_error)

  Data SuccessorNRemove(const Data& key) override; // (might throw std::length_error)
  void RemoveSuccessor(const Data& key) override; // (might throw std::length_error)

  /* ************************************************************************ */

  void RBCoolTree(typename lasd::RB<Data>::RBNode& node, int depth, const std::string& prefix);

    RBNode& Root();

protected:

    /** INSERT SUPPORT FUNCTIONS **/
    int Vcase_sx(RBNode* sx,RBNode* dx);
    int Vcase_dx(RBNode* sx,RBNode* dx);


    RBNode* SxBalance_Case1(RBNode* node);
    RBNode* SxBalance_Case2(RBNode* node);
    RBNode* SxBalance_Case3(RBNode* node);

    RBNode* DxBalance_Case1(RBNode* node);
    RBNode* DxBalance_Case2(RBNode* node);
    RBNode* DxBalance_Case3(RBNode* node);


    RBNode* SxBalance(RBNode* node);
    RBNode* DxBalance(RBNode* node);


    RBNode* Insert(Data&& key,RBNode* node);


    /** REMOVE SUPPORT FUNCTIONS **/

    int Remove_Vcase_sx(RBNode* sx,RBNode* dx);
    int Remove_Vcase_dx(RBNode* sx,RBNode* dx);

    RBNode* Remove_SxBalance_Case1(RBNode* node);
    RBNode* Remove_SxBalance_Case2(RBNode* node);
    RBNode* Remove_SxBalance_Case3(RBNode* node);
    RBNode* Remove_SxBalance_Case4(RBNode* node);


    RBNode* Remove_DxBalance_Case1(RBNode* node);
    RBNode* Remove_DxBalance_Case2(RBNode* node);
    RBNode* Remove_DxBalance_Case3(RBNode* node);
    RBNode* Remove_DxBalance_Case4(RBNode* node);


    RBNode* Remove(RBNode* node,const Data& key);

    RBNode* RemoveNode(RBNode* node);

    void BlackPropagate(RBNode* node);

    RBNode* StaccaMin(RBNode* node,RBNode* parent);

    RBNode* Remove_SxBalance(RBNode* node);
    RBNode* Remove_DxBalance(RBNode* node);




    RBNode* SxRotate(RBNode* node);
    RBNode* DxRotate(RBNode* node);

    RBNode* DxDoubleRotate(RBNode* node);
    RBNode* SxDoubleRotate(RBNode* node);



};




}

/* ************************************************************************** */

#include "rb.cpp"

/* ************************************************************************** */

#endif
