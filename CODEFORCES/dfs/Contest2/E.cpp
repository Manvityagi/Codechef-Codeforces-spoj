// https://codeforces.com/problemset/problem/510/B
#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[51];
bool visited[51][51];
bool findcycle = false;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    else
        return true;
}

void dfs(int x, int y, int fromX, int fromY, char needColor)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;

    if (board[x][y] != needColor)
        return;

    if (visited[x][y])
    {
        findcycle = true;
        return;
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        // if (nextX == fromX && nextY == fromY){
        // 	cout << i << " " << x << " " << y << " " << fromX << " "  << fromY << " "  << nextX << " " << nextY << "\n";
        // 	 continue;
        // }
        if (valid(nextX, nextY) && !visited[nextX][nextY])
            dfs(nextX, nextY, x, y, needColor);
    }
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j, -1, -1, board[i][j]);
            }
        }
    }

    cout << (findcycle ? "Yes" : "No") << "\n";

    return 0;
}
