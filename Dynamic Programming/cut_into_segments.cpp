#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n, x, y, z;

    cin >> n;
    cin >> x >> y >> z;


    vector<int> dp(n + 1, -1);


    // Base case
    dp[0] = 0;



    for(int i = 1; i <= n; i++)
    {
        if(i >= x && dp[i-x] != -1)
        {
            dp[i] = max(dp[i], dp[i-x] + 1);
        }


        if(i >= y && dp[i-y] != -1)
        {
            dp[i] = max(dp[i], dp[i-y] + 1);
        }


        if(i >= z && dp[i-z] != -1)
        {
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }



    if(dp[n] == -1)
    {
        cout << 0;
    }
    else
    {
        cout << dp[n];
    }


    return 0;
}
