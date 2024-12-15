#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<int>> adjList;
        void addEdge(int src, int dest, bool direction) {
            // direction == 0 --> Undirected Graph...
            // vice versa for Directed Graph...
            adjList[src].push_back(dest);
            if(direction == 0) {
                adjList[dest].push_back(src);
            }
        }
        void printADJ() {
            for(auto node : adjList) {
                cout << node.first << " -> { ";
                for(auto neigh : node.second) {
                    cout << neigh << ", ";
                }
                cout << "}";
                cout << endl;
            }
        }
        void bfsTraversal(int src, unordered_map<int, bool>& vis) {
            queue<int> q;
            q.push(src);
            vis[src] = true;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node << "  ";
                for(auto neigh : adjList[node]) {
                    if(!vis[neigh]) {
                        q.push(neigh);
                        vis[neigh] = true;
                    }
                }
            }
        }
        bool cyclebfsTraversal(int src, unordered_map<int, bool>& vis) {
            queue<int> q;
            unordered_map<int, int> parent;
            q.push(src);
            vis[src] = true;
            parent[src] = -1;
            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();
                for(auto nbr : adjList[frontNode]) {
                    if(!vis[frontNode]) {
                        q.push(nbr);
                        vis[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    if(vis[frontNode] && nbr != parent[frontNode]) {
                        return true;
                    }
                }
            }
            return false;
        }
};
int main() {
    int total_nodes;
    cout << "Enter the no. of total nodes : ";
    cin >> total_nodes;
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 4, 0);
    g.addEdge(2, 1, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 0);
    // cout << "Printing ADJACENCY LIST..." << endl;
    // g.printADJ();
    // cout << "BFS..." << endl;
    bool ans = false;
    unordered_map<int, bool> visited;
    for(int i = 0; i < total_nodes; ++i) {
        if(!visited[i]) {
            ans = g.cyclebfsTraversal(i, visited);
            if(ans) break;
        }
    }
    if(ans) cout << "Cycle present h bhailog..." << endl;
    else cout << "Nhi h !..." << endl;
    return 0;
}