#include <iostream>
#include <string>
using namespace std;

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
        bool **AdjMatrix;

};

template <class H> Graph<H>::Graph(int len){
    this->len = len;
    this->index = 0;
    this->vertex = new H[this->len];
    this->AdjMatrix = new bool * [this->len];
    for(int i = 0; i < this->len; i++){
        this->AdjMatrix[i] = new bool[this->len];
    }
    for(int i = 0; i< this->len; i++){
        for(int j = 0; j < this->len; j++){
            this->AdjMatrix[i][j] = 0;
        }
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
        cout << "A node with this value already exists. " << endl;
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
        this->AdjMatrix[posFirst][posSecond] = 1;
    }

}

template <class H> void Graph<H>::printGraph(){
    if(this->index == 0){
        cout << "Graph is empty. " << endl;
    }
    else{
        for(int i = 0; i < this->index; i++){
            for(int j = 0; j < this->index; j++){
                if(this->AdjMatrix[i][j] == 1){
                    cout << "(" << this->vertex[i] << "," << this->vertex[j] << ") ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    Graph<int> * g1 = new Graph<int>(3);
    g1->addNode(4);
    g1->addNode(6);
    g1->addNode(8);
    g1->addEdge(4, 6);
    g1->addEdge(4, 8);
    g1->addEdge(8, 4);
    g1->addEdge(6, 8);
    g1->printGraph();
}
