

#include <iostream>
#include "RandomGens/RandomValues.hpp"
#include "./TreeUtils/TreeUtilsFunctions.hpp"
//#include "./TreeUtils/treeNavFunctions/NavigateFunctions.hpp"
#include "../list/list.hpp"
#include "../bst/bst.hpp"





/** MY TESTS **/



void testBST(){
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

    std::cout<<"\n\n PRINT BST: \n\n";
    PrintElementTreeInOrder(bst);

    //std::cout<<"\n\n"<<bst.Exists(312);
    std::cout<<"\n\n";

    lasd::BST<int> bst2;
    bst2.NewRoot(30);
    bst2.Insert(21);
    bst2.Insert(8);
    bst2.Insert(7);
    //bst2.Insert(12);
    //bst2.Insert(15);
    bst2.Insert(6);
    bst2.Insert(32);
    bst2.Insert(42);
    bst2.Insert(31);
    bst2.Insert(60);
    bst2.Insert(72);
    bst2.Insert(78);

    //std::cout<<"\n\n"<<(bst2.Root().FindParent(78))->Element()<<"\n\n";

    PrintElementTreeInOrder(bst2);

    //bst2.Root().FindParent(40);
    //bst2.Remove(40);


        //std::cout << "L' elemento Max e' : " << bst2.MaxNRemove() << " ed e' stato eliminato.";



    std::cout<<"\n\n STAMPA POST ELIMINAZIONE : \n\n";
    PrintElementTreeInOrder(bst2);

    bst2.NewRoot(20);
    bst2.Remove(20);
    bst2.Remove(20);

    std::cout<<"\n\n STAMPA POST ELIMINAZIONE 2: \n\n";
    PrintElementTreeInOrder(bst2);


    std::cout<<"Inserire elemento di cui si vuole il prec :  ";
    int val;
    std::cin>>val;
    try {
        std::cout << "prec di " << val << " e' : " << bst2.Predecessor(val);
    }catch (std::length_error err) {
        std::cerr<<err.what();
    }

    std::cout<<"Inserire elemento di cui si vuole il succ :  ";
    std::cin>>val;
    try {
        std::cout << "succ di " << val << " e' : " << bst2.Successor(val);
    }catch (std::length_error err) {
        std::clog<<err.what();
    }

    if(bst == bst2) std::cout<<"\n\nsono uguali";
    else std::cout<<"\n\n sono diversi";

    try{
    std::cout<<"\n\nmax : "<<bst2.Max();
    }catch (std::length_error err) {
    std::clog<<err.what();
}

    try{
    std::cout<<"\n\nmin : "<<bst2.Min();
    }catch (std::length_error err) {
        std::clog<<err.what();
    }



}

/*
void testPriorityQueue(){


    lasd::Vector<int> vettore(7);
    for(int i=0;i<7;i++){
        vettore[i] = 12 -i;
    }


    lasd::PriorityQueue<int> PQ1(vettore);
    std::cout<<"*priority queue* "<<std::endl;

    std::cout<<"TEST COPY CONSTRUCTOR : "<<std::endl;
    lasd::PriorityQueue<int> PQ2(PQ1);
    std::cout<<"stampa di LinearHeap2 : "<<std::endl;
    PQ2.PrintArray();


    std::cout<<"\n\nTEST MOVE CONSTRUCTOR : "<<std::endl;
    lasd::PriorityQueue<int> PQ3(std::move(PQ1));
    std::cout<<"stampa di LinearHeap passato con move (vuoto) : "<<std::endl;
    PQ1.PrintArray();
    std::cout<<"stampa di LinearHeap3  : "<<std::endl;
    PQ3.PrintArray();

    std::cout<<"\n\nTEST COPY ASSIGNMENT : "<<std::endl;
    PQ1 = PQ3;
    std::cout<<"stampa di LinearHeap al quale e' assegnato linearheap3  : "<<std::endl;
    PQ1.PrintArray();

    std::cout<<"\n\nTEST MOVE ASSIGNMENT : "<<std::endl;
    PQ1 = std::move(PQ3);
    std::cout<<"stampa di LinearHeap3 passato assegnato per move (vuoto) : "<<std::endl;
    PQ3.PrintArray();
    std::cout<<"stampa di LinearHeap al quale e' assegnato linearheap3 : "<<std::endl;
    PQ1.PrintArray();

    std::cout<<"\n\nTest di uguaglianza : \n";

    if(PQ1 == PQ2) std::cout<<"le due strutture sono uguali\n";
    else std::cout<<"sono diversi\n";

    if(PQ1 == PQ3) std::cout<<"le due strutture sono uguali\n";
    else std::cout<<"sono diversi\n";

    lasd::PriorityQueue<int> PQ4;
    if(PQ4 == PQ3) std::cout<<"le due strutture sono uguali\n";
    else std::cout<<"sono diversi";

    std::cout<<"\ntest vuotezza linearheap3 : "<<PQ3.Empty();

    std::cout<<"\ntest vuotezza linearheap : "<<PQ1.Empty();

    std::cout<<"\nsize linearheap : "<<PQ1.Size();







}
*/




