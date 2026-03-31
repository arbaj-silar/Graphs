#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdList() {
        for(int i=0; i<V; i++) {
            cout<<i<<" : ";
            for(int neigh: l[i]) {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    void dfsHelper(int u, vector<bool>& vis) {
        cout<<u<<" ";
        vis[u] = true;

        for(int v: l[u]) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            } 
        }
    }

    void dfs() {
        int src = 0;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis);
            }
        }
        cout<<endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1); // 0->1
    g.addEdge(1, 2); // 1->2
    g.addEdge(1, 3); // 1->3
    g.addEdge(2, 4); // 2->4

    g.printAdList();
    cout<<"DFS : ";
    g.dfs();
    return 0;
}