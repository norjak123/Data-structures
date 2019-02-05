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

template <class H> class Stack{
    public:
        Stack();
        void setHead(Node<H> * head);
        Node<H> * getHead();
        H topElement();
        void push(H value);
        H pop();
        void printStack();
    protected:

    private:
        Node<H> * head;
};

template <class H> Stack<H>::Stack(){
    this->head = NULL;
}

template <class H> void Stack<H>::setHead(Node<H> * head){
    this->head = head;
}

template <class H> Node<H> * Stack<H>::getHead(){
    return this->head;
}

template <class H> H Stack<H>::topElement(){
    if(this->getHead() == NULL){
        return -1;
    }
    else{
        return this->getHead()->getValue();
    }
}

template <class H> void Stack<H>::push(H value){
    Node<H> * node = new Node<H>(value);
    if(this->getHead() == NULL){
        this->head = node;
    }
    else{
        Node<H> * aux = this->head;
        node->setNext(aux);
        this->head = node;
    }
}

template <class H> H Stack<H>::pop(){
    if(this->head == NULL){
        return -1;
    }
    else{
        H value = this->topElement();
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

template <class H> void Stack<H>::printStack(){
    if(this->head == NULL){
        cout << "Stack is empty. " << endl;
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
    Stack<int> * s1 = new Stack<int>;
    s1->push(4);
    s1->push(3);
    s1->push(2);
    s1->push(1);
    s1->printStack();
    cout << "Removed: " << s1->pop() << endl;
    s1->printStack();
    for(int i = 0; i < 3; i++){
        cout << "Removed: " << s1->pop() << endl;
    }
    s1->printStack();
}
