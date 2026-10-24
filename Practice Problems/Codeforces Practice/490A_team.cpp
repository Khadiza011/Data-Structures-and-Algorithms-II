#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> programming;
    vector<int> math;
    vector<int> physicalEducation;

    for(int i = 1; i <= n; i++)
    {
        int skill;
        cin >> skill;

        if(skill == 1)
        {
            programming.push_back(i);
        }
        else if(skill == 2)
        {
            math.push_back(i);
        }
        else if(skill == 3)
        {
            physicalEducation.push_back(i);
        }
    }

    int teams = min({
        programming.size(),
        math.size(),
        physicalEducation.size()
    });

    cout << teams << endl;

    for(int i = 0; i < teams; i++)
    {
        cout << programming[i] << " "
             << math[i] << " "
             << physicalEducation[i] << endl;
    }

    return 0;
}
