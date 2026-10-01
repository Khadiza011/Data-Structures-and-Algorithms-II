#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;

    cin >> n;


    vector<double> points(n);


    // Taking points input
    for(int i = 0; i < n; i++)
    {
        cin >> points[i];
    }



    // Sort points
    sort(
        points.begin(),
        points.end()
    );



    int intervals = 0;

    int i = 0;



    while(i < n)
    {
        // Start interval from current point
        double start = points[i];


        intervals++;


        // Cover all points within length 1
        while(i < n && points[i] <= start + 1)
        {
            i++;
        }
    }



    cout << intervals;


    return 0;
}
