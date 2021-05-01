
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

bool check(int x)
{
    vector<int> nums;
    int orig = x;
    while (x)
    {
        nums.emplace_back(x % 10);
        x /= 10;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
            if (orig % nums[i])
                return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> num;
    int orig = n;

    for (int i = 0; i <= 1e6; i++)
    {
        if (check(n + i))
        {
            cout << n + i << "\n";
            return;
        }
    }
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