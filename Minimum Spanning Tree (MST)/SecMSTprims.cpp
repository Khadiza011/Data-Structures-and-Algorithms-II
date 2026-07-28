int main() {

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<pair<int, int>> mstedge;
    int mstcost = prims(graph, mstedge);

    int secmst = INT_MAX;

    for (auto edge : mstedge) {
        vector<vector<int>> temp = graph;

        int u = edge.first;
        int v = edge.second;

        temp[u][v] = 0;
        temp[v][u] = 0;

        vector<pair<int, int>> dummy;

        int cost = prims(temp, dummy);

        if (cost > mstcost) {
            secmst = min(secmst, cost);
        }
    }

    cout << "second mst : " << secmst << endl;

    return 0;
}
