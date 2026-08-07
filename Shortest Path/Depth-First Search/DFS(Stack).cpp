#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;

    cout<<"Enter number of vertices : "<<endl;
    cin>>n;

    cout<<"Enter number of edges : "<<endl;
    cin>>e;

    vector<vector<int>>graph(n);

    cout<<"Enter the edges : "<<endl;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source;

    cout<<"Enter source vertex : "<<endl;
    cin>>source;

    vector<int>distance(n,INT_MAX);

    stack<int>st;

    distance[source]=0;
    st.push(source);

    while(!st.empty())
    {
        int current=st.top();
        st.pop();

        for(int i=0;i<graph[current].size();i++)
        {
            int next=graph[current][i];

            if(distance[next]>distance[current]+1)
            {
                distance[next]=distance[current]+1;
                st.push(next);
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
