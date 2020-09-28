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
LL n, m;
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
    int t;
    cin >> t;
    while (t--)
    {
        LL n, x;
        cin >> n >> x;
        int sum = 0;
        bool possible = false;
        vector<int> a(n);
        for (auto &i : a)
        {
            cin >> i;
            sum += i;
            if (i % x)
                possible = true;
        }
        if (!possible)
        {
            cout << -1 << "\n";
            continue;
        }
        if (sum % x)
        {
            cout << n << "\n";
            continue;
        }

        vector<int> pre(a.begin(), a.end()), suff(a.begin(), a.end());

        int ans = 0;
        if (pre[0] % x)
            ans = max(ans, 1);
        for (int i = 1; i < n; i++)
        {
            pre[i] += pre[i - 1];
            if (pre[i] % x)
                ans = max(ans, i + 1);
        }
        if (suff[n - 1] % x)
            ans = max(ans, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] += suff[i + 1];
            if (suff[i] % x)
                ans = max(ans, n - i);
        }

        cout << ans << "\n";
    }
    return 0;
}
