#include <iostream>
#include <vector>
#include <string>

using namespace std;

int comparison = 0;

// Function to find minimum and maximum score in a single department
vector<int> find_max_min(vector<int>& score, int low, int high) {

    vector<int> result(2);

    // Base Case: Only one element
    if (low == high) {
        comparison++;
        result[0] = score[low];
        result[1] = score[low];
        return result;
    }

    // Base Case: Two elements
    if (low + 1 == high) {
        comparison++;
        if (score[low] < score[high]) {
            result[0] = score[low];
            result[1] = score[high];
        } else {
            result[0] = score[high];
            result[1] = score[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    vector<int> left = find_max_min(score, low, mid);
    vector<int> right = find_max_min(score, mid + 1, high);

    comparison++;
    result[0] = min(left[0], right[0]);

    comparison++;
    result[1] = max(left[1], right[1]);

    return result;
}

// Function to find overall minimum and maximum among all departments
vector<int> final_max_min(vector<vector<int>>& dept, int low, int high) {

    vector<int> result(4); // {min, max, minDept, maxDept}

    if (low == high) {
        vector<int> max_min = find_max_min(dept[low], 0, dept[low].size() - 1);

        result[0] = max_min[0];
        result[1] = max_min[1];
        result[2] = low;
        result[3] = low;

        return result;
    }

    int mid = (low + high) / 2;

    vector<int> left = final_max_min(dept, low, mid);
    vector<int> right = final_max_min(dept, mid + 1, high);

    comparison++;
    if (left[0] < right[0]) {
        result[0] = left[0];
        result[2] = left[2];
    } else {
        result[0] = right[0];
        result[2] = right[2];
    }

    comparison++;
    if (left[1] > right[1]) {
        result[1] = left[1];
        result[3] = left[3];
    } else {
        result[1] = right[1];
        result[3] = right[3];
    }

    return result;
}

int main() {

    int departments, students;

    cout << "Enter the number of departments: ";
    cin >> departments;

    cout << "Enter the number of students in each department: ";
    cin >> students;

    vector<vector<int>> departmentScores(departments);
    vector<string> departmentNames(departments);

    for (int i = 0; i < departments; i++) {
        cout << "\nEnter name of Department " << i + 1 << ": ";
        cin >> departmentNames[i];

        cout << "Enter " << students << " student scores: ";

        departmentScores[i].resize(students);

        for (int j = 0; j < students; j++) {
            cin >> departmentScores[i][j];
        }
    }

    vector<int> result = final_max_min(departmentScores, 0, departments - 1);

    cout << "\nHighest Score: " << result[1]
         << " (Department: " << departmentNames[result[3]] << ")" << endl;

    cout << "Lowest Score: " << result[0]
         << " (Department: " << departmentNames[result[2]] << ")" << endl;

    cout << "Total Comparisons: " << comparison << endl;

    return 0;
}
