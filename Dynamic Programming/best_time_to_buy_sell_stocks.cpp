#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> price(n);


    // Taking stock prices input
    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }


    int minimumPrice = price[0];

    int maximumProfit = 0;



    for(int i = 1; i < n; i++)
    {
        // Update minimum buying price
        minimumPrice = min(minimumPrice, price[i]);


        // Calculate possible profit
        int profit = price[i] - minimumPrice;


        // Update maximum profit
        maximumProfit = max(maximumProfit, profit);
    }



    cout << maximumProfit;


    return 0;
}
