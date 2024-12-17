#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

class Graph {
    public:
        // create an adjacency list... node -> {nbr1, nbr2, nbr3,...}... so-on...
        unordered_map<int, list<int>> adjList;

        void addEdge(int srcNode, int destNode, bool direction) {
            // assumption...
            // 0 --> Undirected...
            // 1 --> Directed...

            // always ---> src -> dest (possible)...
            adjList[srcNode].push_back(destNode);

            // for Undirected...
            if(direction == 0) {

                // in the case of Undirected vice-versa is also possible...
                adjList[destNode].push_back(srcNode);
            }
        }

        void printADJ() {
            for(auto &node : adjList) {
                cout << node.first << " -> {";
                for(auto &nbr : node.second) {
                    cout << nbr << " , ";
                }
                cout << "}";
                cout << endl;
            }
        }

        void topoLogicalSortUsingDFS(int src, unordered_map<int, bool>& visited, stack<int>& st) {

            // intial steps...
            visited[src] = true;

            for(auto &nbr : adjList[src]) {

                // if not marked...
                if(!visited[nbr]) {
                    topoLogicalSortUsingDFS(nbr, visited, st);
                }
            }
            st.push(src);
        }
};

int main() {

    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 7, 1);

    cout << "Printing ADJ List..." << endl;
    g.printADJ();

    return 0;
}