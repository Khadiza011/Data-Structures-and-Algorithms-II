#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int main()
{
    int n, e;

    cin >> n >> e;


    // Edge format:
    // source, destination, cost

    vector<vector<int>> edges;


    for(int i = 0; i < e; i++)
    {
        int u, v, cost;

        cin >> u >> v >> cost;

        edges.push_back({u, v, cost});
    }


    int source, destination, stops;


    cin >> source;
    cin >> destination;
    cin >> stops;



    vector<int> distance(
        n,
        INT_MAX
    );


    distance[source] = 0;



    // Relax edges k+1 times
    for(int i = 0; i <= stops; i++)
    {
        vector<int> temp = distance;


        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];


            if(distance[u] != INT_MAX &&
               distance[u] + cost < temp[v])
            {
                temp[v] = distance[u] + cost;
            }
        }


        distance = temp;
    }



    if(distance[destination] == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << distance[destination];
    }



    return 0;
}
