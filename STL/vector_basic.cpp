#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    int n;

    cin >> n;

    // Taking vector input
    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        numbers.push_back(value);
    }

    // Display vector elements
    for(int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
