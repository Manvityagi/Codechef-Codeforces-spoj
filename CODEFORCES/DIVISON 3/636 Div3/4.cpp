#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> mp; //cnt of pairs which need 0 changes to make x
    vector<pair<int, int>> vec;
    for (int i = 0; i < n / 2; i++)
    {
        mp[arr[i] + arr[n - i - 1]]++;
        vec.PB(MP(min(arr[i], arr[n - i - 1]), max(arr[i], arr[n - i - 1])));
    }

    vector<int> pre(2 * k + 10,0);
    for (auto it : vec)
    {
        int l = it.F + 1;
        int r = it.S + k;

        pre[l] += 1;
        pre[r+1] -= 1;
    }
    int sum = 0;
    for(int i = 0; i <= 2*k+10; i++){
        sum += pre[i];
        pre[i] = sum;
    }
    
    int ans = n;
    for(int x = 2; x <= 2*k; x++)
    {
        int cnt0 = mp[x];
        int cnt1 = pre[x]-cnt0;
        int cnt2 = n/2 - cnt0 - cnt1;

        ans = min(ans,cnt1+2*cnt2);
    }

    cout << ans << "\n";
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
