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
int n, k, x, y;

void solve()
{
    cin >> n >> k >> x >> y;
    if (x == y)
    {
        return void(cout << n << " " << n << "\n");
    }
    int origx = x, origy = y; 
    vector<pii> pts;
    if (x < y)
    {
        if (x != 0 && y != n)
        {
            x += n - y;
            y = n;
            pts.emplace_back(x,y); 
        }

        if (x == 0) 
        {
            x += n - y;
            y = n;
            pts.emplace_back(x, y);
            swap(x, y);
            pts.emplace_back(x, y);
            x = x - y;
            y = 0;
            pts.emplace_back(x, y);
            if(pts.size() == 3) pts.emplace_back(origx,origy); 
        }
        else if (y == n) 
        {
            swap(x, y);
            pts.emplace_back(x, y);
            x = x - y;
            y = 0;
            pts.emplace_back(x, y);
            swap(x, y);
            pts.emplace_back(x, y);
            if(pts.size() == 3) pts.emplace_back(origx,origy); 
        }
    }
    else
    {
        if (x != n && y != 0)
        {
            y += n - x;
            x = n;
            pts.emplace_back(x, y); 
        }

        if (x == n)
        {
            swap(x, y);
            pts.emplace_back(x, y);
            y = y - x;
            x = 0;
            pts.emplace_back(x, y);
            swap(x, y);
            pts.emplace_back(x, y);
            if(pts.size() == 3) pts.emplace_back(origx,origy); 
        }
        else if (y == 0)
        {
            y += n - x;
            x = n;
            pts.emplace_back(x, y);
            swap(x, y);
            pts.emplace_back(x, y);
            y = x - y;
            x = 0;
            pts.emplace_back(x, y);
            if(pts.size() == 3) pts.emplace_back(origx,origy); 
        }
    }

    k--; 
    cout << pts[k % 4].F << " " << pts[k % 4].S << "\n";
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
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}