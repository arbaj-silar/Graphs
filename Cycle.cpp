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
    }

    bool isCycleDirDFS(int curr, vector<bool>& vis, vector<bool>& recPath) {
        vis[curr] = true;
        recPath[curr] = true;

        for(int v: l[curr]) {
            if(!vis[v] && isCycleDirDFS(v, vis, recPath)) return true;
            else if(recPath[v]) return true;
        }

        recPath[curr] = false;
        return false;
    }

    bool isCycle() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleDirDFS(i, vis, recPath)) return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g(4);

    g.addEdge(1, 0); // 1->0
    g.addEdge(0, 2); // 0->2
    g.addEdge(2, 3); // 2->3
    g.addEdge(3, 0); // 3->0

    cout<<g.isCycle();
    return 0;
}