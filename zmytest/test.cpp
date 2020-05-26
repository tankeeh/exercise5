

#include <iostream>
#include "RandomGens/RandomValues.hpp"
//#include "./TreeUtils/TreeUtilsFunctions.hpp"
//#include "./TreeUtils/treeNavFunctions/NavigateFunctions.hpp"
#include "../list/list.hpp"


/*
template <typename Data>
void lasd::Heap<Data>::PrintArray(){
    for (int i =0; i<this->size; i++)
        std::cout<<this->tree[i]->Element()<<" "<< this->tree[i]->getIndex()<<std::endl;
}
*/


/** MY TESTS **/


/*
void testHeap(){




    lasd::Vector<int> vettore(7);
    for(int i=0;i<7;i++){
        vettore[i] = 12 -i;
    }


    lasd::Heap<int> linearHeap(vettore);
    std::cout<<"*Heap*"<<std::endl;

    std::cout<<"\n\nTEST COPY CONSTRUCTOR : "<<std::endl;
    lasd::Heap<int> linearHeap2(linearHeap);
    std::cout<<"stampa di LinearHeap2 : "<<std::endl;
    linearHeap2.PrintArray();


    std::cout<<"\n\nTEST MOVE CONSTRUCTOR : "<<std::endl;
    lasd::Heap<int> linearHeap3(std::move(linearHeap));
    std::cout<<"stampa di LinearHeap passato con move (vuoto) : "<<std::endl;
    linearHeap.PrintArray();
    std::cout<<"stampa di LinearHeap3  : "<<std::endl;
    linearHeap3.PrintArray();

    std::cout<<"\n\nTEST COPY ASSIGNMENT : "<<std::endl;
    linearHeap = linearHeap3;
    std::cout<<"stampa di LinearHeap al quale e' assegnato linearheap3  : "<<std::endl;
    linearHeap.PrintArray();

    std::cout<<"\n\nTEST MOVE ASSIGNMENT : "<<std::endl;
    linearHeap = std::move(linearHeap3);
    std::cout<<"stampa di LinearHeap3 passato assegnato per move (vuoto) : "<<std::endl;
    linearHeap3.PrintArray();
    std::cout<<"stampa di LinearHeap al quale e' assegnato linearheap3 : "<<std::endl;
    linearHeap.PrintArray();

    std::cout<<"\n\nTest di uguaglianza : \n";

    if(linearHeap == linearHeap2) std::cout<<"le due strutture sono uguali\n";
    else std::cout<<"sono diversi\n";

    if(linearHeap == linearHeap3) std::cout<<"le due strutture sono uguali\n";
    else std::cout<<"sono diversi\n";

    lasd::Heap<int> linearHeap4;
    if(linearHeap4 == linearHeap3) std::cout<<"le due strutture sono uguali\n";
    else std::cout<<"sono diversi";

    std::cout<<"\ntest vuotezza linearheap3 : "<<linearHeap3.Empty();

    std::cout<<"\ntest vuotezza linearheap : "<<linearHeap.Empty();

    std::cout<<"\nsize linearheap : "<<linearHeap.Size();



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




/**BinaryTreeHeap**/

/*
void BinaryTreeHeapInt(){
    char scelta = '0';
    int n;

        std::cout << "Quanti elementi deve contenere il vettore di generazione ? : \n";
        std::cin>>n;
        lasd::Vector<int> vettore(n);
        for(int i = 0;i<n;i++) vettore[i] = IntValueGenerator();

        std::cout << "\n\n ** Generazione albero Heap tramite un vettore... ** \n\n";

        lasd::Heap<int> heap(vettore);

        while (scelta != 'b') {
            std::cout << "\n\nCosa vuoi fare con il seguente MinHeap di interi? : \n";
            std::cout << "1. MapPreOrder Print. \n";
            std::cout << "2. MapPostOrder Print. \n";
            std::cout << "3. Exists. \n";
            std::cout << "4. Fold MoltiplicateIntSmallerThan. \n";
            std::cout << "5. Map n*(-1)^n. \n";
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
                    int item;
                    std::cin >> item;
                    if(heap.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                    else std::cout<<"L'elemento e' assente nell' albero";
                    break;
                case '4':
                    std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                    std::cout << "Inserire il valore con cui chiamare la Fold : ";
                    int elem;
                    std::cin >> elem;
                    std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeHeapIntMoltiplicateSmallerThan(elem, heap);
                    break;
                case '5':
                    std::cout << " ** MAP n*(-1)^n ** \n\n";
                    FunIntEx4ForBinaryTreeHeap(heap);
                    break;
                case '6':
                    std::cout << "\n\n ** SORT ** \n\n";
                    heap.Sort();
                    std::cout << "L'albero e' adesso ordinato totalmente. \n\n";
                    break;
                case 'b':
                    return;
                    break;
                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }

            }
    }

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

void BinaryTreeHeap(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.Heap di interi. \n";
        std::cout << "2.Heap di float. \n";
        std::cout << "3.Heap di string. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** HEAP DI INTERI ** \n\n";
                BinaryTreeHeapInt();
                break;
            case '2':
                std::cout << " ** HEAP DI FLOAT ** \n\n";
                BinaryTreeHeapFloat();
                break;
            case '3':
                std::cout << " ** HEAP DI STRINGHE ** \n\n";
                BinaryTreeHeapString();
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

/**BinaryTreePriorityQueue**/


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





void mytest() {

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per testare un Albero Heap. \n";
        std::cout << "2. per testare una Priority Queue. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** TEST Heap ** \n\n";
                BinaryTreeHeap();
                break;
            case '2':
                std::cout << " ** TEST Priority Queue ** \n\n";
                BinaryTreePriorityQueue();
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
*/







