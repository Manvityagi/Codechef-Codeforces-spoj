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
#define pii pair<int, int>

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
    while (t--)
    {
        LL n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr)
            cin >> i;

        vector<pii> a(n);
        loop(i, 0, n)
        {
            a[i].F = arr[i];
            a[i].S = i;
        }
        bool pos = 0;
        sort(a.begin(), a.end());
        int maxi = INT_MIN;
        int mini = INT_MAX;
        loop(i, 0, n)
        {
            if (i > 1)
            {
                if (a[i].S > mini && a[i].S < maxi)
                {
                    cout << "YES\n";
                    cout << mini + 1 << " " << a[i].S + 1 << " " << maxi + 1 << "\n";
                    pos = 1;
                    break;
                }
            }
            maxi = max(maxi, a[i].S);
            mini = min(mini, a[i].S);
        }
        if (!pos)
            cout << "NO\n";
    }
    return 0;
}
