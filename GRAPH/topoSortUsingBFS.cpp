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
        void topoSortUsingBFS(int n, vector<int>& ans) {
            queue<int> q;
            unordered_map<int, int> indegree;

            for(auto i : adjList){
                int src = i.first;
                for(auto nbr : i.second){
                    indegree[nbr]++;
                }
            }
            for(int i = 0; i < n; ++i){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int fNode = q.front();
                q.pop();
                ans.push_back(fNode);
                for(auto nbr: adjList[fNode]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
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
    g.addEdge(3, 1, 1);
    // g.addEdge(3, 7, 1);
    // g.addEdge(6, 7, 1);
    // g.addEdge(7, 0, 1);
    // g.addEdge(7, 1, 1);

    vector<int> ans;
    
    g.topoSortUsingBFS(total_nodes, ans);
    for(auto i : ans){
        cout << i << ",  ";
    }
    if(ans.size() == total_nodes){
        cout << "valid topoSort h..." << endl;
    }
    else{
        cout << "cycle present h..." << endl;
    }
    return 0;
}