#include <iostream>
#include <string>
using namespace std;

template <class H> class Node{
    public:
        Node(H value);
        void setValue(H value);
        void setNext(Node<H> * next);
        H getValue();
        Node<H> * getNext();
    protected:

    private:
        H value;
        Node<H> * next;
};

template <class H> class List{
    public:
        List();
        void setHead(Node<H> * head);
        Node<H> * getHead();
        bool isEmpty();
        void insertNode(H value);
        void printList();

    protected:

    private:
        Node<H> * head;
};

template <class H> class Graph{
    public:
        Graph(int len);
        bool isFull();
        int searchNode(H value);
        void addNode(H value);
        void addEdge(H first, H second);
        void printGraph();
    protected:

    private:
        int len;
        int index;
        H * vertex;
        List<H> **AdjList;
};

template <class H> Graph<H>::Graph(int len){
    this->len = len;
    this->index = 0;
    this->vertex = new H[this->len];
    this->AdjList = new List<H> * [this->len];
    for(int i = 0; i < this->len; i++){
        this->AdjList[i] = new List<H>;
    }
}

template <class H> bool Graph<H>::isFull(){
    if(this->index == this->len){
        return true;
    }
    else{
        return false;
    }
}

template <class H> int Graph<H>::searchNode(H value){
    for(int i = 0; i < this->index; i++){
        if(this->vertex[i] == value){
            return i;
        }
    }
    return -1;
}

template <class H> void Graph<H>::addNode(H value){
    if(this->isFull()){
        cout << "Graph is full. " << endl;
    }
    else if(this->searchNode(value) != -1){
        cout << "A node with this value already exist. " << endl;
    }
    else{
        this->vertex[this->index] = value;
        this->index++;
    }
}

template <class H> void Graph<H>::addEdge(H first, H second){
    int posFirst = this->searchNode(first);
    int posSecond = this->searchNode(second);
    if((posFirst == -1) || (posSecond == -1)){
        cout << "There are no nodes with these values. " << endl;
    }
    else{
        this->AdjList[posFirst]->insertNode(second);
    }
}

template <class H> void Graph<H>::printGraph(){
    for(int i = 0; i < this->index; i++){
        cout << "(" << this->vertex[i] << ") : ";
        this->AdjList[i]->printList();
        cout << endl;
    }
}

template <class H> List<H>::List(){
    this->head = NULL;
}

template <class H> void List<H>::setHead(Node<H> * head){
    this->head = NULL;
}

template <class H> Node<H> * List<H>::getHead(){
    return this->head;
}

template <class H> bool List<H>::isEmpty(){
    if(this->head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <class H> void List<H>::insertNode(H value){
    Node<H> * newNode = new Node<H>(value);
    if(this->isEmpty()){
        this->head = newNode;
    }
    else{
        Node<H> * aux = this->head;
        while(aux->getNext() != NULL){
            aux = aux->getNext();
        }
        aux->setNext(newNode);
    }
}

template <class H> void List<H>::printList(){
    if(this->head == NULL){
        cout << "List is empty. " << endl;
    }
    else{
        Node<H> * aux = this->head;
        while(aux != NULL){
            cout << aux->getValue() << " ";
            aux = aux->getNext();
        }
    }
}

template <class H> Node<H>::Node(H value){
    this->value = value;
    this->next = NULL;
}

template <class H> void Node<H>::setValue(H value){
    this->value = value;
}

template <class H> void Node<H>::setNext(Node<H> * next){
    this->next = next;
}

template <class H> H Node<H>::getValue(){
    return this->value;
}

template <class H> Node<H> * Node<H>::getNext(){
    return this->next;
}

int main()
{
    Graph<int> * g1 = new Graph<int>(3);
    g1->addNode(2);
    g1->addNode(3);
    g1->addNode(4);
    g1->addEdge(2, 3);
    g1->addEdge(2, 4);
    g1->addEdge(4, 3);
    g1->addEdge(3, 4);
    g1->printGraph();
}
