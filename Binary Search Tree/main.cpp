#include <iostream>
#include <string>
using namespace std;

template <class H> class Node{
    public:
        Node(H value);
        void setValue(H value);
        H getValue();
        void setFather(Node<H> * father);
        Node<H> * getFather();
        void setLeft(Node<H> * left);
        Node<H> * getLeft();
        void setRight(Node<H> * right);
        Node<H> * getRight();
    protected:

    private:
        H value;
        Node<H> * father;
        Node<H> * left;
        Node<H> * right;
};

template <class H> class BST{
    public:
        BST();
        void setRoot(Node<H> * root);
        Node<H> * getRoot();
        bool isEmpty();
        Node<H> * searchNode(H value);
        Node<H> * maxNode(Node<H> * node);
        Node<H> * minNode(Node<H> * node);
        Node<H> * successor(Node<H> * node);
        void preorder(Node<H> * node);
        void inorder(Node<H> * node);
        void postorder(Node<H> * node);
        void insertValue(H value);
        void deleteValue(H value);
        void trasplant(Node<H> * u, Node<H> * v);
    protected:

    private:
        Node<H> * root;
};

template <class H> BST<H>::BST(){
    this->root = NULL;
}

template <class H> void BST<H>::setRoot(Node<H> * root){
    this->root = root;
}

template <class H> Node<H> * BST<H>::getRoot(){
    return this->root;
}

template <class H> bool BST<H>::isEmpty(){
    if(this->root == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <class H> Node<H> * BST<H>::searchNode(H value){
    if(this->isEmpty()){
        return NULL;
    }
    else{
        Node<H> * aux = this->root;
        while((aux != NULL) && (aux->getValue() != value)){
            if(aux->getValue() >= value){
                aux = aux->getLeft();
            }
            else{
                aux = aux->getRight();
            }
        }
        return aux;
    }
}

template <class H> Node<H> * BST<H>::maxNode(Node<H> *node){
    Node<H> * aux = node;
    while(aux->getRight() != NULL){
        aux = aux->getRight();
    }
    return aux;
}

template <class H> Node<H> * BST<H>::minNode(Node<H> * node){
    Node<H> * aux = node;
    while(aux->getLeft() != NULL){
        aux = aux->getLeft();
    }
    return aux;
}

template <class H> Node<H> * BST<H>::successor(Node<H> * node){
    Node<H> * aux = node;
    if(aux->getRight() != NULL){
        return this->minNode(aux->getRight());
    }
    else{
        Node<H> * father = aux->getFather();
        while((father != NULL) && (father->getRight() == aux)){
            aux = father;
            father = father->getFather();
        }
        return father;
    }
}

template <class H> void BST<H>::preorder(Node<H> * node){
    if(node != NULL){
        cout << node->getValue() << " ";
        preorder(node->getLeft());
        preorder(node->getRight());
    }
}

template <class H> void BST<H>::inorder(Node<H> * node){
    if(node != NULL){
        inorder(node->getLeft());
        cout << node->getValue() << " ";
        inorder(node->getRight());
    }
}

template <class H> void BST<H>::postorder(Node<H> * node){
    if(node != NULL){
        postorder(node->getLeft());
        postorder(node->getRight());
        cout << node->getValue() << " ";
    }
}

template <class H> void BST<H>::insertValue(H value){
    Node<H> * node = new Node<H>(value);
    if(this->isEmpty()){
        this->root = node;
    }
    else{
        Node<H> * aux = this->root;
        Node<H> * auxn = NULL;
        while(aux != NULL){
            auxn = aux;
            if(aux->getValue() >= value){
                aux = aux->getLeft();
            }
            else{
                aux = aux->getRight();
            }
        }
        node->setFather(auxn);
        if(auxn->getValue() >= value){
            auxn->setLeft(node);
        }
        else{
            auxn->setRight(node);
        }
    }
}

template <class H> void BST<H>::trasplant(Node<H> * u, Node<H> * v){
    if(u == u->getFather()->getLeft()){
        u->getFather()->setLeft(v);
    }
    else if(u == u->getFather()->getRight()){
        u->getFather()->setRight(v);
    }
    if(v != NULL){
        v->setFather(u->getFather());
    }
}

template <class H> void BST<H>::deleteValue(H value){
    Node<H> * node = this->searchNode(value);
    if(node != NULL){
        if(node->getLeft() == NULL){
            trasplant(node, node->getRight());
        }
        else if(node->getRight() == NULL){
            trasplant(node, node->getLeft());
        }
        else{
            Node<H> * successor = this->successor(node);
            if(successor->getFather() == node){
                trasplant(successor, successor->getRight());
                successor->setRight(node->getRight());
                successor->getRight()->setFather(successor);
            }
            else{
                trasplant(node, successor);
                successor->setLeft(node->getLeft());
                successor->getLeft()->setFather(successor);
            }
        }
    }
    else{
        cout << "Node does not exist. " << endl;
    }
}

template <class H> Node<H>::Node(H value){
    this->value = value;
    this->father = NULL;
    this->left = NULL;
    this->right = NULL;
}

template <class H> void Node<H>::setValue(H value){
    this->value = value;
}

template <class H> H Node<H>::getValue(){
    return this->value;
}

template <class H> void Node<H>::setFather(Node<H> * father){
    this->father = father;
}

template <class H> Node<H> * Node<H>::getFather(){
    return this->father;
}

template <class H> void Node<H>::setLeft(Node<H> * left){
    this->left = left;
}

template <class H> Node<H> * Node<H>::getLeft(){
    return this->left;
}

template <class H> void Node<H>::setRight(Node<H> * right){
    this->right = right;
}

template <class H> Node<H> * Node<H>::getRight(){
    return this->right;
}



int main()
{
    BST<int> * b1 = new BST<int>;
    b1->insertValue(10);
    b1->insertValue(7);
    b1->insertValue(9);
    b1->insertValue(3);
    b1->insertValue(25);
    b1->insertValue(12);
    b1->insertValue(30);
    b1->deleteValue(3);
    b1->deleteValue(12);
    b1->deleteValue(25);
    b1->preorder(b1->getRoot());
}
