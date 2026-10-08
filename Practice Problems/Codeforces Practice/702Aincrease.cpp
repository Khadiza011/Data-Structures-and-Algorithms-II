#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumLength(vector<int>& arr, int n)
{
    int current = 1;
    int maximum = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[i - 1])
        {
            current++;
        }
        else
        {
            current = 1;
        }

        maximum = max(maximum, current);
    }

    return maximum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maximumLength(arr, n);

    return 0;
}
