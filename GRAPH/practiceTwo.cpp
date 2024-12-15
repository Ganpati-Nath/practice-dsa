#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<pair<int, int>>> adjList;
        void addEdge(int src, int dest, int weight, bool direction) {
            // direction == 0 --> Undirected Graph...
            // vice versa for Directed Graph...
            adjList[src].push_back({dest, weight});
            if(direction == 0) {
                adjList[dest].push_back({src, weight});
            }
        }
        void printADJ() {
            for(auto node : adjList) {
                cout << node.first << " -> { ";
                for(auto neigh : node.second) {
                    cout << "(" << neigh.first << ", " << neigh.second << "), ";
                }
                cout << "}";
                cout << endl;
            }
        }
};
int main() {
    Graph g;
    g.addEdge(0, 1, 6, 1);
    g.addEdge(0, 4, 4, 1);
    g.addEdge(2, 1, 5, 1);
    g.addEdge(2, 3, 2, 1);
    g.addEdge(3, 0, 7, 1);
    cout << "Printing ADJACENCY LIST..." << endl;
    g.printADJ();
    return 0;
}