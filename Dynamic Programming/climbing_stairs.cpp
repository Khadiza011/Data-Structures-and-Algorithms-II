#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;

    cin >> n;


    if(n == 0 || n == 1)
    {
        cout << 1;
        return 0;
    }



    vector<int> dp(n + 1);



    // Base cases
    dp[0] = 1;
    dp[1] = 1;



    // Calculate number of ways
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }



    cout << dp[n];


    return 0;
}
