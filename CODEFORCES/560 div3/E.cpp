#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;
#define int long long
main()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] * (i+1)*(n-i);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        a[i] %= MOD;
        ans = (ans + a[i] * b[i]) % MOD;
    }

    cout << ans << "\n";
}
