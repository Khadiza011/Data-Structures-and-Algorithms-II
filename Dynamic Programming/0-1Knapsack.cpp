#include<iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter the number of items: ";
    cin >> n;

    char item[n];
    int weight[n];
    int value[n];

    for(int i = 0; i < n; i++){
        cout << "Enter item name: ";
        cin >> item[i];

        cout << "Enter weight of item " << item[i] << ": ";
        cin >> weight[i];

        cout << "Enter value of item " << item[i] << ": ";
        cin >> value[i];
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[n+1][capacity+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(weight[i-1] <= j){
                dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << "MAX: " << dp[n][capacity] << endl;

    int i = n, j = capacity;

    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i-1][j]){
            cout << "SELECTED ITEM: " << item[i-1] << endl;
            j = j - weight[i-1];
        }
        i--;
    }

    return 0;
}
