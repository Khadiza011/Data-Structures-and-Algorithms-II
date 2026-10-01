#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n, m;

    cin >> n >> m;


    vector<int> height(n);


    // Taking height input
    for(int i = 0; i < n; i++)
    {
        cin >> height[i];
    }


    // Sort heights
    sort(height.begin(), height.end());


    int minimumDifference = INT_MAX;


    // Check every group of M students
    for(int i = 0; i + m - 1 < n; i++)
    {
        int difference = height[i + m - 1] - height[i];


        minimumDifference = min(
            minimumDifference,
            difference
        );
    }



    cout << minimumDifference;


    return 0;
}
