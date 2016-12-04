
#ifndef BFSEARCH_h
#define BFSEARCH_h

#include <queue>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
 
/****************************************************************
 
 Performs the Breadth-First Graph search for both directed and
 undirected graphs. This algorithm explores all the findable nodes
 in "layers".
 @author Bibek Subedi
*****************************************************************/
 
 
/****************************************************************
 
Class Queue represent a Queue data structure which is First In
First Out [FIFO] structured. It has operations like Enqueue which
adds an element at the rear side and Dequeue which removes the
element from front.
 
*****************************************************************/
 
/*struct node {
    int info;
    node *next;
};
 
class Queue {
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();
 
};
 
void Queue::display(){
    node *p = new node;
    p = front;
    if(front == NULL){
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}
 
Queue::Queue() {
    front = NULL;
    rear = NULL;
}
 
Queue::~Queue() {
    delete front;
}
 
void Queue::enqueue(int data) {
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
}
 
int Queue::dequeue() {
    node *temp = new node();
    int value;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}
 
bool Queue::isEmpty() {
    return (front == NULL);
}*/




class Graph {
    private:
        int n; /// n is the number of vertices in the graph
        int **A; /// A stores the edges between two vertices
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int u, int v);
        void BFS(int );
};
 
Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}
 
Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}
 
 
/******************************************************
Checks if two given vertices are connected by an edge
@param u vertex
@param v vertex
@return true if connected false if not connected
******************************************************/
bool Graph::isConnected(int u, int v) {
    return (A[u-1][v-1] == 1);
}
 
/*****************************************************
adds an edge E to the graph G.
@param u vertex
@param v vertex
*****************************************************/
void Graph::addEdge(int u, int v) {
    A[u-1][v-1] = A[v-1][u-1] = 1;
}
 
/*****************************************************
performs Breadth First Search
@param s initial vertex
*****************************************************/
void Graph::BFS(int s) {
    queue<int> Q;
    cout << "n" << "is  " << n << endl;
    /** Keeps track of explored vertices */
    bool *explored = new bool[n+1];
    vector<int> distance(n);
    fill(distance.begin(), distance.end(), 0);

 
    /** Initailized all vertices as unexplored */
    for (int i = 1; i <= n; ++i)
    explored[i] = false;
 
    /** Push initial vertex to the queue */
    Q.push(s);
    explored[s] = true; /** mark it as explored */
    distance[s] = 0 ;
    cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
 
    /** Unless the queue is empty */
    while (!Q.empty()) {
        /** Pop the vertex from the queue */
        int v = Q.front();
        Q.pop();
 
        /** display the explored vertices */
        cout << v << " ";
 
        /** From the explored vertex v try to explore all the
        connected vertices */
        for (int w = 1; w <= n; ++w)
 
            /** Explores the vertex w if it is connected to v
            and and if it is unexplored */
            if (isConnected(v, w) && !explored[w]) {
                /** adds the vertex w to the queue */
                Q.push(w);
                distance[w] = distance[v] + 1;
                /** marks the vertex w as visited */
                explored[w] = true;
            }
    }
    cout << endl;
    delete [] explored;

    cout << "this is where my code starts" << endl ;
    cout << endl ;
    cout << " distance from " << s << endl ;
    for( int i = 0 ; i < distance.size() ; i++)
    {
 
        cout<< i << "distance from source" << distance[i] << endl ;
    }
}


#endif
