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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

main()
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
        int diff = 0;
        int mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
        vector<int> arr(n), temp;
        int sum = 0;
        loop(i, 0, n)
        {
            cin >> arr[i];
        }

        loop(i, 0, n)
        {
            if (i + 1 < n && arr[i] != -1 && arr[i + 1] != -1)
            {
                diff = max(diff, abs(arr[i] - arr[i + 1]));
                // cout << i << " : " << diff << "\n";
            }

            if (arr[i] != -1 && (i != 0 && (arr[i - 1] == -1) || (i != n - 1 && arr[i + 1] == -1)))
            {
                mn = min(mn, arr[i]);
                mx = max(mx, arr[i]);
            }
        }

        int k = (mx + mn) / 2;
        for (auto a : temp)
        {
            diff = max(diff, abs(k - a));
        }

        cout << diff << " " << k << "\n";
    }
    return 0;
}
