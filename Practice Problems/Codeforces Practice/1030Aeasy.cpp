#include <iostream>
#include <vector>

using namespace std;

void checkProblem(vector<int>& opinions, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(opinions[i] == 1)
        {
            cout << "HARD";
            return;
        }
    }

    cout << "EASY";
}

int main()
{
    int n;
    cin >> n;

    vector<int> opinions(n);

    for(int i = 0; i < n; i++)
    {
        cin >> opinions[i];
    }

    checkProblem(opinions, n);

    return 0;
}
