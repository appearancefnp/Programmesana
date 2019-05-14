#include <fstream>
using namespace std;

class Queue {
private:
    struct elem {
        int value;
        elem *next;
    };
    elem *first;
    elem *last;
    int count;
public:
    Queue() {
        first=last=NULL;
        count = 0;
    }
    void enqueue(int val) {
        elem *p = new elem; /// s1
        p->value=val; /// s2
        p->next=NULL; /// s3
        if(first==NULL) first=p; /// s4a
        else last->next=p; /// s4b
        last=p; /// s5
        count++;
    }
    int dequeue() {
        int val=-1;
        elem *p = first; /// 1
        if (p!=NULL) {
            val = p->value;
            first = p->next; /// 2
            delete p; /// 3
            p=first; /// 4
            count--;
        }
        return val;
    }
    bool empty() {
        return (count == 0);
    }
    int size() {
        return count;
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
    int count;
public:
    elem *start;
    elem *last;
    List() {
        start=last=NULL;
        count = 0;
    }
    void push_back(int val) {
        elem *p = new elem; /// s1
        p->value=val; /// s2
        p->next=NULL; /// s3
        if(start==NULL) start=p; /// s4a
        else last->next=p; /// s4b
        last=p; /// s5
        count++;
    }
    bool empty() {
        return (count == 0);
    }
    int size() {
        return count;
    }
    int& operator[] (int i) {
         elem *p = start;
         for (int j=0; j<i; j++) {
            p = p->next;
         }
         return p->value;
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

//Funkcija atgriez lielako distanci
int BreadthFirstSearchForMaxDist(List adj[], int source, int vertices, int dist[]){
    //Izveido tuksu rindu
    Queue que;
    //Izveido apmekletibas array
    int max;
    int visited[vertices];
    //Uzstada, ka vel neesam bijusi neviena virsotne
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        dist[i] = 999999;
        //prev[i] = -1;
    }
    //Source mes esam apmeklejusi un tas bija 0 garuma
    visited[source] = true;
    dist[source] = 0;
    que.enqueue(source);

    // standard BFS algorithm
    while (!que.empty()) {
        int w = que.dequeue();
        for (int i = 0; i < adj[w].size(); i++) {
            if (visited[adj[w][i]] == false) {
                visited[adj[w][i]] = true;
                dist[adj[w][i]] = dist[w] + 1;
                que.enqueue(adj[w][i]);
                max = dist[adj[w][i]] ;
            }
        }
    }
    return max;
}

void printServer(List adj[], int vertices, fstream &fout) {
    //Glabâ attâlumu masîvâ lîdz katrai virsotnei. Katrai virsotnei lielakais attalums
    int dist[vertices], maxdist[vertices];
    int min = 999999;
    //Atrod katrai virsotnei lielako attalumu
    for (int i=0; i<vertices; i++) {
        maxdist[i] = BreadthFirstSearchForMaxDist(adj, i, vertices, dist);
        if (maxdist[i] < min) min = maxdist[i];
    }
    fout << min << endl;
    bool printed = false;
    for (int i=0; i<vertices; i++) {
        //Parbauda vai nav izprintets jau
        if(maxdist[i] == min) {
            if (printed) fout << " ";
            fout << i+1;
            printed = true;
        }
    }
}


int main() {
    int v = 0;
    int source = 1,destination = 1;
    fstream fin("serveris.in", ios::in);
    fstream fout("serveris.out", ios::out);
    //NOLASA NO FAILA CIK BUS VIRSOTNU
    fin >> v;
    // IZVEIDO INCIDENCES SARAKSTU
    List adj[v];
    // LASA NO FAILA VIRSOTNES;
    do {
        fin >> source;
        fin >> destination;
        if (source == 0 and destination == 0) break;
        add_edge(adj, source-1, destination-1);
    } while (1);
    //VEIC APSTRADI
    printServer(adj,v, fout);

    fin.close();
    fout.close();

}
