#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> cost(n);


    // Taking cost input
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }



    vector<int> dp(n);


    dp[0] = cost[0];
    dp[1] = cost[1];



    // Calculate minimum cost for each step
    for(int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }



    // We can start from step 0 or step 1
    cout << min(dp[n-1], dp[n-2]);


    return 0;
}
