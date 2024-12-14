#include<iostream>
#include<vector>
using namespace std;

int main() {
    int totalNodes;
    cout << "Enter the number of NODES : ";
    cin >> totalNodes;
    vector<vector<int>> adj(totalNodes, vector<int>(totalNodes, 0));
    int totalEdges;
    cout << "Enter the number of EDGES : ";
    cin >> totalEdges;
    for(int idx = 0; idx < totalEdges; ++idx) {
        int initialNode, finalNode;
        cin >> initialNode >> finalNode;
        adj[initialNode][finalNode] = 1;
    }
    for(int idx = 0; idx < totalNodes; ++idx) {
        for(int jdx = 0; jdx < totalNodes; ++jdx) {
            cout << adj[idx][jdx] << "  ";
        }
        cout << endl;
    }
    return 0;
}