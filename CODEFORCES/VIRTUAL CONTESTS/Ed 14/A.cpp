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
    // cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<LL> a(n);
        bool possible = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            if (a[0] == 0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }

            return 0;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += a[i];
        }

        if (cnt != n - 1)
            possible = 0;
        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
