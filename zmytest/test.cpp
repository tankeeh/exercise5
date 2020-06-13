

#include <iostream>
#include "RandomGens/RandomValues.hpp"
#include "./TreeUtils/TreeUtilsFunctions.hpp"
#include "../bst/bst.hpp"
#include "../bst/avl/avl.hpp"
#include "../bst/rb/rb.hpp"


/*
template <typename Data>
void BeautyTree(typename lasd::AVL<Data>::AVLNode& node, int depth, const std::string& prefix){
    std::cout << std::string(depth*2, ' ') << ((depth > 0)? prefix : "ROOT") << ": [" << node.Element() << "]\n";
    if(node.HasLeftChild()) BeautyTree<Data>(*node.Left(), depth+1, prefix + "L");
    if(node.HasRightChild()) BeautyTree<Data>(*node.Right(), depth+1, prefix + "R");
}
*/



/** MY TESTS **/



void testBST() {
    lasd::BST<int> mBST;
    mBST.NewRoot(10);
    mBST.Insert(2);
    mBST.Insert(1);
    mBST.Insert(12);
    mBST.Insert(13);
    std::cout<< mBST.Predecessor(12);
/*
    lasd::BST<int> bstree;
    //h0
    bstree.Insert(1000);

    //h1
    bstree.Insert(500);
    bstree.Insert(1500);

    //h2
    bstree.Insert(250);
    bstree.Insert(750);
    bstree.Insert(1250);
    bstree.Insert(1750);

    //h3
    bstree.Insert(125);
    bstree.Insert(375);
    bstree.Insert(625);
    bstree.Insert(875);

    //h4
    bstree.Insert(1125);
    bstree.Insert(1375);
    bstree.Insert(1625);
    bstree.Insert(1875);

    //h5
    bstree.Insert(62);
    bstree.Insert(187);
    bstree.Insert(313);
    bstree.Insert(437);
    bstree.Insert(562);
    bstree.Insert(687);
    bstree.Insert(813);
    bstree.Insert(900);
    bstree.Insert(1100);
    bstree.Insert(1150);
    bstree.Insert(1313);
    bstree.Insert(1437);
    bstree.Insert(1563);
    bstree.Insert(1687);
    bstree.Insert(1813);
    bstree.Insert(1937);

    lasd::BST<int> tempbst(bstree);

    std::cout<<"MIN DI TEMP : "<<tempbst.Min();

    //int val;
    //std::cin>>val;

    //std::cout<<"il succ parent di "<<val<<" e' "<<bstree.Root().SuccessorParent(val)->Element();
    //bstree.Remove(1500);
    //bstree.Remove(62);
    //bstree.Remove(125);
    int elem;

    bstree.BeautyTree(bstree.Root(),0,"");
    while(elem!=-1){
       std::cout<<"Di quale elemento vuoi rimuovere il predecessore? \n";
       std::cin>>elem;
       try {
           std::cout << "il predecessore di " << elem << " e' " << bstree.PredecessorNRemove(elem) << "\n\n";
           bstree.BeautyTree(bstree.Root(),0,"");
       }
       catch(std::length_error err){ std::cout<<"\n\n"<<err.what()<<"\n\n";}
       }



    //std::cout<<bstree.Root().SuccessorParent(val);
    /*
    lasd::BST<int> bst;
    bst.NewRoot(30);
    bst.Insert(21);
    bst.Insert(21);
    bst.Insert(8);
    bst.Insert(3);
    bst.Insert(12);
    bst.Insert(6);
    bst.Insert(32);
    bst.Insert(42);
    bst.Insert(31);
    bst.Insert(60);
    bst.Insert(72);

    std::cout << "\n\n PRINT BST: \n\n";
    PrintElementTreeInOrder(bst);

    //std::cout<<"\n\n"<<bst.Exists(312);
    std::cout << "\n\n";

    lasd::BST<int> bst2;
    bst2.NewRoot(150);
    bst2.Insert(175);
    bst2.Insert(160);
    bst2.Insert(158);
    bst2.Insert(164);
    bst2.Insert(180);
    bst2.Insert(190);


    //std::cout<<"\n\n"<<(bst2.Root().FindParent(78))->Element()<<"\n\n";

    //PrintElementTreeInOrder(bst2);

    //bst2.Root().FindParent(40);
    //bst2.Remove(40);


    //std::cout << "L' elemento Max e' : " << bst2.MaxNRemove() << " ed e' stato eliminato.";



    //std::cout << "\n\n STAMPA POST ELIMINAZIONE : \n\n";
    //PrintElementTreeInOrder(bst2);

    //bst2.NewRoot(20);
    //bst2.Remove(20);
    //bst2.Remove(20);

    std::cout << "\n\n STAMPA POST ELIMINAZIONE 2: \n\n";
    PrintElementTreeInOrder(bst2);


    std::cout << "Inserire elemento di cui si vuole il prec :  ";
    int val;
    std::cin >> val;
    try {
        std::cout << "prec di " << val << " e' : " << bst2.Predecessor(val);
    } catch (std::length_error err) {
        std::cerr << err.what();
    }

    std::cout << "Inserire elemento di cui si vuole il succ :  ";
    std::cin >> val;
    try {
        std::cout << "succ di " << val << " e' : " << bst2.Successor(val);
    } catch (std::length_error err) {
        std::clog << err.what();
    }

    if (bst == bst2) std::cout << "\n\nsono uguali";
    else std::cout << "\n\n sono diversi";

    try {
        std::cout << "\n\nmax : " << bst2.Max();
    } catch (std::length_error err) {
        std::clog << err.what();
    }

    try {
        std::cout << "\n\nmin : " << bst2.Min();
    } catch (std::length_error err) {
        std::clog << err.what();
    }
     */
}
void testBSToperations() {
    lasd::BST<int> mBST;
    mBST.Insert(10);
    mBST.Insert(2);
    mBST.Insert(1);
    mBST.Insert(12);
    mBST.Insert(13);

    std::cout<<"stampa albero iniziale : \n";
    mBST.BeautyTree(mBST.Root(),0,"");

    std::cout<<"\n\n TEST COPY CONSTRUCTOR : \n";
    lasd::BST<int> bst2(mBST);
    bst2.BeautyTree(bst2.Root(),0,"");
    std::cout<<"\n\nSe è stato stampato un albero uquale a quello iniziale, ha funzionato\n\n";

    std::cout<<" TEST MOVE CONSTRUCTOR : \n";
    lasd::BST<int> bst3(std::move(mBST));
    bst3.BeautyTree(bst3.Root(),0,"");
    std::cout<<"\n\nSe è stato stampato un albero uquale a quello iniziale, ha funzionato\n\n";
    std::cout<<"Stampa dell' albero passato per move : (DEVE ESSERE VUOTO)\n";
    mBST.BeautyTree(mBST.Root(),0,"");

    std::cout<<" TEST COPY ASSIGNMENT : \n\n";
    lasd::BST<int> A;
    A.Insert(10);
    A.Insert(2);
    A.Insert(1);
    std::cout<<"stampa di A : \n";
    A.BeautyTree(A.Root(),0,"");

    lasd::BST<int> B;
    B.Insert(18);
    B.Insert(21);
    B.Insert(12);
    std::cout<<"stampa di B : \n";
    B.BeautyTree(A.Root(),0,"");

    A = B;
    std::cout<<"stampa di A POST ASSEGNAMENTO : \n";
    A.BeautyTree(A.Root(),0,"");
    std::cout<<"\n\nSe è stato stampato un albero uquale all' albero B, ha funzionato\n\n";

    B = std::move(A);
    std::cout<<"stampa di B POST ASSEGNAMENTO DI A PASSATO PER MOVE : \n";
    B.BeautyTree(B.Root(),0,"");
    std::cout<<"\n\nSe è stato stampato un albero uquale all' albero A, ha funzionato\n\n";
    std::cout<<"stampa di A PASSATO PER MOVE : \n";
    A.BeautyTree(A.Root(),0,"");

    lasd::BST<int> C;
    C.Insert(27);
    C.Insert(38);
    C.Insert(92);
    C.Insert(25);
    C.Insert(3);
    C.Insert(71);
    C.Insert(40);
    C.Insert(99);
    C.Insert(135);

    lasd::BST<int> D;
    D.Insert(47);
    D.Insert(38);
    D.Insert(92);
    D.Insert(75);
    D.Insert(3);
    D.Insert(71);
    D.Insert(40);
    D.Insert(99);
    D.Insert(135);

    if(C == D)std::cout<<"\nLe strutture sono uguali!\n";
    else std::cout<<"\nLe strutture sono diverse! (ed e' giusto in tal caso)\n";

    lasd::BST<int> E;
    E.Insert(47);
    E.Insert(38);
    E.Insert(92);
    E.Insert(75);
    E.Insert(3);
    E.Insert(71);
    E.Insert(40);
    E.Insert(99);
    E.Insert(135);

    if(E == D)std::cout<<"\nLe strutture sono uguali! (ed e' giusto in tal caso)\n";
    else std::cout<<"\nLe strutture sono diverse! \n";

    std::cout<<"La size di D e' : "<<D.Size()<<" e dovrebbe essere 9\n";

    D.Remove(47);
    D.Remove(38);

    std::cout<<"La size di D dopo due rimozioni e' : "<<D.Size()<<" e dovrebbe essere 7\n";
}


