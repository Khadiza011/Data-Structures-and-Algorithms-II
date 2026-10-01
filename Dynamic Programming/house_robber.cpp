#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> money(n);


    // Taking house money input
    for(int i = 0; i < n; i++)
    {
        cin >> money[i];
    }



    if(n == 1)
    {
        cout << money[0];
        return 0;
    }



    vector<int> dp(n);



    // Base cases
    dp[0] = money[0];

    dp[1] = max(money[0], money[1]);



    // Calculate maximum robbery amount
    for(int i = 2; i < n; i++)
    {
        dp[i] = max(
            dp[i-1],
            money[i] + dp[i-2]
        );
    }



    cout << dp[n-1];


    return 0;
}