/**BinarySearchTree*/


void BinarySearchTreeInt(){
    char scelta = '0';
    int n;

    lasd::BST<int> bst;
    std::cout << "Quanti elementi deve contenere il BST? : \n";
        std::cin>>n;
        //bst.NewRoot(IntValueGenerator());
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
                    std::cout <<"Elemento minimo rimosso con successo!";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'e'://rimozione
                    std::cout << " ** REMOVE MIN ** \n\n";
                    try{
                    bst.RemoveMin();
                    std::cout <<"Elemento minimo rimosso con successo!";
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
                    std::cout <<"Elemento massimo rimosso con successo!";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;
                case 'y':
                    std::cout << " ** REMOVE MAX ** \n\n";
                    try{
                    bst.RemoveMax();
                    std::cout <<"Elemento massimo rimosso con successo!";
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
                        std::cout<<"Predecessore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}

                    break;
                case 'o':
                    std::cout << " ** REMOVE PREDECESSOR ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole eliminare il predecessore all' interno dell' albero : \n";
                        int predeced_item;
                        std::cin>>predeced_item;
                        bst.RemovePredecessor(predeced_item);
                        std::cout<<"Predecessore eliminato con successo!. \n";
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
                        std::cout<<"Successore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}

                    break;
                case 's':
                    std::cout << " ** REMOVE SUCCESSOR ** \n\n";
                    try{
                        std::cout<<"Inserire il valore del quale si vuole eliminare il successore all' interno dell' albero : \n";
                        int succeeded_item;
                        std::cin>>succeeded_item;
                        bst.RemoveSuccessor(succeeded_item);
                        std::cout<<"Successore eliminato con successo!. \n";
                    }catch(std::length_error error){ std::clog<<error.what();}
                    break;

                case 'b':
                    return;
                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }

            }
    }
/*
void BinaryTreeHeapFloat(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere il vettore di generazione ? : \n";
    std::cin>>n;
    lasd::Vector<float> vettore(n);
    for(int i = 0;i<n;i++) vettore[i] = FloatValueGenerator();

    std::cout << "\n\n ** Generazione albero Heap tramite un vettore... ** \n\n";

    lasd::Heap<float> heap(vettore);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente MinHeap di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold SumFloatBiggerThan. \n";
        std::cout << "5. Map Opposite Float. \n";
        std::cout << "6. Sort \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(heap);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(heap);
                break;
            case '3':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(heap.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '4':
                std::cout << " ** FOLD SumFloatBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma dei float maggiori di "<<elem<<" e' :"<<FoldTreeHeapFloatSumBiggerThan(elem, heap);
                break;
            case '5':
                std::cout << " ** MAP Opposite Float ** \n\n";
                NegatifyDataForBinaryTreeHeap(heap);
                break;
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                heap.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeHeapString(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere il vettore di generazione ? : \n";
    std::cin>>n;
    lasd::Vector<std::string> vettore(n);
    for(int i = 0;i<n;i++) vettore[i] = CharValueGenerator();

    std::cout << "\n\n ** Generazione albero Heap tramite un vettore... ** \n\n";

    lasd::Heap<std::string> heap(vettore);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente MinHeap di stringhe? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold StringConcatLowerEqualsThan. \n";
        std::cout << "5. Map InitialConcatString \n";
        std::cout << "6. Sort \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(heap);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(heap);
                break;
            case '3': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (heap.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '4':
                std::cout << " ** FOLD StringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int length;
                std::cin >> length;
                std::cout << "La concatenazione di stringhe con lunghezza minore o uguale a " << length << " e' :"
                          << FoldTreeHeapStringConcatLowerEqualsThan(length, heap);
                break;
            case '5':{
                std::cout << " ** MAP InitialConcatString ** \n\n";
                std::string par;
                std::cout << "Che sequenza vuoi concatenare all'inizio di ogni stringa dello heap ? \n";
                std::cin >> par;
                InitialConcatStringForBinaryTreeHeap(heap,&par);
                break;
             }
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                heap.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}
*/
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
                //BinarySearchTreeFloat();
                break;
            case '3':
                std::cout << " ** BST DI STRINGHE ** \n\n";
                //BinarySearchTreeString();
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





/** **/


