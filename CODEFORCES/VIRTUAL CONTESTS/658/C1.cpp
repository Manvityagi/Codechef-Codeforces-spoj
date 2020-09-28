#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int hi = n-1;
    vector<int> ans;
    while (hi >= 0) {
        if (a[hi] != b[hi]) {
            if (a[0] == b[hi]) {
            	if(a[hi] == '1') a[0] = '0';
            	else a[0] = '1';
                ans.push_back(1);
            }
            for(int i = 0; i <= hi; i++) {
            	if(a[i] == '1') a[i] = '0';
            	else a[i] = '1';
            }
            reverse(a.begin(), a.begin()+hi+1);
            ans.push_back(hi+1);
        }
        hi--;
    }
    cout << ans.size() << " ";
    for (auto a : ans) cout << a << " ";
    cout << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
