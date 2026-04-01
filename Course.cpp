#include<iostream>
#include<list>
#include<stack>
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

    bool isCycle(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& edges) {
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {
                if(!vis[v]) {
                    if(isCycle(v, vis, recPath, edges)) return true;
                    else if(recPath[v]) {
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& edges) {
        vis[src] = true;

        for(int i=0; i<edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {
                if(!vis[v]) {
                    topoSort(v, vis, s, edges);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(isCycle(i, vis, recPath, edges)) {
                    return ans;
                }
            }
        }

        stack<int> s;
        vis.assign(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topoSort(i, vis, s, edges);
            }
        }

        while(s.size()>0) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
int main() {
    Graph g(4);
    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> ans = g.findOrder(n, edges);
    for(int val: ans) {
        cout<<val<<" ";
    }
    return 0;
}