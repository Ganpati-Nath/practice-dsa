#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
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
        void dfsTraversal(int src, unordered_map<int, bool>& vis) {
            cout << src << "  ";
            vis[src] = true;
            for(auto neigh : adjList[src]) {
                if(!vis[neigh]) {
                    dfsTraversal(neigh, vis);
                }
            }
        }
        void topologicalSortDFS(int src, unordered_map<int, bool>& vis, stack<int>& st) {
            vis[src] = true;
            for(auto neigh : adjList[src]) {
                if(!vis[neigh]) {
                    topologicalSortDFS(neigh, vis, st);
                }
            }
            st.push(src);
        }
};
int main() {
    int total_nodes;
    cout << "Enter the no. of total nodes : ";
    cin >> total_nodes;
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    cout << "Printing ADJACENCY LIST..." << endl;
    g.printADJ();
    cout << "BFS..." << endl;
    unordered_map<int, bool> visited1;
    for(int i = 0; i < total_nodes; ++i) {
        if(!visited1[i]) {
            g.bfsTraversal(i, visited1);
        }
    }
    cout << endl;
    cout << "DFS..." << endl;
    unordered_map<int, bool> visited2;
    for(int i = 0; i < total_nodes; ++i) {
        if(!visited2[i]) {
            g.dfsTraversal(i, visited2);
        }
    }
    cout << endl;
    cout << "TOPOSort..." << endl;
    unordered_map<int, bool> visited3;
    stack<int> st;
    for(int i = 0; i < total_nodes; ++i) {
        if(!visited3[i]) {
            g.topologicalSortDFS(i, visited3, st);
        }
    }
    while(!st.empty()){
        cout << st.top() << "  ";
        st.pop();
    }
    return 0;
}