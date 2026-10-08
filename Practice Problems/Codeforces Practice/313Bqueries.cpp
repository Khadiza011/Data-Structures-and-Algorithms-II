#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int n = str.size();

    vector<int> prefix(n, 0);

    // Count equal adjacent characters
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1];

        if(str[i] == str[i - 1])
        {
            prefix[i]++;
        }
    }

    int queries;
    cin >> queries;

    while(queries--)
    {
        int left, right;
        cin >> left >> right;

        cout << prefix[right - 1] - prefix[left - 1] << endl;
    }

    return 0;
}
