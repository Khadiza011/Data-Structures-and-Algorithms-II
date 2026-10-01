#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> coins(n);


    // Taking coin values
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }


    int amount;

    cin >> amount;



    // Sort coins in descending order
    sort(
        coins.begin(),
        coins.end(),
        greater<int>()
    );



    int count = 0;



    for(int i = 0; i < n; i++)
    {
        while(amount >= coins[i])
        {
            amount -= coins[i];

            count++;
        }
    }



    if(amount != 0)
    {
        cout << "Not Possible";
    }
    else
    {
        cout << count;
    }



    return 0;
}
