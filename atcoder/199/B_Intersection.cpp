
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
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(auto &i: a) cin >> i;
  for(auto &i: b) cin >> i;
  if(n == 0){
      cout << 0;
      return;
  }

  int ll = a[0], ul = b[0];

  for(int i = 1; i < n; i++){
      if(a[i] > ll) ll = a[i]; 
      if(b[i] < ul) ul = b[i]; 
  }

    int ans = max(int(0),b[i]-a[i]);
    cout << ans;

}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}