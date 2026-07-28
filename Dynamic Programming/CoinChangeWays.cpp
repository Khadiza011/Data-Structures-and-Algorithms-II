#include<iostream>

using namespace std;

int main(){

    int n;

    cout << "Enter the number of coin denominations: ";
    cin >> n;

    int coins[n];

    cout << "Enter the coin denominations: ";
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int amount;

    cout << "Enter the target amount: ";
    cin >> amount;

    int dp[amount + 1];

    for(int i = 0; i <= amount; i++){
        dp[i] = 0;
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= amount; j++){
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    cout << "WAYS: " << dp[amount];

    return 0;
}
