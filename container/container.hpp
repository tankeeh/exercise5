
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <functional>
#include <cmath>
namespace lasd {

/* ************************************************************************** */

    class Container {

    private:

        // ...

    protected:

        unsigned int size = 0;
        // ...

    public:


        // Destructor
        virtual ~Container() = default;

        /* ************************************************************************ */

        // Copy assignment
        Container &operator=(const Container &) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        Container &
        operator=(const Container &&) noexcept = delete;  // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators

        // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
        bool operator==(const Container &) const noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
        bool operator!=(const Container &) const noexcept = delete;
        /* ************************************************************************ */

        // Specific member functions

        // type Empty() specifiers;
        virtual bool Empty() const noexcept;

        // type Size() specifiers;
        virtual int Size() const noexcept;

        // type Clear() specifiers;
        virtual void Clear() = 0;
    };

/* ************************************************************************** */

    template<typename Data>
    class LinearContainer : virtual public Container {

    private:

    protected:
        using Container::size;
    public:

        // Destructor
        virtual ~LinearContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        LinearContainer &
        operator=(const LinearContainer &) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        LinearContainer &operator=(const LinearContainer &&) noexcept = delete;
        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const LinearContainer &) const noexcept = delete;

        bool operator!=(const LinearContainer &) const noexcept = delete;


        /* ************************************************************************ */

        // Specific member functions

        virtual Data Front() const = 0;

        virtual Data Back() const = 0;

        virtual Data &operator[](const unsigned int)const = 0;
    };

/* ************************************************************************** */

    template<typename Data>
    class TestableContainer : virtual public Container {

    private:

    protected:

    public:

        // Destructor
        virtual ~TestableContainer() = default;

        /* ************************************************************************ */

        TestableContainer &
        operator=(const TestableContainer &) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        TestableContainer &operator=(const TestableContainer &&) noexcept = delete;  // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const TestableContainer &) const noexcept = delete;

        // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
        bool operator!=(const TestableContainer &) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member functions

        virtual bool Exists(const Data &) const noexcept = 0;

    };

/* ************************************************************************** */

    template<typename Data>
    class SearchableContainer : virtual public TestableContainer<Data> {

    private:

    protected:

    public:

        // Destructor
        virtual ~SearchableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        SearchableContainer &operator=(const SearchableContainer &) = delete;

        // Move assignment
        SearchableContainer &operator=(const SearchableContainer &&) noexcept = delete;


        /* ************************************************************************ */

        // Comparison operators
        bool operator==(SearchableContainer &) const noexcept = delete;

        bool operator!=(SearchableContainer &) const noexcept = delete;


        /* ************************************************************************ */

        // Specific member functions


        typedef std::function<void(Data &, void *)> MapFunctor;

        virtual void MapPreOrder(MapFunctor functor, void *par) = 0;

        virtual void MapPostOrder(MapFunctor functor, void *par) = 0;



        typedef std::function<void(const Data &, const void *par, void *acc) noexcept> FoldFunctor;

        virtual void FoldPreOrder(FoldFunctor functor, const void *par, void *acc) const = 0;
        virtual void FoldPostOrder(FoldFunctor functor, const void *par, void *acc) const = 0;
        virtual bool Exists(const Data &) const noexcept override;

    };

    /* ************************************************************************************* */

    template <typename Data>
    class BreadthSearchableContainer : virtual public SearchableContainer<Data>{

    private:

    protected:

        //unsigned int size = 0;

    public:

        // Destructor
        ~BreadthSearchableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        BreadthSearchableContainer& operator=(BreadthSearchableContainer&) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        BreadthSearchableContainer& operator=(BreadthSearchableContainer&&) = delete; // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(BreadthSearchableContainer&)const noexcept = delete;  // Comparison of abstract types might not be possible.
        bool operator!=(BreadthSearchableContainer&)const noexcept  = delete;  // Comparison of abstract types might not be possible.

        /* ************************************************************************ */

        // Specific member functions

        using typename SearchableContainer<Data>::MapFunctor;
        virtual void MapBreadth(MapFunctor functor, void *par) = 0;

        using typename SearchableContainer<Data>::FoldFunctor;
        virtual void FoldBreadth(FoldFunctor functor,const void *par,void* acc)const = 0;

    };

#include "container.cpp"

}

#endif
