#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> arr(n);


    // Taking array input
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }



    if(n == 0)
    {
        cout << 0;
        return 0;
    }


    if(n == 1)
    {
        cout << arr[0];
        return 0;
    }



    vector<int> dp(n);



    // Base cases
    dp[0] = arr[0];

    dp[1] = max(arr[0], arr[1]);



    // Calculate maximum sum
    for(int i = 2; i < n; i++)
    {
        dp[i] = max(
            dp[i-1],
            arr[i] + dp[i-2]
        );
    }



    cout << dp[n-1];


    return 0;
}
