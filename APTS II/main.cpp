#include <fstream>
#include <iostream>
using namespace std;

class Queue {
private:
    struct elem {
        int value;
        elem *next;
    };
    elem *first;
    elem *last;
public:
    Queue() {
        first=last=NULL;
    }
    void enqueue(int val) {
        elem *p = new elem; /// s1
        p->value=val; /// s2
        p->next=NULL; /// s3
        if(first==NULL) first=p; /// s4a
        else last->next=p; /// s4b
        last=p; /// s5
    }
    int dequeue() {
        int val=-1;
        elem *p = first; /// 1
        if (p!=NULL) {
            val = p->value;
            first = p->next; /// 2
            delete p; /// 3
            p=first; /// 4
        }
        return val;
    }
    bool empty() {
        return (first == NULL);
    }
    ~Queue() {
        elem *p = first; /// 1
        while (p!=NULL) {
            first = p->next; /// 2
            delete p; /// 3
            p=first; /// 4
        }
    }
// TESTING PURPOUSES/////////////////////////
    void print() {
        elem *p=first;
        while (p!=NULL) {
            cout<<p->value<<" ";
            p=p->next;
        }
        cout<<endl;
    }
/////////////////////////////////////////
};

class List {
private:
    struct elem {
        int value;
        elem *next;
    };
public:
    elem *start;
    elem *last;
    List() {
        start=last=NULL;
    }
    void push_back(int val) {
        elem *p = new elem; /// s1
        p->value=val; /// s2
        p->next=NULL; /// s3
        if(start==NULL) start=p; /// s4a
        else last->next=p; /// s4b
        last=p; /// s5
    }
    ~List() {
        elem *p = start; /// 1
        while (p!=NULL) {
            start = p->next; /// 2
            delete p; /// 3
            p=start; /// 4
        }
    }
};

void add_edge(List adj[], int source, int dest) {
    adj[source].push_back(dest);
    adj[dest].push_back(source);
}

bool BreadthFirstSearch(List adj[], int source, int dest, int vertices, int prev[], int dist[]){
    //Izveido tuksu rindu
    Queue que;
    //Uzstada, ka vel neesam bijusi neviena virsotne
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = 999999;
        prev[i] = -1;
    }
    //Source mes esam apmeklejusi un tas bija 0 garuma
    visited[source] = true;
    dist[source] = 0;
    que.enqueue(source);

    // standard BFS algorithm
    // JASAFIXO SI DALA
    while (!que.empty()) {
        int w = que.dequeue();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                   return true;
            }
        }
    }

    return false;
}


int main() {
    //NOLASA NO FAILA CIK BUS VIRSOTNU
    int v = 1;
    // IZVEIDO INCIDENCES SARAKSTU
    List adj[v];
    // LASA NO FAILA VIRSOTNES;
    add_edge(adj, 0, 1);
    //IZDZEST LISTUS

}
