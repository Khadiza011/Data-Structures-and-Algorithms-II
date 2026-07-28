#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter the coin denominations: ";
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the target amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, 1e9);
    vector<int> chosen(amount + 1, -1);

    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            if(dp[i] > dp[i - coin] + 1){
                dp[i] = dp[i - coin] + 1;
                chosen[i] = coin;
            }
        }
    }

    cout << "Minimum coins needed = " << dp[amount] << endl;

    cout << "Coins used: ";

    int curr = amount;
    while (curr > 0) {
        cout << chosen[curr] << " ";
        curr -= chosen[curr];
    }

    return 0;
}
