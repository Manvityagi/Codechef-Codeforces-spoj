// https://codeforces.com/contest/329/problem/B

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define loop(i, a, b) for (int i = a; i < b; i++)
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

bool valid(int x, int y, int r, int c, vector<vector<char>> &arr)
{
    return x >= 0 && y >= 0 && x < r && y < c && arr[x][y] != 'T';
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int r, c;
    cin >> r >> c;
    pii ex;
    pii st;
    vector<vector<char>> arr(r, vector<char>(c));
    vector<vector<int>> dist(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'E')
            {
                ex = make_pair(i, j);
            }
            if (arr[i][j] == 'S')
            {
                st = make_pair(i, j);
            }
        }
    }

    queue<pii> q;
    q.emplace(ex);
    dist[ex.first][ex.second] = 0;
    int mydist;
    while (q.size())
    {
        auto front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;

        for (int k = 0; k < 4; k++)
        {
            int newx = x + movex[k];
            int newy = y + movey[k];
            if (!valid(newx, newy, r, c, arr) || dist[newx][newy] != -1)
                continue;
            dist[newx][newy] = dist[x][y] + 1;

            if (newx == st.first && newy == st.second)
                mydist = dist[newx][newy];
            q.emplace(newx, newy);
        }
    }

    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] >= '0' && arr[i][j] <= '9')
            {
                if (dist[i][j] != -1 && dist[i][j] <= mydist)
                {
                    ans += (arr[i][j] - '0');
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
