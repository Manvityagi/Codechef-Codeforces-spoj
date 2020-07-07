#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define loop(i, a, b) for (int i = a; i < b; i++)

void make(vector<int> &arr, vector<int> &days, vector<int> &hugs)
{
    int sz = arr.size();
    for (int i = 1; i < sz; i++)
        days[i] += days[i - 1];

    for (auto &i : arr)
        hugs.emplace_back(i * (i + 1) / 2);

    for (int i = 1; i < sz; i++)
        hugs[i] += hugs[i - 1];
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL n, m, x;
    cin >> n >> x;
    vector<int> arr(n + 1);
    loop(i, 1, n + 1) cin >> arr[i];
    vector<int> days(arr.begin(), arr.end()), hugs;
    int ans = INT_MIN;
    make(arr, days, hugs);

    //1-based indexing me karna hai sab kuch
    for (int i = 1; i <= n; i++)
    {
        int end_month = i;
        int start_day = days[i] - x + 1;
        if (start_day <= 0)
            start_day += days[n];

        int start_month = lower_bound(days.begin(), days.end(), start_day) - days.begin();
        int days_in_start_mon, res, end_day_in_start_mon, start_day_in_start_mon;

        if (start_month <= end_month)
        {
            res = hugs[end_month] - hugs[start_month];
            days_in_start_mon = x - (days[end_month] - days[start_month]);
        }
        else
        {
            res = hugs[end_month] + hugs[n] - hugs[start_month];
            days_in_start_mon = x - (days[end_month] + days[n] - days[start_month]);
        }

        end_day_in_start_mon = arr[start_month];
        start_day_in_start_mon = end_day_in_start_mon - days_in_start_mon + 1;
        res += (end_day_in_start_mon * (end_day_in_start_mon + 1) >> 1) - ((start_day_in_start_mon * (start_day_in_start_mon - 1)) >> 1);

        ans = max(ans, res);
    }

    cout << ans << "\n";
    return 0;
}
