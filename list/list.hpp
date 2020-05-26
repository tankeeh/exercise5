
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */
#include <stdexcept>
#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public LinearContainer<Data>, virtual public SearchableContainer<Data> {

private:

  // ...

protected:

    using LinearContainer<Data>::size;

    struct Node {

    Data elem = Data();
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors


    Node() = default;
    // ...

    // Copy constructor con Node
    Node(const Data& item);

    // Copy constructor con Node
    Node(const Node &);

    // Move constructor che prende Data
    Node(Data &&);

    // Move constructor che prende Node
    Node(Node &&);


      /* ********************************************************************** */

    // Destructor
    ~Node()noexcept = default ;
    // ...

    /* ********************************************************************** */

    // Comparison operators

    bool operator==(const Node& node)const noexcept;

    bool operator!=(const Node& node)const noexcept;

    /* ********************************************************************** */

    // Specific member functions


  };

    Node* node = nullptr;
    Node* tail = nullptr;

  // ...

public:

  // Default constructor
   List() = default;

  // Copy constructor
   List(const List& list);

  // Move constructor
   List(List&& list);

  /* ************************************************************************ */

  // Destructor
  ~List() noexcept;


  /* ************************************************************************ */

  // Copy assignment
  List &operator=(const List& list);

  // Move assignment
  List &operator=(List&& list);


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List& list) const noexcept;
  bool operator!=(const List& list) const noexcept;

  /* ************************************************************************ */


  // type RemoveFromFront() specifier;
  void RemoveFromFront();
  Data FrontNRemove();

  // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(const Data& item);
  // type InsertAtFront(argument) specifier; // Move of the value
  void InsertAtFront(Data&& item);


  void InsertAtBack(const Data& item) ; // Copy of the value
  void InsertAtBack(Data&& item) ; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    void Clear() override;   // Override Container member

    /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data Front()const  override ; // Override LinearContainer member
  Data Back()const override ; // Override LinearContainer member

  Data& operator[](const unsigned int position)const override ; // Override LinearContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>::MapFunctor;
  void MapPreOrder(MapFunctor functor, void *par); // Override SearchableContainer member
  void MapPostOrder(MapFunctor functor, void *par); // Override SearchableContainer member


  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldPreOrder(FoldFunctor functor, const void *par, void *acc) const override ; //Override SearchableContainer member
  void FoldPostOrder(FoldFunctor functor, const void *par, void *acc) const override ; //Override SearchableContainer member

  using SearchableContainer<Data>::Exists;



protected:



  void MapPreOrder(MapFunctor functor, void *par,Node* temp); // Accessory function executing from one point of the list onwards
  void MapPostOrder(MapFunctor functor, void *par,Node* temp);  // Accessory function executing from one point of the list onwards

  void FoldPreOrder(FoldFunctor functor,const void *par,void* acc,Node* temp)const; // Accessory function executing from one point of the list onwards
  void FoldPostOrder(FoldFunctor functor,const void *par,void* acc,Node* temp)const;  // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

#include "list.cpp"

}

#endif
