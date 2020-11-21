
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define int LL
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
vector<pii> point;
int n;
double calSlope(int i, int j)
{
    double slope;
    int x2 = point[j].F, x1 = point[i].F;
    int y2 = point[j].S, y1 = point[i].S;
    if (x2 == x1)
        slope = INT_MAX;
    else
        slope = ((y2 - y1) * 1.0) / (x2 - x1);

    return slope;
}

bool solve()
{

    if (n <= 2)
        return 0;

    int ans = 2;

    for (int i = 0; i < n; i++)
    {
        unordered_map<double, int> mp;
        int inf = 0, currmax = 0, same = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (point[i].F == point[j].F && point[i].S == point[j].S)
                same++;
            else if (point[i].F == point[j].F)
            {
                inf++;
                currmax = max(currmax, inf);
            }
            else
            {
                double slope = calSlope(i, j);
                mp[slope]++;
                currmax = max(currmax, mp[slope]);
            }
        }

        ans = max(ans, currmax + same + 1);
        mp.clear();
    }
    if(ans >= 3) return 1;
    return 0;
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    // cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            point.emplace_back(x, y);
        }
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}