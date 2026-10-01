#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int row, col;

    cin >> row >> col;


    vector<vector<int>> grid(
        row,
        vector<int>(col)
    );


    // Taking grid input
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }



    vector<vector<int>> dp(
        row,
        vector<int>(col)
    );



    dp[0][0] = grid[0][0];



    // First row
    for(int i = 1; i < col; i++)
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }



    // First column
    for(int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }



    // Fill remaining cells
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            dp[i][j] =
            grid[i][j] +
            min(dp[i-1][j], dp[i][j-1]);
        }
    }



    cout << dp[row-1][col-1];


    return 0;
}
