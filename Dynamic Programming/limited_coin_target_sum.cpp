#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n, target;


    cin >> n;


    vector<int> coins(n);


    // Taking coin values
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }


    cin >> target;



    vector<int> dp(
        target + 1,
        0
    );


    // One way to make sum 0
    dp[0] = 1;



    // Process each coin
    for(int i = 0; i < n; i++)
    {
        for(int sum = target; sum >= coins[i]; sum--)
        {
            dp[sum] += dp[sum - coins[i]];
        }
    }



    cout << dp[target];


    return 0;
}
