#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    // Insert 100 at first position
    v.insert(v.begin(), 100);

    // Delete first element
    v.erase(v.begin());

    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
