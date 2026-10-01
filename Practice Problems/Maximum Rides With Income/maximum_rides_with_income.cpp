#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Ride
{
    int start;
    int end;
    int income;
};


// Sort rides according to ending time
bool compare(Ride a, Ride b)
{
    return a.end < b.end;
}


// Find previous non-overlapping ride
int findPreviousRide(vector<Ride>& rides, int index)
{
    int low = 0;
    int high = index - 1;


    while(low <= high)
    {
        int mid = (low + high) / 2;


        if(rides[mid].end <= rides[index].start)
        {
            if(mid + 1 < index &&
               rides[mid + 1].end <= rides[index].start)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            high = mid - 1;
        }
    }


    return -1;
}



int main()
{
    int n;

    cin >> n;


    vector<Ride> rides(n);



    // Taking ride information
    for(int i = 0; i < n; i++)
    {
        cin >> rides[i].start
            >> rides[i].end
            >> rides[i].income;
    }



    sort(
        rides.begin(),
        rides.end(),
        compare
    );



    vector<int> dp(n);



    dp[0] = rides[0].income;



    for(int i = 1; i < n; i++)
    {
        int includeIncome = rides[i].income;


        int previous = findPreviousRide(
            rides,
            i
        );


        if(previous != -1)
        {
            includeIncome += dp[previous];
        }


        int excludeIncome = dp[i-1];


        dp[i] = max(
            includeIncome,
            excludeIncome
        );
    }



    cout << dp[n-1];


    return 0;
}
