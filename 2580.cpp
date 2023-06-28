#include <iostream>
#include <string>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 9

int graph[SIZE][SIZE];
bool isInRow[SIZE][SIZE];
bool isInCol[SIZE][SIZE];
bool isInSquare[SIZE][SIZE];

int getSquare(int y, int x) {
    return (y / 3) * 3 + (x / 3);
}

void initInput() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cin >> graph[row][col];

            if (graph[row][col]) {
                isInRow[row][graph[row][col]] = true; 
                isInCol[col][graph[row][col]] = true; 
                isInSquare[getSquare(row, col)][graph[row][col]] = true;
            }
        }
    }
}

void printGraph() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

void DFS(int cnt) {
    int row = cnt / SIZE;
    int col = cnt % SIZE;
    if (cnt == 81) {
        printGraph();
        exit(0);
    }

    if (!graph[row][col]) {
        for (int i = 1; i <= 9; i++) {
            if ((!isInRow[row][i]) && (!isInCol[col][i]) && (!isInSquare[getSquare(row, col)][i])) {
                isInRow[row][i] = true;
                isInCol[col][i] = true;
                isInSquare[getSquare(row, col)][i] = true;
                graph[row][col] = i;
                DFS(cnt + 1);
                graph[row][col] = 0;
                isInRow[row][i] = false;
                isInCol[col][i] = false;
                isInSquare[getSquare(row, col)][i] = false;
            }
        }
    }
    else DFS(cnt + 1);
}

void solve() {
    DFS(0);
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
