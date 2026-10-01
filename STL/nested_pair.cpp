#include <iostream>
using namespace std;

int main()
{
    pair<string, pair<int, float>> student;

    cin >> student.first;
    cin >> student.second.first;
    cin >> student.second.second;

    cout << "Name: " << student.first << endl;
    cout << "ID: " << student.second.first << endl;
    cout << "CGPA: " << student.second.second;

    return 0;
}
