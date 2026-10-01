#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> distance(n);
    vector<int> fuel(n);



    // Taking station information
    for(int i = 0; i < n; i++)
    {
        cin >> distance[i];
        cin >> fuel[i];
    }


    int destination;
    int currentFuel;


    cin >> destination;
    cin >> currentFuel;



    priority_queue<int> maxFuel;


    int stops = 0;
    int currentDistance = 0;
    int index = 0;



    while(currentDistance + currentFuel < destination)
    {
        // Add reachable stations
        while(index < n &&
              distance[index] <= currentDistance + currentFuel)
        {
            maxFuel.push(fuel[index]);

            index++;
        }



        // No station available
        if(maxFuel.empty())
        {
            cout << -1;
            return 0;
        }



        // Take maximum fuel
        currentFuel += maxFuel.top();

        maxFuel.pop();


        stops++;
    }



    cout << stops;


    return 0;
}