void testAVL(){

    lasd::AVL<int> avltree;
    //h0
    avltree.Insert(1000);

    //h1
    avltree.Insert(500);
    avltree.Insert(1500);

    //h2
    avltree.Insert(250);
    avltree.Insert(750);
    avltree.Insert(1250);
    avltree.Insert(1750);

    //h3
    avltree.Insert(125);
    avltree.Insert(375);
    avltree.Insert(625);
    avltree.Insert(875);

    //h4
    avltree.Insert(1125);
    avltree.Insert(1375);
    avltree.Insert(1625);
    avltree.Insert(1875);

    //h5
    avltree.Insert(62);
    avltree.Insert(187);
    avltree.Insert(313);
    avltree.Insert(437);
    avltree.Insert(562);
    avltree.Insert(687);
    avltree.Insert(813);
    avltree.Insert(900);
    avltree.Insert(1100);
    avltree.Insert(1150);
    avltree.Insert(1313);
    avltree.Insert(1437);
    avltree.Insert(1563);
    avltree.Insert(1687);
    avltree.Insert(1813);
    avltree.Insert(1937);


    avltree.BeautyTree(avltree.Root(),0,"");
    //int val;
    //std::cin>>val;
    std::cout<<"\n\n";

    int elem;
    while(elem!=-1){
        std::cout<<"Di quale elemento vuoi rimuovere il predecessore? \n";
        std::cin>>elem;
        try {
            std::cout << "il predecessore di " << elem << " e' ";
            std::cout<< avltree.PredecessorNRemove(elem) << "\n\n";
            avltree.BeautyTree(avltree.Root(),0,"");
        }
        catch(std::length_error err){ std::clog<<"\n\n"<<err.what()<<"\n\n";}
    }
    //std::cout<<"il succ parent di "<<val<<" e' "<<bstree.Root().SuccessorParent(val)->Element();
    //avltree.Remove(187);
    //avltree.Remove(62);
    //avltree.Remove(125);
/*
    lasd::AVL<int> avltree2;
    //h0
    avltree2.Insert(1000);

    //h1
    avltree2.Insert(500);
    avltree2.Insert(1500);

    //h2
    avltree2.Insert(250);
    avltree2.Insert(750);
    avltree2.Insert(1250);
    avltree2.Insert(1750);

    //h3
    avltree2.Insert(125);
    avltree2.Insert(375);
    avltree2.Insert(625);
    avltree2.Insert(875);

    //h4
    avltree2.Insert(1125);
    avltree2.Insert(1375);
    avltree2.Insert(1625);
    avltree2.Insert(1875);

    //h5
    avltree2.Insert(62);
    avltree2.Insert(187);
    avltree2.Insert(313);
    avltree2.Insert(437);
    avltree2.Insert(562);
    avltree2.Insert(687);
    avltree2.Insert(813);
    avltree2.Insert(900);
    avltree2.Insert(1100);
    avltree2.Insert(1150);
    avltree2.Insert(1313);
    avltree2.Insert(1437);
    avltree2.Insert(1563);
    avltree2.Insert(1687);
    avltree2.Insert(1813);
    avltree2.Insert(1937);


    avltree2.BeautyTree(avltree2.Root(),0,"");
    //int val;
    //std::cin>>val;
    std::cout<<"\n\n";

    //std::cout<<"il succ parent di "<<val<<" e' "<<bstree.Root().SuccessorParent(val)->Element();
    avltree2.Remove(187);
    avltree2.Remove(62);

    //PrintElementTreeInOrder(avltree);
    std::cout<<"\n\n";
    avltree.BeautyTree(avltree.Root(),0,"");

    if(avltree2 == avltree)std::cout<<"\n uguali";
    else std::cout<<"\ndiversi";
    /*
    std::cout<<"AVL"<<std::endl;
    lasd::AVL<int> myAvl;
    int i = 0;
    while (myAvl.Size() != 3) {
        myAvl.Insert(10 - i);
        i++;
    }
   // myAvl.BeautyTree(myAvl.Root(), 0,"");

    int n = 10;

        int i = 0;
        lasd::AVL<int> avl;

        while(i < n) {
            avl.Insert(n-i);
            i++;
        }

/*
    avl.NewRoot(30);

    lasd::AVL<int> avl2;
    avl2.Insert(50);
    avl2.Insert(59);

    avl = avl2;
    */

        //avl.Remove(1);
        //avl.Remove(29);



        //avl.BeautyTree(avl.Root(),0,"");
        /*
        avl.Insert(50);
        avl.Insert(59);
        avl.Insert(40);
        avl.Insert(38);
        avl.Insert(50);
        avl.Insert(59);
        avl.Insert(40);
        avl.Insert(38);
        PrintElementTreePreOrder(avl);

        avl.Insert(35);
        std::cout<<"\n\n";
         */
        //PrintElementTreePreOrder(avl);

        //std::cout<<" il min e' : "<<avl.MinNRemove()<<"\n\n";
        /*
        avl.RemoveMin();
        std::cout<<"\n\n";
        //PrintElementTreePreOrder(avl);
    avl.BeautyTree(avl.Root(),0,"");

        //avl.RemoveMax();
    std::cout<<"\n\n";

    avl.BeautyTree(avl.Root(),0,"");
    //std::cout<<" il max e' : "<<avl.MaxNRemove()<<"\n\n";
    avl.BeautyTree(avl.Root(),0,"");


    //PrintElementTreePreOrder(avl);

    std::cout<<"\n\n size : "<<avl.Size();


*/
}
void testAVLoperations(){


}


