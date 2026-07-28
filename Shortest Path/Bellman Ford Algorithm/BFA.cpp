#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int V,E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
    }

    int source = 1;

    vector<int> dist(V+1,1e9);
    vector<int> parent(V+1,-1);

    dist[source] = 0;

    // Bellman-Ford
    for(int i=1;i<=V-1;i++){

        for(auto edge : edges){

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != 1e9 &&
               dist[u] + w < dist[v]){

                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    cout << "Shortest Cost = "
         << dist[V] << endl;

    vector<int> path;

    int current = V;

    while(current != -1){
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(),path.end());

    cout << "\nPath:\n";

    for(int node : path)
        cout << node << " ";

    return 0;
}
