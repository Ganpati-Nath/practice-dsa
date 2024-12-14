#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>
class Graph {
    public:
        unordered_map<int, list<pair<T, T>>> adjList;
        void addEdge(T source, T destination, T weight, bool direction) {
            adjList[source].push_back({destination, weight});
            if(direction == 0) {
                adjList[destination].push_back({source, weight});
            }
        }
        void printADJ() {
            for(auto node : adjList) {
                cout << node.first << " -> ";
                for(auto neigh : node.second) {
                    cout << "( " << neigh.first << ", " << neigh.second << "), ";
                }
                cout << endl;
            }
        }
};
int main() {
    Graph<int> g;
    g.addEdge(0, 1, 5, 0);
    g.addEdge(1, 2, 8, 0);
    g.addEdge(2, 0, 6, 0);
    cout << endl;
    g.printADJ();
    return 0;
}