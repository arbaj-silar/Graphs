#include<iostream>
#include<list>
#include<vector>
#include<queue>
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

    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while(q.size()>0) {
            int u = q.front();
            q.pop();

            cout<<u<<" ";
            for(int v: l[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
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
    g.addEdge(2, 3); // 2->3
    g.addEdge(2, 4); // 2->4

    g.printAdList();

    g.bfs();
    return 0;
}