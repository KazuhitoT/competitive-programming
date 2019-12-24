#include "dijkstra.hpp"
#include <iostream>

int main(){

    V = 3;

    G[0].push_back(edge(1, 1));
    G[0].push_back(edge(2, 6));

    G[1].push_back(edge(2, 3));

    G[2].push_back(edge(0, 3));
    G[2].push_back(edge(1, 4));

    dijkstra(0);

    for(int i = 0; i < V; ++i){
       cout << i << " " << d[i] << endl; 
    }

    get_path(1);
    vector<int> path1 = get_path(1);
    cout << " shortest path 1: ";
    for (int i = 0; i < path1.size(); ++i) {
        cout << path1[i] << " ";
    }
    cout << endl;

    get_path(2);
    vector<int> path2 = get_path(2);
    cout << " shortest path 2: ";
    for (int i = 0; i < path2.size(); ++i) {
        cout << path2[i] << " ";
    }
    cout << endl;

    return 0;
}
