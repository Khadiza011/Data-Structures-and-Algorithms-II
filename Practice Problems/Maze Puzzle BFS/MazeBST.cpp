#include <iostream>
using namespace std;

#define MAX 100

int R, C;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

// Directions
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Circular Queue
int qx[MAX*MAX], qy[MAX*MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    qx[rear] = x;
    qy[rear] = y;
    rear = (rear + 1) % (MAX*MAX);
}

void dequeue(int &x, int &y) {
    x = qx[front];
    y = qy[front];
    front = (front + 1) % (MAX*MAX);
}

bool isEmpty() {
    return front == rear;
}

int bfs() {

    if(maze[0][0]==1 || maze[R-1][C-1]==1)
        return -1;

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++) {
            visited[i][j] = false;
            dist[i][j] = -1;
        }

    front = rear = 0;

    enqueue(0,0);
    visited[0][0] = true;
    dist[0][0] = 0;

    while(!isEmpty()) {

        int x,y;
        dequeue(x,y);

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<R && ny>=0 && ny<C &&
               maze[nx][ny]==0 && !visited[nx][ny]) {

                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                enqueue(nx, ny);
            }
        }
    }

    return dist[R-1][C-1];
}

int main() {

    cin >> R >> C;

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin >> maze[i][j];

    int result = bfs();
    cout << "Minimum steps: " << result << endl;

    return 0;
}
