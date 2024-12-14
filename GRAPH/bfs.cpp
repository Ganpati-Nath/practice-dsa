#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph {
    public:
        unordered_map<int, list<int>> adjList;
        void addEdge(int source, int destination, bool direction) {
            adjList[source].push_back(destination);
            if(direction == 0) {
                adjList[destination].push_back(source);
            }
        }
        void printADJ() {
            for(auto node : adjList) {
                cout << node.first << " -> ";
                for(auto neigh : node.second) {
                    cout << neigh << ", ";
                }
                cout << endl;
            }
        }
        void bfsTraversal(int src, unordered_map<int, bool>& vis) {
            queue<int> q;
            q.push(src);
            vis[src] = true;
            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();
                cout << frontNode << "  ";
                for(auto neigh : adjList[frontNode]) {
                    if(!vis[neigh]) {
                        q.push(neigh);
                        vis[neigh] = true;
                    }
                }
            }
        }
        void dfsTraversal(int src, unordered_map<int, bool>& vis) {
            cout << src << "  ";
            vis[src] = true;
            for(auto neigh : adjList[src]) {
                if(!vis[neigh]) {
                    dfsTraversal(neigh, vis);
                }
            }
        }
};
int main() {
    Graph g;
    int n = 4;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    // g.addEdge(3, 7, 0);
    // g.addEdge(7, 6, 0);
    // g.addEdge(7, 4, 0);
    cout << endl;
    g.printADJ();
    cout << endl;
    unordered_map<int, bool> vis;
    cout << "BFS..." << endl;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            g.bfsTraversal(i, vis);
        }
    }
    cout << endl;
    unordered_map<int, bool> vis2;
    cout << "DFS..." << endl;
    for(int i = 0; i < n; ++i) {
        if(!vis2[i]) {
            g.dfsTraversal(i, vis2);
        }
    }
    return 0;
}