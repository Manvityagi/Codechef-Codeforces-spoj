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
#define loop(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int main()
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
        int n, m;
        cin >> n >> m;
        vector<pii> rob(n), light(m);
        for (int i = 0; i < n; i++)
            cin >> rob[i].F >> rob[i].S;
        for (int i = 0; i < m; i++)
            cin >> light[i].F >> light[i].S;

        vector<pii> arr;
        for (auto r : rob)
        {
            for (auto l : light)
            {
                arr.emplace_back(max(0, l.F - r.F + 1), max(0, l.S - r.S + 1));
            }
        }

        sort(arr.begin(), arr.end());

        int sz = arr.size();
        vector<int> largesty(sz+1);

        int maxTillNow = 0;
        largesty[sz] = 0;
        for (int i = sz-1; i >= 0; i--)
        {
            maxTillNow = max(maxTillNow, arr[i].S);
            largesty[i] = maxTillNow;
        }

        int ans = largesty[0];
        for (auto i = 0; i < sz; i++)
        {
            int x = arr[i].F;
            int y = largesty[i + 1];
            ans = min(ans, x + y);
        }

        cout << ans << "\n";
    }
    return 0;
}
