#include <bits/stdc++.h>
using namespace std;
int n, k, i;
string s;
main()
{
    cin >> n >> k;
    cin >> s;
    vector<int> a(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'A']++;
    }

    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (k > 0)
        {
            ans += a[i]*min(a[i],k);
            k -= a[i];
        }
    }

    cout << ans;
}