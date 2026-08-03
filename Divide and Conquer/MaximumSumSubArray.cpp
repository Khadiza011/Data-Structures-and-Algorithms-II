#include <iostream>
#include <vector>

using namespace std;

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

int myMax3(int a, int b, int c) {
    return myMax(myMax(a, b), c);
}

int maxCrossingSum(vector<int> &arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = -1000000;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        left_sum = myMax(left_sum, sum);
    }

    sum = 0;
    int right_sum = -1000000;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        right_sum = myMax(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSubarraySum(vector<int> &arr, int left, int right) {

    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;

    int left_sum = maxSubarraySum(arr, left, mid);
    int right_sum = maxSubarraySum(arr, mid + 1, right);
    int cross_sum = maxCrossingSum(arr, left, mid, right);

    return myMax3(left_sum, right_sum, cross_sum);
}

int main() {

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, 0, n - 1);

    cout << "\nMaximum Subarray Sum: " << result << endl;

    return 0;
}
