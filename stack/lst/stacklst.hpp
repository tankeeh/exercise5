
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class StackLst : virtual public Stack<Data>,protected List<Data>{

    private:

        // ...

    protected:
        
        using List<Data>::size;
        using List<Data>::node;
        // ...

    public:

        // Default constructor
        StackLst() = default;

        // Copy constructor
        StackLst( const StackLst& stack);

        // Move constructor
        StackLst(StackLst&& stack);

        // StackLst(argument);

        /* ************************************************************************ */

        // Destructor
        ~StackLst() = default;

        /* ************************************************************************ */

        // Copy assignment
        StackLst &operator=(const StackLst& stack);


        // Move assignment
        StackLst &operator=(StackLst&& stack);

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const StackLst& stack)const;
        bool operator!=(const StackLst& stack)const;


        /* ************************************************************************ */

        // Specific member functions (inherited from Stack)

        Data Top() const override ; // Override Stack member (might throw std::length_error)
        void Pop() override ; // Override Stack member (might throw std::length_error)
        Data TopNPop() override ; // Override Stack member (might throw std::length_error)
        void Push(const Data& item) noexcept override; // Override Stack member
        void Push(Data&& item) noexcept override; // Override Stack member

        /* ************************************************************************ */

        // Specific member functions (inherited from Container)

        using Container::Empty;

        using Container::Size;

        using List<Data>::Clear;

    };

/* ************************************************************************** */

#include "stacklst.cpp"

}

#endif
