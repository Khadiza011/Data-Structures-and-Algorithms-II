#include <iostream>
using namespace std;

#define MAX 100

int R, C;
int maze[MAX][MAX];
bool visited[MAX][MAX];

// Directions
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {

    visited[x][y] = true;
    int count = 1;

    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<R && ny>=0 && ny<C &&
           maze[nx][ny]==0 && !visited[nx][ny]) {

            count += dfs(nx, ny);
        }
    }
    return count;
}

int main() {

    cin >> R >> C;

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }

    int regionCount = 0;
    int regionSize[100];

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(maze[i][j]==0 && !visited[i][j]) {
                regionSize[regionCount] = dfs(i,j);
                regionCount++;
            }
        }
    }

    cout << "Number of regions: " << regionCount << endl;
    cout << "Region sizes: ";
    for(int i=0;i<regionCount;i++)
        cout << regionSize[i] << " ";

    return 0;
}
