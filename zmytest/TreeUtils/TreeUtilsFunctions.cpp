//
// Created by Antonio on 30/04/2020.
//


template <typename Data>
void PrintElementTreePreOrder(lasd::BinaryTree<Data>& tree){
tree.MapPreOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementTreeBreadth(lasd::BinaryTree<Data>& tree){
    tree.MapBreadth(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementTreeInOrder(lasd::BinaryTree<Data>& tree){
    tree.MapInOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementTreePostOrder(lasd::BinaryTree<Data>& tree){
    tree.MapPostOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementHeapPreOrder(lasd::BinaryTree<Data>& tree){
    tree.MapPreOrder(&PrintElement<Data>, nullptr);
}




template <typename Data>
void PrintElementHeapPostOrder(lasd::BinaryTree<Data>& tree){
    tree.MapPostOrder(&PrintElement<Data>, nullptr);
}


template <typename Data>
void TriplicateIntForBinaryTree(lasd::BinaryTree<Data>& tree){
    tree.MapPreOrder(&TriplicateInt<Data>, nullptr);
}

template <typename Data>
void CubedFloatForBinaryTree(lasd::BinaryTree<Data>& tree){
    tree.MapPreOrder(&CubedFloat<Data>, nullptr);
}

template <typename Data>
void InitialConcatStringForBinaryTree(lasd::BinaryTree<Data>& tree, void* par){
    tree.MapPreOrder(&InitialConcatString<Data>,par);
}


/*
template <typename Data>
void InitialConcatStringForBinaryTreeHeap(lasd::Heap<Data>& heap, void* par){
    heap.MapPreOrder(&InitialConcatString<Data>,par);
}


template <typename Data>
void ForBinaryTreeHeap(lasd::Heap<Data>& heap, void* par){
    heap.MapPreOrder(&InitialConcatString<Data>,par);
}

template <typename Data>
void FunIntEx4ForBinaryTreeHeap(lasd::Heap<Data>& heap){
    heap.MapPreOrder(&MapFunIntEx4<Data>, nullptr);
}

template <typename Data>
void NegatifyDataForBinaryTreeHeap(lasd::Heap<Data>& heap){
    heap.MapPreOrder(&NegatifyData<Data>, nullptr);
}


template <typename Data>
Data FoldTreeHeapIntMoltiplicateSmallerThan(const Data& par, lasd::Heap<Data> &heap){
    int acc = 1;
    heap.FoldPreOrder(&MoltiplicateInt<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldTreeHeapFloatSumBiggerThan(const Data& par, lasd::Heap<Data> &heap){
    float acc = 0;
    heap.FoldPreOrder(&SumFloatBiggerThan<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldTreeHeapStringConcatLowerEqualsThan(const int& par, lasd::Heap<Data> &heap){
    std::string acc = "";
    heap.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}
*/
template <typename Data>
Data FoldTreeIntMoltiplicateSmallerThan(const Data& par, lasd::BinaryTree<Data> &tree){
    int acc = 1;
    tree.FoldPreOrder(&MoltiplicateInt<Data>,&par,&acc);
    return acc;
}



template <typename Data>
Data FoldTreeStringConcatLowerEqualsThan(const int& par, lasd::BinaryTree<Data> &tree){
    std::string acc = "";
    tree.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldTreeFloatSumBiggerThan(const Data& par, lasd::BinaryTree<Data> &tree){
    float acc = 0;
    tree.FoldPreOrder(&SumFloatBiggerThan<Data>,&par,&acc);
    return acc;
}




