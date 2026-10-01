#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int main()
{
    int n, e;

    cin >> n >> e;


    // {destination, cost, time}
    vector<vector<vector<int>>> graph(n);


    for(int i = 0; i < e; i++)
    {
        int u, v, cost, time;

        cin >> u >> v >> cost >> time;


        graph[u].push_back({v, cost, time});
        graph[v].push_back({u, cost, time});
    }


    int source, destination, maxTime;


    cin >> source;
    cin >> destination;
    cin >> maxTime;



    // Store minimum cost for each node at different time
    vector<vector<int>> distance(
        n,
        vector<int>(maxTime + 1, INT_MAX)
    );


    // {cost, node, time}
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;



    distance[source][0] = 0;

    pq.push({0, source, 0});



    while(!pq.empty())
    {
        int currentCost = pq.top()[0];
        int node = pq.top()[1];
        int currentTime = pq.top()[2];

        pq.pop();



        if(node == destination)
        {
            cout << currentCost;
            return 0;
        }



        for(auto edge : graph[node])
        {
            int next = edge[0];
            int cost = edge[1];
            int time = edge[2];


            int newTime = currentTime + time;

            int newCost = currentCost + cost;



            // Check time limit
            if(newTime <= maxTime)
            {

                if(newCost < distance[next][newTime])
                {
                    distance[next][newTime] = newCost;


                    pq.push(
                        {
                            newCost,
                            next,
                            newTime
                        }
                    );
                }
            }
        }
    }



    cout << "-1";


    return 0;
}
