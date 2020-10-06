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
    int t = 1;
    cin >> t;
    cout << fixed;
    cout.precision(10);
    while (t--)
    {
        LL n, l;
        cin >> n >> l;

        vector<int> flag(n);
        for (auto &i : flag)
            cin >> i;

        int i = 0, j = n - 1;
        double ca = 0, cb = l;
        int sa = 1, sb = 1;
        double ans = 0;

        while (i <= j)
        {
            double d1 = flag[i] - ca;
            double d2 = cb - flag[j];
            double ta = (d1 * 1.0) / sa;
            double tb = (d2 * 1.0) / sb;

            if (ta <= tb)
            {
                ans += ta;
                ca += d1;
                cb -= (ta * 1.0 * sb);
                sa++;
                i++;
            }
            else
            {
                ans += tb;
                ca += (tb * 1.0 * sa);
                cb -= d2;
                sb++;
                j--;
            }
        }

        double d = cb - ca;
        ans += d / (sa + sb);
        cout << ans << "\n";
    }
    return 0;
}
