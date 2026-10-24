#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countBulbasaur(string str)
{
    int B = 0, u = 0, l = 0;
    int b = 0, a = 0, s = 0, r = 0;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'B')
            B++;
        else if(str[i] == 'u')
            u++;
        else if(str[i] == 'l')
            l++;
        else if(str[i] == 'b')
            b++;
        else if(str[i] == 'a')
            a++;
        else if(str[i] == 's')
            s++;
        else if(str[i] == 'r')
            r++;
    }

    return min({B, u / 2, l, b, a / 2, s, r});
}

int main()
{
    string str;
    cin >> str;

    cout << countBulbasaur(str);

    return 0;
}
