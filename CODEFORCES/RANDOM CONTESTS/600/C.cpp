#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define int LL
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] ={ 0, 0, 1, -1 };
int movey[] ={ 1, -1, 0, 0 };

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
        LL n, m;
        cin >> n >> m;
        vector<int> a(n), ans(n), mid(n);
        for (auto &i : a) cin>>i;
        sort(a.begin(), a.end());

        mid = a;
        for (int i = m; i < n; i++)
            mid[i] += mid[i-m];

        ans[0] = a[0];
        for (int i = 1; i < n; i++)
            ans[i] = ans[i-1] + mid[i];

        for (auto i : ans) cout << i << " ";
    }
    return 0;
}
