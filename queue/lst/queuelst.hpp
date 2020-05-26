
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */
#include <stdexcept>
#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: virtual public Queue<Data>, virtual protected List<Data>{

private:

  // ...

protected:

    using List<Data>::size;
    using List<Data>::node;

  // ...

public:

  // Default constructor
  QueueLst() = default;

  // Copy constructor
  QueueLst(const QueueLst& queue);

  // Move constructor
  QueueLst(QueueLst&& queue);

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator=(const QueueLst& queue);

  // Move assignment
  QueueLst& operator=(QueueLst&& queue);


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst& queue)const;
  bool operator!=(const QueueLst& queue)const;


  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

     Data Head() const override ; // (might throw std::length_error)
     void Dequeue() override; // (might throw std::length_error)
     Data HeadNDequeue() override; // (might throw std::length_error)
     void Enqueue(const Data& item) noexcept override; // Copy of the value
     void Enqueue(Data&& item) noexcept override;// Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    using Container::Empty;

    using Container::Size;
    /* ************** */
    using List<Data>::Clear;

};

/* ************************************************************************** */

#include "queuelst.cpp"

}

#endif
