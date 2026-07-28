#include<bits/stdc++.h>

using namespace std;

// helper function
int minKey(vector<int> &key, vector<bool> mstTree){
    int min_value = INT_MAX, min_index = INT_MAX;

    for(int k = 0; k < key.size(); k++){
        if(mstTree[k] == false && key[k] < min_value){
            min_value = key[k];
            min_index = k;
        }
    }
    return min_index;
}

void prims(vector<vector<int>> &graph){
    int vs = graph.size();

    vector<int> parent(vs, INT_MAX);
    vector<int> key(vs, INT_MAX);
    vector<bool> mstTree(vs, false);

    key[0] = 0;
    parent[0] = -1;

    int edges = vs - 1;

    for(int e = 0; e < edges; e++){
        int current_v = minKey(key, mstTree);
        mstTree[current_v] = true;

        for(int v = 0; v < vs; v++){
            if(graph[current_v][v] != 0 && mstTree[v] == false && graph[current_v][v] < key[v]){
                parent[v] = current_v;
                key[v] = graph[current_v][v];
            }
        }
    }

    int sum = 0;

    cout << "Edges\tWeight" << endl;
    for(int i = 1; i < vs; i++){
        cout << parent[i] << "-" << i << "\t" << key[i] << endl;
        sum += key[i];
    }

    cout << "Total COST: " << sum;
}

int main(){

    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));

    cout << "Enter the adjacency matrix:\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cin >> graph[i][j];
        }
    }

    prims(graph);

    return 0;
}
