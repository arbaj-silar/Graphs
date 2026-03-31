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

    bool isCycleDFS(int src, int par, vector<bool>& vis) {
        vis[src] = true;
        list<int> neigh = l[src];

        for(int v: neigh) {
            if(!vis[v]) {
                if(isCycleDFS(v, src, vis)) {
                    return true;
                }
            } else if(v != par) {
                return true;
            }
        }
        return false;
    }

    bool isCycle() {
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleDFS(i, -1, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1); // 0->1
    g.addEdge(1, 2); // 1->2
    g.addEdge(1, 3); // 1->3
    g.addEdge(2, 3); // 2->3
    g.addEdge(2, 4); // 2->4

    g.printAdList();
    cout<<g.isCycle();
    return 0;
}