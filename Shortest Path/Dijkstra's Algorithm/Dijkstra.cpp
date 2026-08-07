#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;

    cout<<"Enter number of vertices : "<<endl;
    cin>>n;

    cout<<"Enter number of edges : "<<endl;
    cin>>e;

    vector<vector<pair<int,int>>>graph(n);

    cout<<"Enter the edges and weights : "<<endl;

    for(int i=0;i<e;i++)
    {
        int u,v,w;

        cin>>u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int source;

    cout<<"Enter source vertex : "<<endl;
    cin>>source;

    vector<int>distance(n,INT_MAX);
    vector<bool>visited(n,false);

    distance[source]=0;

    for(int i=0;i<n;i++)
    {
        int current=-1;
        int minimum=INT_MAX;

        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && distance[j]<minimum)
            {
                minimum=distance[j];
                current=j;
            }
        }

        if(current==-1)
        {
            break;
        }

        visited[current]=true;

        for(int j=0;j<graph[current].size();j++)
        {
            int next=graph[current][j].first;
            int weight=graph[current][j].second;

            if(visited[next]==false)
            {
                if(distance[current]+weight<distance[next])
                {
                    distance[next]=distance[current]+weight;
                }
            }
        }
    }

    cout<<endl;

    cout<<"Shortest distances from source "<<source<<" : "<<endl;

    for(int i=0;i<n;i++)
    {
        if(distance[i]==INT_MAX)
        {
            cout<<source<<" to "<<i<<" = Not reachable"<<endl;
        }
        else
        {
            cout<<source<<" to "<<i<<" = "<<distance[i]<<endl;
        }
    }

    return 0;
}
