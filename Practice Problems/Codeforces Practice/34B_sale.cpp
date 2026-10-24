#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    int money = 0;

    // Take at most m negative-priced TVs
    for(int i = 0; i < m; i++)
    {
        if(prices[i] < 0)
        {
            money -= prices[i];
        }
    }

    cout << money;

    return 0;
}
