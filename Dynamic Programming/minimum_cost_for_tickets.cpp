#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<int> days(n);


    // Taking travel days input
    for(int i = 0; i < n; i++)
    {
        cin >> days[i];
    }


    int cost1, cost7, cost30;


    cin >> cost1 >> cost7 >> cost30;



    vector<int> dp(days[n-1] + 1, 0);



    int index = 0;


    for(int day = 1; day <= days[n-1]; day++)
    {
        // If it is not a travelling day
        if(index < n && day != days[index])
        {
            dp[day] = dp[day-1];
        }

        else
        {
            int oneDay = dp[max(0, day-1)] + cost1;


            int sevenDay = dp[max(0, day-7)] + cost7;


            int thirtyDay = dp[max(0, day-30)] + cost30;



            dp[day] = min(
                oneDay,
                min(sevenDay, thirtyDay)
            );


            index++;
        }
    }


    cout << dp[days[n-1]];


    return 0;
}
