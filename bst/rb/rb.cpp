
namespace lasd {

/* ************************************************************************** */

    //COPY CONSTRUCTOR DEL NODO
    template<typename Data>
    RB<Data>::RBNode::RBNode(const Data& item){
        this->val = new Data(item);
        this->color = 0;
        this->sx = nullptr;
        this->dx = nullptr;
    }

    //MOVE CONSTRUCTOR DEL NODO
    template<typename Data>
    RB<Data>::RBNode::RBNode(Data &&item){
        this->val = new Data(std::move(item));
        this->color = 0;
        this->sx = nullptr;
        this->dx = nullptr;
    }

    //OPERATORE DI UGUAGLIANZA (CHE RICHIAMA QUELLO DI BST)
    template<typename Data>
    bool RB<Data>::operator==(const RB &tree) const noexcept {
        return BST<Data>::operator==(tree);
    }

    //OPERATORE DI DISUGUAGLIANZA (CHE RICHIAMA QUELLO DI BST)
    template<typename Data>
    bool RB<Data>::operator!=(const RB &tree) const noexcept {
        return BST<Data>::operator!=(tree);
    }

/* ************************************************************************** */

}
