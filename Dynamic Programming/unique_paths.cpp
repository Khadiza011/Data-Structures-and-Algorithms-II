#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int m, n;

    cin >> m >> n;


    vector<vector<int>> dp(
        m,
        vector<int>(n, 1)
    );


    // Fill DP table
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            dp[i][j] =
            dp[i-1][j] + dp[i][j-1];
        }
    }


    cout << dp[m-1][n-1];


    return 0;
}
