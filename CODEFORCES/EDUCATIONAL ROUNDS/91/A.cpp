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
        vector<pii> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].F;
            arr[i].S = i;
        }

        sort(arr.begin(), arr.end());

        bool poss = 0;
        int mn_idx = INT_MAX, mx_idx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].S > mn_idx && arr[i].S < mx_idx)
            {
                cout << "YES\n";
                cout << mn_idx + 1 << " " << arr[i].S + 1 << " " << mx_idx + 1 << "\n";
                poss = 1;
                break;
            }
            mn_idx = min(mn_idx, arr[i].S);
            mx_idx = max(mx_idx, arr[i].S);
        }

        if (!poss)
            cout << "NO\n";
    }
    return 0;
}
