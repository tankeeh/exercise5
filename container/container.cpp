


// Specific member functions (Container)

inline bool Container::Empty() const noexcept {
    return (size==0);
}

inline int Container::Size() const noexcept {
    return size;
}
// ...

/* ************************************************************************** */

// Specific member functions (LinearContainer)




// ...

/* ************************************************************************** */

// Specific member functions (TestableContainer)

// ...

/* ************************************************************************** */

// Specific member functions (SearchableContainer)
template <typename Data>
void FoldExists(const Data& dat, const void* value,void* exists){

    if(dat== *((Data*)value))
        *((bool*)exists) = true;
}

template <>
inline void FoldExists<double>(const double& dat, const void* value,void* exists){

    if (fabs(dat - *((double *)value))< 0.001)
        *((bool*)exists) = true;
}

template <typename Data>
bool lasd::SearchableContainer<Data>::Exists(const Data& dat)const noexcept {
    bool exists = false;
    FoldPreOrder(&FoldExists<Data>, &dat,&exists);
    return exists;
}



// ...
