#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, string> student;

    cin >> student.first;
    cin >> student.second;

    cout << "ID: " << student.first << endl;
    cout << "Name: " << student.second;

    return 0;
}
