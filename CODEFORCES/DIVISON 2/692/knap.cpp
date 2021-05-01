
#include <bits/stdc++.h>
using namespace std;

#define int long long
string largestNumber(vector<int> &a, int n)
{
    int mn = 1e5;
    int id = 9;
    for (int i = 9; i >= 1; i--)
    {
        if (mn > a[i])
        {
            id = i;
            mn = a[i];
        }
    }
    int l = n / mn;
    int rem = n % mn;
    if (l == 0)
    {
        return "-1";
    }
    string ans(l, id + '0');
    for (int i = 0; i < l; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if ((rem + a[ans[i] - '0']) >= a[j])
            {
                rem += a[ans[i] - '0'];
                rem -= a[j];
                ans[i] = j + '0';
            }
        }
    }
    return ans;
}

signed main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int amt;
        vector<int> cost(10);
        cin >> amt;
        for (auto i = 1; i <= 9; i++)
            cin >> cost[i];
        string ans = largestNumber(cost, amt);
        cout << ans << "\n";
    }
    return 0;
}