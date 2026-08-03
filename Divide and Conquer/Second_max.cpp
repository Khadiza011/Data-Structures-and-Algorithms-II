#include <iostream>
#include <vector>
using namespace std;

int comparisons = 0;

// Return pair: {max, second max}
vector<int> second_max(vector<int>& arr, int low, int high) {

    vector<int> result(2);

    // Base case: single element
    if (low == high) {
        result[0] = arr[low];     // max
        result[1] = arr[low];     // second max (same for now)
        return result;
    }

    // Base case: two elements
    if (low + 1 == high) {
        comparisons++;
        if (arr[low] > arr[high]) {
            result[0] = arr[low];
            result[1] = arr[high];
        } else {
            result[0] = arr[high];
            result[1] = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    vector<int> left = second_max(arr, low, mid);
    vector<int> right = second_max(arr, mid + 1, high);

    vector<int> result_final(2);

    // Compare maximums
    comparisons++;
    if (left[0] > right[0]) {
        result_final[0] = left[0];

        // Second max candidate
        comparisons++;
        result_final[1] = max(left[1], right[0]);
    } else {
        result_final[0] = right[0];

        // Second max candidate
        comparisons++;
        result_final[1] = max(right[1], left[0]);
    }

    return result_final;
}

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res = second_max(arr, 0, arr.size() - 1);

    cout << "Maximum: " << res[0] << endl;
    cout << "Second Maximum: " << res[1] << endl;
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
