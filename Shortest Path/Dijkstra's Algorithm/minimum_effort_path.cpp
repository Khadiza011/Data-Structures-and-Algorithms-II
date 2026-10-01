#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int main()
{
    int rows, cols;

    cin >> rows >> cols;


    vector<vector<int>> height(rows, vector<int>(cols));


    // Taking grid input
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> height[i][j];
        }
    }


    vector<vector<int>> effort(
        rows,
        vector<int>(cols, INT_MAX)
    );


    // {effort, row, column}
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;


    effort[0][0] = 0;

    pq.push({0, 0, 0});


    int direction[4][2] =
    {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };


    while(!pq.empty())
    {
        int currentEffort = pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];

        pq.pop();


        // Destination reached
        if(r == rows-1 && c == cols-1)
        {
            cout << currentEffort;
            return 0;
        }


        for(int i = 0; i < 4; i++)
        {
            int newRow = r + direction[i][0];
            int newCol = c + direction[i][1];


            if(newRow >= 0 && newRow < rows &&
               newCol >= 0 && newCol < cols)
            {

                int difference =
                abs(height[r][c] - height[newRow][newCol]);


                int newEffort =
                max(currentEffort, difference);



                if(newEffort < effort[newRow][newCol])
                {
                    effort[newRow][newCol] = newEffort;

                    pq.push(
                        {
                            newEffort,
                            newRow,
                            newCol
                        }
                    );
                }
            }
        }
    }


    return 0;
}
