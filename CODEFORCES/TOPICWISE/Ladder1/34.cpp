#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ppi pair<int, int>
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> pages(n), sum(n);
    for (int i = 0; i < 7; i++)
    {
        cin >> pages[i];
        sum[i] += pages[i];
        if (sum[i] >= n)
        {
            ans = i;
        }
    }

    if (ans != 0)
    {
        cout << ans;
        return 0;
    }

    n = n - n / sum[n - 1];

    for (int i = 0; i < 7; i++)
    {
        if (sum[i] >= n)
        {
            ans = i;
            cout << ans;
            return 0;
        }
    }
}