#include<iostream>
#include<list>
#include<stack>
#include<queue>
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

    void topologicalSort() {
        vector<int> ans;

        vector<int> inDegree(V, 0);
        for(int u = 0; u<V; u++) {
            for(int v : l[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(q.size()>0) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(int i: l[curr]) {
                inDegree[i]--;
                if(inDegree[i] == 0) {
                    q.push(i);
                }
            }

        }
        for(int val: ans) {
            cout<<val<<" ";
        }
        cout<<endl;
    }

};

int main() {
    Graph g(6);

    g.addEdge(3, 1); 
    g.addEdge(2, 3); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(5, 0); 
    g.addEdge(5, 3); 

    g.topologicalSort();
    return 0;
}