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

    cout << "Size: " << v.size() << endl;

    // Remove last element
    v.pop_back();

    cout << "After removing last element:" << endl;

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
