#include<iostream>
#include<vector>
using namespace std;

int main() {
    int total_nodes;
    cout << "Enter the total no. of nodes : ";
    cin >> total_nodes;
    vector<vector<int>> adjMAT(total_nodes, vector<int>(total_nodes, 0));
    int total_edges;
    cout << "Enter the total no. of edges : ";
    cin >> total_edges;
    for(int idx = 0; idx < total_edges; ++idx) {
        int source, destination;
        cin >> source >> destination;
        adjMAT[source][destination] = 1;
    }
    cout << "Printing ADJACENCY MATRIX..." << endl;
    for(int idx = 0; idx < total_nodes; ++idx) {
        for(int jdx = 0; jdx < total_nodes; ++jdx) {
            cout << adjMAT[idx][jdx] << "  ";
        }
        cout << endl;
    }
    return 0;
}