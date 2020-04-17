#include <bits/stdc++.h>
using namespace std;
const long long N = 500;
#define LL long long
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
vector<string> planet;
int n, r1, c1, r2, c2;
vector<pii> SRC, DES;
unordered_set<string> visited;
int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}
void dfs(int x, int y, vector<pii> &filled)
{

    string str = to_string(x) + "-" + to_string(y);
    // cout << "DFS ON " << str << "\n";
    if (!valid(x, y) || visited.find(str) != visited.end() || planet[x][y] == '1')
    {
        return;
    }

    visited.insert(str);

    filled.push_back(MP(x, y));

    for (int i = 0; i < 4; i++)
    {
        int newx = x + moveX[i];
        int newy = y + moveY[i];

        string newstr = to_string(newx) + "-" + to_string(newy);
        if (valid(newx, newy) && visited.find(newstr) == visited.end())
        {
            dfs(newx, newy, filled);
        }
    }
}

main()
{
    cin >> n >> r1 >> c1 >> r2 >> c2;
    planet.resize(n);
    r1--,c1--,r2--,c2--;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        planet[i] = s;
    }

    visited.clear();
    dfs(r1, c1, SRC);
    visited.clear();
    dfs(r2, c2, DES);

    int x1, y1, x2, y2;

    // cout << "REACHABLE FROM SRC \n";
    // for (int i = 0; i < SRC.size(); i++)
    // {
    //     cout << SRC[i].F << "," << SRC[i].S << "  ";
    // }
    // cout << "\n REACHABLE FROM DES \n";
    // for (int i = 0; i < DES.size(); i++)
    // {
    //     cout << DES[i].F << "," << DES[i].S << "  ";
    // }

    if (SRC == DES)
    {
        cout << 0;
        return 0;
    }

    int cost = INT_MAX;
    for (int i = 0; i < SRC.size(); i++)
    {
        x1 = SRC[i].F + 1;
        y1 = SRC[i].S + 1;
        for (int j = 0; j < DES.size(); j++)
        {
            x2 = DES[j].F + 1;
            y2 = DES[j].S + 1;

            int currcost = pow((x2 - x1), 2) + pow((y2 - y1), 2);
            cost = min(cost, currcost);
        }
    }

    cout << cost;
}