/*
void BinaryTreePQueueInt(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere la lista di generazione ? : \n";
    std::cin>>n;
    lasd::List<int> lista;
    int i = 0;
    while(i<n){
        lista.InsertAtBack(IntValueGenerator());
        i++;
    }

    std::cout << "\n\n ** Generazione Priority Queue tramite una lista... ** \n\n";

    lasd::PriorityQueue<int> Pqueue(lista);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con la seguente Priority Queue di interi? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold MoltiplicateIntSmallerThan. \n";
        std::cout << "5. Map n*(-1)^n. \n";
        std::cout << "6. Sort \n";
        std::cout << "7. Menu' navigazione nodi. \n";



        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(Pqueue);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(Pqueue);
                break;
            case '3':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(Pqueue.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '4':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeHeapIntMoltiplicateSmallerThan(elem, Pqueue);
                break;
            case '5':
                std::cout << " ** MAP n*(-1)^n ** \n\n";
                FunIntEx4ForBinaryTreeHeap(Pqueue);
                break;
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                Pqueue.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case '7':
                std::cout << "\n\n ** NAVIGAZIONE TRA I NODI ** \n";
                std::cout<<"NOTA: Le funzioni 'tip' sono disponibili solo sulla root dell' albero. \n\n";
                TreePQueueNavigation(&Pqueue);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreePQueueFloat(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere la lista di generazione ? : \n";
    std::cin>>n;
    lasd::List<float> lista;
    int i = 0;
    while(i<n){
        lista.InsertAtFront(FloatValueGenerator());
        i++;
    }

    std::cout << "\n\n ** Generazione Priority Queue tramite una lista... ** \n\n";

    lasd::PriorityQueue<float> Pqueue(lista);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con la seguente Priority Queue di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold SumFloatBiggerThan. \n";
        std::cout << "5. Map Opposite Float. \n";
        std::cout << "6. Sort. \n";
        std::cout << "7. Menu' navigazione nodi. \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(Pqueue);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(Pqueue);
                break;
            case '3':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(Pqueue.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '4':
                std::cout << " ** FOLD SumFloatBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma dei float maggiori di "<<elem<<" e' :"<<FoldTreeHeapFloatSumBiggerThan(elem, Pqueue);
                break;
            case '5':
                std::cout << " ** MAP Opposite Float ** \n\n";
                NegatifyDataForBinaryTreeHeap(Pqueue);
                break;
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                Pqueue.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case '7':
                std::cout << "\n\n ** NAVIGAZIONE TRA I NODI ** \n\n";
                std::cout<<"NOTA: Le funzioni 'tip' sono disponibili solo sulla root dell' albero. \n\n";
                TreePQueueNavigation(&Pqueue);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreePQueueString(){
    char scelta = '0';
    int n;

    std::cout << "Quanti elementi deve contenere la lista di generazione ? : \n";
    std::cin>>n;
    lasd::List<std::string> lista;
    int i = 0;
    while(i<n){
        lista.InsertAtFront(CharValueGenerator());
        i++;
    }

    std::cout << "\n\n ** Generazione Priority Queue tramite una lista... ** \n\n";

    lasd::PriorityQueue<std::string> Pqueue(lista);

    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con la seguente Priority Queue di float? : \n";
        std::cout << "1. MapPreOrder Print. \n";
        std::cout << "2. MapPostOrder Print. \n";
        std::cout << "3. Exists. \n";
        std::cout << "4. Fold StringConcatLowerEqualsThan. \n";
        std::cout << "5. Map InitialConcatString. \n";
        std::cout << "6. Sort. \n";
        std::cout << "7. Menu' navigazione nodi. \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementHeapPreOrder(Pqueue);
                break;
            case '2':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementHeapPostOrder(Pqueue);
                break;
            case '3':{
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (Pqueue.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '4':
                std::cout << " ** FOLD StringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int length;
                std::cin >> length;
                std::cout<<"La concatenazione di stringhe con lunghezza minore o uguale a "<<length<<" e' :"<<FoldTreeHeapStringConcatLowerEqualsThan(length, Pqueue);
                break;
            case '5':{
                std::cout << " ** MAP InitialConcatString ** \n\n";
                std::string par;
                std::cout << "Che sequenza vuoi concatenare all'inizio di ogni stringa della Priority Queue? \n";
                std::cin >> par;
                InitialConcatStringForBinaryTreeHeap(Pqueue,&par);
                break;
            }
            case '6':
                std::cout << "\n\n ** SORT ** \n\n";
                Pqueue.Sort();
                std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                break;
            case '7':
                std::cout << "\n\n ** NAVIGAZIONE TRA I NODI ** \n\n";
                std::cout<<"NOTA: Le funzioni 'tip' sono disponibili solo sulla root dell' albero. \n\n";
                TreePQueueNavigation(&Pqueue);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}


void BinaryTreePriorityQueue(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.Priority Queue di interi. \n";
        std::cout << "2.Priority Queue di float. \n";
        std::cout << "3.Priority Queue di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** PRIORITY QUEUE DI INTERI ** \n\n";
                BinaryTreePQueueInt();
                break;
            case '2':
                std::cout << " ** PRIORITY QUEUE DI FLOAT ** \n\n";
                BinaryTreePQueueFloat();
                break;
            case '3':
                std::cout << " ** PRIORITY QUEUE DI STRINGHE ** \n\n";
                BinaryTreePQueueString();
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



*/

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
                //BinaryTreePriorityQueue();
                break;
            case '3':
                std::cout << " ** TEST R&B ** \n\n";
                //BinaryTreePriorityQueue();
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








