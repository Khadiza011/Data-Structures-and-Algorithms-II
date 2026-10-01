#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int players, coaches;


    cin >> players;


    vector<int> playerSkill(players);


    // Taking player skills
    for(int i = 0; i < players; i++)
    {
        cin >> playerSkill[i];
    }


    cin >> coaches;


    vector<int> coachSkill(coaches);


    // Taking coach requirements
    for(int i = 0; i < coaches; i++)
    {
        cin >> coachSkill[i];
    }



    // Sort both arrays
    sort(playerSkill.begin(), playerSkill.end());

    sort(coachSkill.begin(), coachSkill.end());



    int i = 0;
    int j = 0;

    int matches = 0;



    while(i < players && j < coaches)
    {
        if(playerSkill[i] >= coachSkill[j])
        {
            // Player can match with coach
            matches++;

            i++;
            j++;
        }
        else
        {
            // Need a stronger player
            i++;
        }
    }



    cout << matches;


    return 0;
}
