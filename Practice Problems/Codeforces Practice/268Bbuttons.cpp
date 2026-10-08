#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = n;

    for(int i = 1; i < n; i++)
    {
        count += (n - i) * i;
    }

    cout << count;

    return 0;
}
