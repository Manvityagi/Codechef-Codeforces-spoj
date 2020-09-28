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

vector<int> fib(int n)
{
    vector<int> f(n + 1);
    int i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f;
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    vector<int> f = fib(1001);
    // cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;

        vector<char> ans(n + 1, 'o');
        for (int i = 0; i < n, f[i] <= n; i++)
        {
            ans[f[i]] = 'O';
        }

        for (auto i = 1; i <= n; i++)
            cout << ans[i];
    }
    return 0;
}
