//
// Created by Antonio on 10/05/2020.
//



/**NAVIGAZIONE SULLE PRIORITY QUEUES**/
template <typename Data>
void RecursivePQueueNavigate(lasd::PriorityQueue<Data>* Pqueue,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul figlio sinistro \n";
        std::cout<<"2. per spostarsi sul figlio destro \n";
        std::cout<<"r. per spostarsi sul nodo padre \n";
        std::cout<<"3. per aggiungere un nodo \n";
        std::cout<<"4. per vedere il dato nella radice \n";
        std::cout<<"5. per cambiare la priorita' di un nodo \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild() && !(Pqueue->Empty())) {
                    std::cout<<"Mi sposto sul nodo sinistro...";
                    RecursivePQueueNavigate(Pqueue,&node->LeftChild());
                }else std::clog<<"Tale nodo non ha un figlio sinistro. \n\n";

                break;
            case '2':
                if(node->HasRightChild() && !(Pqueue->Empty()) ){
                    std::cout<<"Mi sposto sul nodo destro...";
                    RecursivePQueueNavigate(Pqueue,&node->RightChild());
                }
                else std::clog<<"Tale nodo non ha un figlio destro. \n\n";
                break;
            case 'r':
                if(node->HasParent()) {
                    std::cout << "Mi sposto sul nodo padre...";
                    return;
                }else std::clog<<"Tale nodo non ha un nodo padre. \n\n";
                break;
            case '3': {
                Data item;
                std::cout << "Che valore deve avere il nuovo nodo ? \n";
                std::cin >> item;
                Pqueue->Insert(item);
                break;
            }
            case '4':
                try {
                    std::cout << "Il dato nella radice e' : " << Pqueue->Tip() << "\n\n";
                }
                catch (std::length_error err){
                    std::clog<<err.what()<<"\n";
                }
                break;
            case '5':
                if(!(Pqueue->Empty())) {
                    Data val;
                    std::cout << "** CHANGE PRIORITY **";
                    std::cout << "Quale valore vuoi che sovrascriva il nodo che attualmente stai visitando ? \n";
                    std::cin >> val;
                    Pqueue->ChangePriority(*node, val);
                    std::cout << "Ricostruzione della Priority Queue come MinHeap...";
                }else {
                    std::clog<<"\n Nodo non presente. E' possibile che la priority queue sia vuota.\n\n";
                    return;
                }
                break;
            case 'e': {
                std::cout << " Esco dalla navigazione nodi... (potrebbe esserci la necessita' di richiamare piu' volte questo comando) \n";
                return;
                }
            default:
                std::cout<<"carattere non valido.";
    }
    }


}

template<typename Data>
void RootNavigator(lasd::PriorityQueue<Data>* Pq, typename lasd::BinaryTreeVec<Data>::NodeVec* node){
    char scelta='0';
    while (scelta !='e') {
        std::cout << "\n Attualmente sei sulla Root dell' albero \n";
        std::cout << "1. Per vedere il valore della radice." << std::endl;
        std::cout << "2. Per rimuovere nella radice" << std::endl;
        std::cout << "3. Per vedere l'elemento in radice e rimuoverlo" << std::endl;
        std::cout << "4. Per cambiare la priorita' della radice"<<std::endl;
        std::cout << "5. Per spostarsi sul figlio sinistro"<<std::endl;
        std::cout << "6. Per spostarsi sul figlio destro"<<std::endl;
        std::cout << "7. Per aggiungere un nuovo nodo"<<std::endl;
        std::cout << "e. Per tornare indietro"<<std::endl;
        std::cin>>scelta;
        switch (scelta) {
            case '1':{
                try {
                    std::cout << "Il valore della radice e' : " << Pq->Tip() << std::endl;
                }
                catch (std::length_error ex) {
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case '2':{
                try {
                    Pq->RemoveTip();
                    std::cout << "Radice rimossa." << std::endl;
                }
                catch (std::length_error ex) {
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case '3':{
                try {
                    std::cout << "L' elemento in radice e' : " << Pq->TipNRemove() << std::endl;
                    std::cout << "Radice rimossa.\n";
                }
                catch (std::length_error ex) {
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case '4':{
                if (!Pq->Empty()){
                    std::cout<<"Inserire il nuovo valore da sovrascrivere per la Radice : "<<std::endl;
                    Data newPriority;
                    std::cin>>newPriority;
                    Pq->ChangePriority(*node, newPriority);
                }
                else{
                    std::cout<<"Struttura vuota."<<std::endl;
                    std::cout<<"Che Elemento vuoi inserire ? "<<std::endl;
                    Data newPriority;
                    std::cin>>newPriority;
                    Pq->Insert(newPriority);
                }
                break;
            }
            case '5':{
                if (node->HasLeftChild())RecursivePQueueNavigate(Pq, &node->LeftChild());
                else std::cout << "Tale nodo non ha un figlio sinistro." << std::endl;
                break;
            }
            case '6':{
                if (node->HasRightChild()) RecursivePQueueNavigate(Pq, &node->RightChild());
                else std::cout<<"Tale nodo non ha un figlio destro."<<std::endl;
                break;
            }
            case '7':{
                std::cout<<"Che valore deve avere il nuovo nodo?"<<std::endl;
                Data newelem;
                std::cin>>newelem;
                Pq->Insert(newelem);
                break;
            }
            case 'e':{
                break;
            }
            default:{
                std::cout<<"\ncarattere non valido.";
                break;
            }
        }
    }
    return;
}

template <typename Data>
void TreePQueueNavigation(lasd::PriorityQueue<Data>* Pqueue){
    if(!(Pqueue->Empty())) {
        RootNavigator(Pqueue, &Pqueue->Root());
    }
    else{
        std::cout<<" PQ vuota."<<std::endl;
        std::cout<<" 1. inserire un elemento."<<std::endl;
        std::cout<<" Premi un tasto per tornare al menu' struttura."<<std::endl;

        char scelta = '0';
        std::cin>>scelta;
        if(scelta == '1'){
            Data val = 0;
            std::cout<<"inserire un qualsivoglia elemento."<<std::endl;
            std::cin>>val;
            Pqueue->Insert(val);
            RootNavigator(Pqueue,&Pqueue->Root());
        }
        else return;

    }
}



