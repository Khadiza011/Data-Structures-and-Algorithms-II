#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    vector<vector<pair<int,int>>> graph(nodes);


    // Input graph
    for(int i = 0; i < edges; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});   // For undirected graph
    }


    int source;

    cin >> source;


    vector<int> distance(nodes, INF);

    // Min heap: {distance, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;


    distance[source] = 0;

    pq.push({0, source});


    while(!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();


        // Check all connected nodes
        for(auto edge : graph[currentNode])
        {
            int nextNode = edge.first;
            int weight = edge.second;


            // Relaxation
            if(currentDistance + weight < distance[nextNode])
            {
                distance[nextNode] = currentDistance + weight;

                pq.push({distance[nextNode], nextNode});
            }
        }
    }


    // Print shortest distance
    for(int i = 0; i < nodes; i++)
    {
        if(distance[i] == INF)
        {
            cout << "Node " << i << " : Not Reachable\n";
        }
        else
        {
            cout << "Node " << i << " : " << distance[i] << endl;
        }
    }


    return 0;
}
