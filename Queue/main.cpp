#include <iostream>
#include <string>
using namespace std;

template <class H> class Node{
    public:
        Node(H value);
        void setValue(H value);
        H getValue();
        void setNext(Node<H> * next);
        Node<H> * getNext();
    protected:

    private:
        H value;
        Node<H> * next;
};

template <class H> class Queue{
    public:
        Queue();
        void setHead(Node<H> * head);
        Node<H> * getHead();
        void enqueue(H value);
        H dequeue();
        void printQueue();
    protected:

    private:
        Node<H> * head;

};

template <class H> Queue<H>::Queue(){
    this->head = NULL;
}

template <class H> void Queue<H>::setHead(Node<H> * head){
    this->head = head;
}

template <class H> Node<H> * Queue<H>::getHead(){
    return this->head;
}

template <class H> void Queue<H>::enqueue(H value){
    Node<H> * node = new Node<H>(value);
    if(this->head == NULL){
        this->head = node;
    }
    else{
        Node<H> * aux = this->head;
        while(aux->getNext() != NULL){
            aux = aux->getNext();
        }
        aux->setNext(node);
    }
}

template <class H> H Queue<H>::dequeue(){
    if(this->head == NULL){
        return -1;
    }
    else{
        H value = this->head->getValue();
        Node<H> * aux = this->head;
        if(aux->getNext() != NULL){
            this->head = aux->getNext();
        }
        else{
            this->head = NULL;
        }
        return value;
    }
}

template <class H> void Queue<H>::printQueue(){
    if(this->head == NULL){
        cout << "Queue is empty. " << endl;
    }
    else{
        Node<H> * aux = this->head;
        while(aux != NULL){
            cout << aux->getValue() << " ";
            aux = aux->getNext();
        }
        cout << endl;
    }
}

template <class H> Node<H>::Node(H value){
    this->value = value;
    this->next = NULL;
}

template <class H> void Node<H>::setValue(H value){
    this->value = value;
}

template <class H> H Node<H>::getValue(){
    return this->value;
}

template <class H> void Node<H>::setNext(Node<H> * next){
    this->next = next;
}

template <class H> Node<H> * Node<H>::getNext(){
    return this->next;
}

int main()
{
    Queue<int> * q1 = new Queue<int>;
    q1->enqueue(1);
    q1->enqueue(2);
    q1->enqueue(3);
    q1->enqueue(4);
    q1->printQueue();
    cout << "Removed: " << q1->dequeue() << endl;
    q1->printQueue();
    for(int i = 0; i < 3; i++){
        cout << "Removed: " << q1->dequeue() << endl;
    }
    q1->printQueue();
}