void testRB() {

    lasd::RB<int> myRB;
    myRB.Insert(33);
    myRB.Insert(22);
    myRB.Insert(44);
    myRB.Insert(11);
    myRB.Insert(31);
    myRB.Insert(35);
    myRB.Insert(66);
    myRB.Insert(10);
    myRB.Insert(29);
    myRB.Insert(32);
    myRB.Insert(34);
    myRB.Insert(38);
    myRB.Insert(55);
    myRB.Insert(77);
    myRB.Insert(26);
    myRB.Insert(30);
    myRB.Insert(36);
    myRB.Insert(39);
    myRB.Insert(50);
    myRB.Insert(88);
    std::cout<<"\n\n";
    myRB.RBCoolTree(myRB.Root(),0,""); std::cout<<"\n\n";



    /** remove part **/
    /*
    myRB.Remove(11);
    myRB.Remove(20);
    myRB.Remove(30);
    myRB.Remove(34);
    myRB.Remove(29);
    myRB.Remove(32);
    myRB.Remove(44);
    myRB.Remove(10);
    myRB.RBCoolTree(myRB.Root(),0,""); std::cout<<"\n\n";


    myRB.Remove(15);
    myRB.Remove(31);
    myRB.Remove(22);
    myRB.Remove(23);
    myRB.Remove(55);
    myRB.Remove(33);
    myRB.Remove(28);
    myRB.Remove(80);
    myRB.Remove(36);
    myRB.Remove(35);
    myRB.Remove(42);

    myRB.Remove(38);
    myRB.Remove(66);
    myRB.RBCoolTree(myRB.Root(),0,""); std::cout<<"\n\n";
    myRB.Remove(50);
    myRB.Remove(77);
    myRB.Remove(39);
    myRB.Remove(40);
    myRB.Remove(85);
    myRB.Remove(90);
    myRB.Remove(60);
    myRB.Remove(70);
    myRB.Remove(88);
    myRB.Remove(65);*/

    myRB.Remove(10);
    myRB.Remove(11);

    myRB.RBCoolTree(myRB.Root(),0,"");
    std::cout<<"\n size : "<<myRB.Size();

/*
    lasd::RB<int> myRB;
    //h0
    //rbtree.Insert(1000);

    //h1
    //rbtree.Insert(500);
    //rbtree.Insert(1500);

    //h2
    //rbtree.Insert(250);

    myRB.Insert(13);
    myRB.Insert(8);
    myRB.Insert(16);
    myRB.Insert(18);
    myRB.Insert(5);
    myRB.Insert(6);
    myRB.Insert(7);
    myRB.Insert(9);
    myRB.Insert(0);
    myRB.Insert(10);
    myRB.Insert(20);
    myRB.Insert(1);
    myRB.Insert(4);
    myRB.Insert(2);
    myRB.Insert(12);
    myRB.Insert(3);
    /*rbtree.Insert(750);
    rbtree.Insert(1250);
    rbtree.Insert(1750);

    //h3
    rbtree.Insert(125);
    rbtree.Insert(375);
    rbtree.Insert(625);
    rbtree.Insert(875);

    //h4
    rbtree.Insert(1125);
    rbtree.Insert(1375);
    rbtree.Insert(1625);
    rbtree.Insert(1875);

    //h5
    rbtree.Insert(62);
    rbtree.Insert(187);
    rbtree.Insert(313);
    rbtree.Insert(437);
    rbtree.Insert(562);
    rbtree.Insert(687);
    rbtree.Insert(813);
    rbtree.Insert(900);
    rbtree.Insert(1100);
    rbtree.Insert(1150);
    rbtree.Insert(1313);
    rbtree.Insert(1437);
    rbtree.Insert(1563);
    rbtree.Insert(1687);
    rbtree.Insert(1813);
    rbtree.Insert(1937);

    //int val;
    //std::cin>>val;

    //std::cout<<"il succ parent di "<<val<<" e' "<<bstree.Root().SuccessorParent(val)->Element();
    //bstree.Remove(1500);
    //bstree.Remove(62);
    //bstree.Remove(125);
    //int elem;
*/
    /*
    while(elem!=-1){
        std::cout<<"Di quale elemento vuoi rimuovere il predecessore? \n";
        std::cin>>elem;
        try {
            std::cout << "il predecessore di " << elem << " e' " << bstree.PredecessorNRemove(elem) << "\n\n";
            bstree.BeautyTree(bstree.Root(),0,"");
        }
        catch(std::length_error err){ std::cout<<"\n\n"<<err.what()<<"\n\n";}
    }
*/


    //std::cout<<bstree.Root().SuccessorParent(val);
    /*
    lasd::BST<int> bst;
    bst.NewRoot(30);
    bst.Insert(21);
    bst.Insert(21);
    bst.Insert(8);
    bst.Insert(3);
    bst.Insert(12);
    bst.Insert(6);
    bst.Insert(32);
    bst.Insert(42);
    bst.Insert(31);
    bst.Insert(60);
    bst.Insert(72);

    std::cout << "\n\n PRINT BST: \n\n";
    PrintElementTreeInOrder(bst);

    //std::cout<<"\n\n"<<bst.Exists(312);
    std::cout << "\n\n";

    lasd::BST<int> bst2;
    bst2.NewRoot(150);
    bst2.Insert(175);
    bst2.Insert(160);
    bst2.Insert(158);
    bst2.Insert(164);
    bst2.Insert(180);
    bst2.Insert(190);


    //std::cout<<"\n\n"<<(bst2.Root().FindParent(78))->Element()<<"\n\n";

    //PrintElementTreeInOrder(bst2);

    //bst2.Root().FindParent(40);
    //bst2.Remove(40);


    //std::cout << "L' elemento Max e' : " << bst2.MaxNRemove() << " ed e' stato eliminato.";



    //std::cout << "\n\n STAMPA POST ELIMINAZIONE : \n\n";
    //PrintElementTreeInOrder(bst2);

    //bst2.NewRoot(20);
    //bst2.Remove(20);
    //bst2.Remove(20);

    std::cout << "\n\n STAMPA POST ELIMINAZIONE 2: \n\n";
    PrintElementTreeInOrder(bst2);


    std::cout << "Inserire elemento di cui si vuole il prec :  ";
    int val;
    std::cin >> val;
    try {
        std::cout << "prec di " << val << " e' : " << bst2.Predecessor(val);
    } catch (std::length_error err) {
        std::cerr << err.what();
    }

    std::cout << "Inserire elemento di cui si vuole il succ :  ";
    std::cin >> val;
    try {
        std::cout << "succ di " << val << " e' : " << bst2.Successor(val);
    } catch (std::length_error err) {
        std::clog << err.what();
    }

    if (bst == bst2) std::cout << "\n\nsono uguali";
    else std::cout << "\n\n sono diversi";

    try {
        std::cout << "\n\nmax : " << bst2.Max();
    } catch (std::length_error err) {
        std::clog << err.what();
    }

    try {
        std::cout << "\n\nmin : " << bst2.Min();
    } catch (std::length_error err) {
        std::clog << err.what();
    }
     */
}
void testRBoperations() {

}








/**BinarySearchTree**/

void BinarySearchTreeString(){
    char scelta = '0';
    int n;

    lasd::BST<std::string> bst;
    std::cout << "Quanti elementi deve contenere il BST? : \n";
    std::cin>>n;
    while(bst.Size()<n)
        bst.Insert(CharValueGenerator());

    std::cout << "\n\n ** Generazione albero casuale BST ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BST di stringhe? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold TreeStringConcatLowerEqualsThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(bst);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(bst);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(bst);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(bst);
                break;
            case '5': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (bst.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '6':
                std::cout << " ** FOLD TreeStringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La concatenazione delle stringhe con lunghezza minore o uguale a "<<elem<<" e' : "<<FoldTreeStringConcatLowerEqualsThan(elem, bst);
                break;
            case '7': {
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno del BST: ";
                std::string d;
                std::cin >> d;
                bst.Insert(d);
                std::cout << "\nInserimento effettuato con successo!\n\n";
                break;
            }
            case '8': {
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dal BST: ";
                std::string r;
                std::cin >> r;
                bst.Remove(r);
                std::cout << "\nRimozione effettuata con successo!\n\n";
                break;
            }
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente BST e' : " << bst.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente BST e' : "<<bst.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    bst.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente BST e' : "<<bst.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente BST e' : "<<bst.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    bst.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del BST e' "<<bst.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del BST e' "<<bst.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    bst.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del BST e' "<<bst.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del BST e' "<<bst.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    bst.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinarySearchTreeFloat(){
    char scelta = '0';
    int n;

    lasd::BST<float> bst;
    std::cout << "Quanti elementi deve contenere il BST? : \n";
    std::cin>>n;
    while(bst.Size()<n)
        bst.Insert(FloatValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale BST ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BST di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold TreeFloatSumBiggerThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(bst);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(bst);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(bst);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(bst);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(bst.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD TreeFloatSumBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma degli elementi maggiori di "<<elem<<" e' :"<<FoldTreeFloatSumBiggerThan(elem, bst);
                break;
            case '7':
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno del BST: ";
                float d;
                std::cin >> d;
                bst.Insert(d);
                std::cout<<"\nInserimento effettuato con successo!\n\n";

                break;
            case '8':
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dal BST: ";
                float r;
                std::cin >> r;
                bst.Remove(r);
                std::cout<<"\nRimozione effettuata con successo!\n\n";

                break;
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente BST e' : " << bst.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente BST e' : "<<bst.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    bst.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente BST e' : "<<bst.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente BST e' : "<<bst.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    bst.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del BST e' "<<bst.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del BST e' "<<bst.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    bst.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del BST e' "<<bst.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del BST e' "<<bst.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    bst.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinarySearchTreeInt(){
    char scelta = '0';
    int n;

    lasd::BST<int> bst;
    std::cout << "Quanti elementi deve contenere il BST? : \n";
        std::cin>>n;
        while(bst.Size()<n)
            bst.Insert(IntValueGenerator());



        std::cout << "\n\n ** Generazione albero casuale BST ... ** \n\n";

        while (scelta != 'b') {
            std::cout << "\n\nCosa vuoi fare con il seguente BST di interi? : \n";
            std::cout << "1. MapPreOrder Print. \n";
            std::cout << "2. MapInOrder Print. \n";
            std::cout << "3. MapPostOrder Print. \n";
            std::cout << "4. MapBreadth Print. \n";
            std::cout << "5. Exists. \n";
            std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";

            std::cout << "7. Inserimento di un dato. \n";
            std::cout << "8. Rimozione di un dato. \n";

            std::cout << "q. Lettura del Minimo \n";
            std::cout << "w. Lettura e rimozione del Minimo \n";
            std::cout << "e. Rimozione del Minimo \n";

            std::cout << "r. Lettura del Massimo \n";
            std::cout << "t. Lettura e rimozione del Massimo \n";
            std::cout << "y. Rimozione del Massimo \n";

            std::cout << "u. Lettura del Predecessore di un dato elemento \n";
            std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
            std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

            std::cout << "p. Lettura del Successore di un dato elemento \n";
            std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
            std::cout << "s. Rimozione del Successore di un dato elemento \n";

            std::cout << "b. tornare indietro. \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** PREORDER PRINT ** \n\n";
                    PrintElementTreePreOrder(bst);
                    break;
                case '2':
                    std::cout << " ** INORDER PRINT ** \n\n";
                    PrintElementTreeInOrder(bst);
                    break;
                case '3':
                    std::cout << " ** POSTORDER PRINT ** \n\n";
                    PrintElementTreePostOrder(bst);
                    break;
                case '4':
                    std::cout << " ** BREADTH PRINT ** \n\n";
                    PrintElementTreeBreadth(bst);
                    break;
                case '5':
                    std::cout << " ** EXISTS ** \n\n";
                    std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                    int item;
                    std::cin >> item;
                    if(bst.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                    else std::cout<<"L'elemento e' assente nell' albero";
                    break;
                case '6':
                    std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                    std::cout << "Inserire il valore con cui chiamare la Fold : ";
                    int elem;
                    std::cin >> elem;
                    std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeIntMoltiplicateSmallerThan(elem, bst);
                    break;
                case '7':
                    std::cout << " ** INSERT ** \n\n";
                    std::cout << "Quale valore si intende inserire all' interno del BST: ";
                    int d;
                    std::cin >> d;
                    bst.Insert(d);
                    std::cout<<"\nInserimento effettuato con successo!\n\n";

                    break;
                case '8':
                    std::cout << " ** REMOVE ** \n\n";
                    std::cout << "Quale valore si intende rimuovere dal BST: ";
                    int r;
                    std::cin >> r;
                    bst.Remove(r);
                    std::cout<<"\nRimozione effettuata con successo!\n\n";

                    break;
                case 'q'://lettura
                    std::cout << " ** MIN ** \n\n";
                    try {
                        std::cout << "Il valore minimo del seguente BST e' : " << bst.Min();
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'w'://lettura con rimozione
                    std::cout << " ** MIN&REMOVE ** \n\n";
                    try{
                    std::cout << "Il valore minimo del seguente BST e' : "<<bst.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'e'://rimozione
                    std::cout << " ** REMOVE MIN ** \n\n";
                    try{
                    bst.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'r':
                    std::cout << " ** MAX ** \n\n";
                    try{
                    std::cout << "Il valore massimo del seguente BST e' : "<<bst.Max();
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 't':
                    std::cout << " ** MAX&REMOVE ** \n\n";
                    try{
                    std::cout << "Il valore massimo del seguente BST e' : "<<bst.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'y':
                    std::cout << " ** REMOVE MAX ** \n\n";
                    try{
                    bst.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'u':
                    std::cout << " ** PREDECESSOR ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                        int predeced_item;
                        std::cin>>predeced_item;
                        std::cout << "Il predecessore di "<<predeced_item<<" all' interno del BST e' "<<bst.Predecessor(predeced_item);
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'i':
                    std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                        int predeced_item;
                        std::cin>>predeced_item;
                        std::cout << "Il predecessore di "<<predeced_item<<" all' interno del BST e' "<<bst.PredecessorNRemove(predeced_item);
                        std::cout<<"\nPredecessore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}

                    break;
                case 'o':
                    std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                        int predeced_item;
                        std::cin>>predeced_item;
                        bst.RemovePredecessor(predeced_item);
                        std::cout<<"\nPredecessore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}

                    break;
                case 'p':
                    std::cout << " ** SUCCESSOR ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                        int succeeded_item;
                        std::cin>>succeeded_item;
                        std::cout << "Il successore di "<<succeeded_item<<" all' interno del BST e' "<<bst.Successor(succeeded_item);
                    }catch(std::length_error error){ std::clog<<error.what();}

                    break;
                case 'a':
                    std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                        int succeeded_item;
                        std::cin>>succeeded_item;
                        std::cout << "Il successore di "<<succeeded_item<<" all' interno del BST e' "<<bst.SuccessorNRemove(succeeded_item);
                        std::cout<<"\nSuccessore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}

                    break;
                case 's':
                    std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                        int succeeded_item;
                        std::cin>>succeeded_item;
                        bst.RemoveSuccessor(succeeded_item);
                        std::cout<<"\nSuccessore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;

                case 'b':
                    return;
                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }

            }
    }

void BinarySearchTree(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.BST di interi. \n";
        std::cout << "2.BST di float. \n";
        std::cout << "3.BST di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BST DI INTERI ** \n\n";
                BinarySearchTreeInt();
                break;
            case '2':
                std::cout << " ** BST DI FLOAT ** \n\n";
                BinarySearchTreeFloat();
                break;
            case '3':
                std::cout << " ** BST DI STRINGHE ** \n\n";
                BinarySearchTreeString();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}




/**AVL**/

//quando hai tempo inserisci coolTreePrintAVL tra le funzioni in modo da
//dare la possibilità di verificare

void AVLTreeString(){
    char scelta = '0';
    int n;

    lasd::AVL<std::string> avl;
    std::cout << "Quanti elementi deve contenere il seguente AVL? : \n";
    std::cin>>n;
    while(avl.Size()<n)
        avl.Insert(CharValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale AVL ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente AVL di stringhe? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold TreeStringConcatLowerEqualsThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(avl);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(avl);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(avl);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(avl);
                break;
            case '5': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (avl.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '6':
                std::cout << " ** FOLD TreeStringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeStringConcatLowerEqualsThan(elem, avl);
                break;
            case '7': {
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno dell' AVL: ";
                std::string d;
                std::cin >> d;
                avl.Insert(d);
                std::cout << "\nInserimento effettuato con successo!\n\n";
                break;
            }
            case '8': {
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dall' AVL: ";
                std::string r;
                std::cin >> r;
                avl.Remove(r);
                std::cout << "\nRimozione effettuata con successo!\n\n";

                break;
            }
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente AVL e' : " << avl.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente AVL e' : "<<avl.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    avl.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente AVL e' : "<<avl.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente AVL e' : "<<avl.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    avl.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del AVL e' "<<avl.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno dell' AVL e' "<<avl.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    avl.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno dell' AVL e' "<<avl.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del AVL e' "<<avl.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    avl.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void AVLTreeFloat(){
    char scelta = '0';
    int n;

    lasd::AVL<float> avl;
    std::cout << "Quanti elementi deve contenere il seguente AVL? : \n";
    std::cin>>n;
    while(avl.Size()<n)
        avl.Insert(FloatValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale AVL ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente AVL di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold TreeFloatSumBiggerThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(avl);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(avl);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(avl);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(avl);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(avl.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"\nL'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD TreeFloatSumBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma degli elementi maggiori di "<<elem<<" e' :"<<FoldTreeFloatSumBiggerThan(elem, avl);
                break;
            case '7':
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno dell' AVL: ";
                float d;
                std::cin >> d;
                avl.Insert(d);
                std::cout<<"\nInserimento effettuato con successo!\n\n";

                break;
            case '8':
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dall' AVL: ";
                float r;
                std::cin >> r;
                avl.Remove(r);
                std::cout<<"\nRimozione effettuata con successo!\n\n";

                break;
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente AVL e' : " << avl.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente AVL e' : "<<avl.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    avl.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente AVL e' : "<<avl.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente AVL e' : "<<avl.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    avl.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del AVL e' "<<avl.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno dell' AVL e' "<<avl.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    avl.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno dell' AVL e' "<<avl.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del AVL e' "<<avl.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    avl.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void AVLTreeInt(){
    char scelta = '0';
    int n;

    lasd::AVL<int> avl;
    std::cout << "Quanti elementi deve contenere il seguente AVL? : \n";
    std::cin>>n;
    while(avl.Size()<n)
        avl.Insert(IntValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale AVL ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente AVL di interi? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "c. TreeCoolPrint. (consigliata per verificare bilanciamenti delle strutture) \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(avl);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(avl);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(avl);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(avl);
                break;
            case 'c':
                std::cout << " ** TREE COOL PRINT ** \n\n";
                if(!avl.Empty())
                avl.BeautyTree(avl.Root(),0,"");
                else std::clog<<"Albero vuoto.\n\n";
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(avl.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeIntMoltiplicateSmallerThan(elem, avl);
                break;
            case '7':
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno dell' AVL: ";
                int d;
                std::cin >> d;
                avl.Insert(d);
                std::cout<<"\nInserimento effettuato con successo!\n\n";

                break;
            case '8':
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dall' AVL: ";
                int r;
                std::cin >> r;
                avl.Remove(r);
                std::cout<<"\nRimozione effettuata con successo!\n\n";

                break;
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente AVL e' : " << avl.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente AVL e' : "<<avl.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    avl.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente AVL e' : "<<avl.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente AVL e' : "<<avl.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    avl.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    int predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del AVL e' "<<avl.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    int predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno dell' AVL e' "<<avl.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    int predeced_item;
                    std::cin>>predeced_item;
                    avl.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    int succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno dell' AVL e' "<<avl.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    int succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del AVL e' "<<avl.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    int succeeded_item;
                    std::cin>>succeeded_item;
                    avl.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void AVLTree(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.AVL di interi. \n";
        std::cout << "2.AVL di float. \n";
        std::cout << "3.AVL di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** AVL DI INTERI ** \n\n";
                AVLTreeInt();
                break;
            case '2':
                std::cout << " ** AVL DI FLOAT ** \n\n";
                AVLTreeFloat();
                break;
            case '3':
                std::cout << " ** AVL DI STRINGHE ** \n\n";
                AVLTreeString();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}


/**RED&BLACK**/
//quando hai tempo inserisci coolTreePrintAVL tra le funzioni in modo da
//dare la possibilità di verificare

void RBTreeString(){
    char scelta = '0';
    int n;

    lasd::RB<std::string> rb;
    std::cout << "Quanti elementi deve contenere il R&B? : \n";
    std::cin>>n;
    while(rb.Size()<n)
        rb.Insert(CharValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale R&B ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente R&B di stringhe? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold TreeStringConcatLowerEqualsThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(rb);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(rb);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(rb);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(rb);
                break;
            case '5': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (rb.Exists(item))std::cout << "\nL'elemento e' presente nell' albero";
                else std::cout << "\nL'elemento e' assente nell' albero";
                break;
            }
            case '6':
                std::cout << " ** FOLD TreeStringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La concatenazione delle stringhe con lunghezza minore o uguale di "<<elem<<" e' :"<<FoldTreeStringConcatLowerEqualsThan(elem, rb);
                break;
            case '7': {
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno del R&B: ";
                std::string d;
                std::cin >> d;
                rb.Insert(d);
                std::cout << "\nInserimento effettuato con successo!\n\n";
                break;
            }
            case '8': {
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dal R&B: ";
                std::string r;
                std::cin >> r;
                rb.Remove(r);
                std::cout << "\nRimozione effettuata con successo!\n\n";
                break;
            }
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente R&B e' : " << rb.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente R&B e' : "<<rb.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    rb.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente R&B e' : "<<rb.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente R&B e' : "<<rb.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    rb.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del R&B e' "<<rb.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del R&B e' "<<rb.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    std::string predeced_item;
                    std::cin>>predeced_item;
                    rb.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del R&B e' "<<rb.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del R&B e' "<<rb.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    std::string succeeded_item;
                    std::cin>>succeeded_item;
                    rb.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void RBTreeFloat(){
    char scelta = '0';
    int n;

    lasd::RB<float> rb;
    std::cout << "Quanti elementi deve contenere il R&B? : \n";
    std::cin>>n;
    while(rb.Size()<n)
        rb.Insert(FloatValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale R&B ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente R&B di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold TreeFloatSumBiggerThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(rb);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(rb);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(rb);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(rb);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(rb.Exists(item))std::cout<<"\nL'elemento e' presente nell' albero";
                else std::cout<<"\nL'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma degli elementi maggiori di "<<elem<<" e' :"<<FoldTreeFloatSumBiggerThan(elem, rb);
                break;
            case '7':
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno del R&B: ";
                float d;
                std::cin >> d;
                rb.Insert(d);
                std::cout<<"\nInserimento effettuato con successo!\n\n";

                break;
            case '8':
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dal R&B: ";
                float r;
                std::cin >> r;
                rb.Remove(r);
                std::cout<<"\nRimozione effettuata con successo!\n\n";

                break;
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente R&B e' : " << rb.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente R&B e' : "<<rb.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    rb.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente R&B e' : "<<rb.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente R&B e' : "<<rb.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    rb.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del R&B e' "<<rb.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del R&B e' "<<rb.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    float predeced_item;
                    std::cin>>predeced_item;
                    rb.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del R&B e' "<<rb.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del R&B e' "<<rb.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    float succeeded_item;
                    std::cin>>succeeded_item;
                    rb.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void RBTreeInt(){
    char scelta = '0';
    int n;

    lasd::RB<int> rb;
    std::cout << "Quanti elementi deve contenere il R&B? : \n";
    std::cin>>n;
    while(rb.Size()<n)
        rb.Insert(IntValueGenerator());



    std::cout << "\n\n ** Generazione albero casuale R&B ... ** \n\n";

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente R&B di interi? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapInOrder Print. \n";
        std::cout << "3. MapPostOrder Print. \n";
        std::cout << "4. MapBreadth Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";

        std::cout << "7. Inserimento di un dato. \n";
        std::cout << "8. Rimozione di un dato. \n";

        std::cout << "q. Lettura del Minimo \n";
        std::cout << "w. Lettura e rimozione del Minimo \n";
        std::cout << "e. Rimozione del Minimo \n";

        std::cout << "r. Lettura del Massimo \n";
        std::cout << "t. Lettura e rimozione del Massimo \n";
        std::cout << "y. Rimozione del Massimo \n";

        std::cout << "u. Lettura del Predecessore di un dato elemento \n";
        std::cout << "i. Lettura e rimozione del Predecessore di un dato elemento \n";
        std::cout << "o. Rimozione del Predecessore di un dato elemento \n";

        std::cout << "p. Lettura del Successore di un dato elemento \n";
        std::cout << "a. Lettura e rimozione del Successore di un dato elemento \n";
        std::cout << "s. Rimozione del Successore di un dato elemento \n";

        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(rb);
                break;
            case '2':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(rb);
                break;
            case '3':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(rb);
                break;
            case '4':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(rb);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(rb.Exists(item))std::cout<<"\nL'elemento e' presente nell' albero";
                else std::cout<<"\nL'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeIntMoltiplicateSmallerThan(elem, rb);
                break;
            case '7':
                std::cout << " ** INSERT ** \n\n";
                std::cout << "Quale valore si intende inserire all' interno del R&B: ";
                int d;
                std::cin >> d;
                rb.Insert(d);
                std::cout<<"\nInserimento effettuato con successo!\n\n";

                break;
            case '8':
                std::cout << " ** REMOVE ** \n\n";
                std::cout << "Quale valore si intende rimuovere dal R&B: ";
                int r;
                std::cin >> r;
                rb.Remove(r);
                std::cout<<"\nRimozione effettuata con successo!\n\n";

                break;
            case 'q'://lettura
                std::cout << " ** MIN ** \n\n";
                try {
                    std::cout << "Il valore minimo del seguente R&B e' : " << rb.Min();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'w'://lettura con rimozione
                std::cout << " ** MIN&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore minimo del seguente R&B e' : "<<rb.MinNRemove();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'e'://rimozione
                std::cout << " ** REMOVE MIN ** \n\n";
                try{
                    rb.RemoveMin();
                    std::cout <<"\nElemento minimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'r':
                std::cout << " ** MAX ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente R&B e' : "<<rb.Max();
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 't':
                std::cout << " ** MAX&REMOVE ** \n\n";
                try{
                    std::cout << "Il valore massimo del seguente R&B e' : "<<rb.MaxNRemove();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'y':
                std::cout << " ** REMOVE MAX ** \n\n";
                try{
                    rb.RemoveMax();
                    std::cout <<"\nElemento massimo rimosso con successo!";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'u':
                std::cout << " ** PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il predecessore all' interno dell' albero : \n";
                    int predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del R&B e' "<<rb.Predecessor(predeced_item);
                }catch(std::length_error error){ std::clog<<error.what();}
                break;
            case 'i':
                std::cout << " ** PREDECESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    int predeced_item;
                    std::cin>>predeced_item;
                    std::cout << "Il predecessore di "<<predeced_item<<" all' interno del R&B e' "<<rb.PredecessorNRemove(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'o':
                std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                    int predeced_item;
                    std::cin>>predeced_item;
                    rb.RemovePredecessor(predeced_item);
                    std::cout<<"\nPredecessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'p':
                std::cout << " ** SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole trovare il successore all' interno dell' albero : \n";
                    int succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del R&B e' "<<rb.Successor(succeeded_item);
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 'a':
                std::cout << " ** SUCCESSOR & REMOVE ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    int succeeded_item;
                    std::cin>>succeeded_item;
                    std::cout << "Il successore di "<<succeeded_item<<" all' interno del R&B e' "<<rb.SuccessorNRemove(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}

                break;
            case 's':
                std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                try{
                    std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                    int succeeded_item;
                    std::cin>>succeeded_item;
                    rb.RemoveSuccessor(succeeded_item);
                    std::cout<<"\nSuccessore eliminato con successo!. \n";
                }catch(std::length_error error){ std::clog<<error.what();}
                break;

            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void RBTree(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.R&B di interi. \n";
        std::cout << "2.R&B di float. \n";
        std::cout << "3.R&B di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** R&B DI INTERI ** \n\n";
                RBTreeInt();
                break;
            case '2':
                std::cout << " ** R&B DI FLOAT ** \n\n";
                RBTreeFloat();
                break;
            case '3':
                std::cout << " ** R&B DI STRINGHE ** \n\n";
                RBTreeString();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}


void mytest() {

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per testare un BST. \n";
        std::cout << "2. per testare un AVL. \n";
        std::cout << "3. per testare un R&B. \n";


        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** TEST BST ** \n\n";
                BinarySearchTree();
                break;
            case '2':
                std::cout << " ** TEST AVL ** \n\n";
                AVLTree();
                break;
            case '3':
                std::cout << " ** TEST R&B ** \n\n";
                RBTree();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << "Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}








