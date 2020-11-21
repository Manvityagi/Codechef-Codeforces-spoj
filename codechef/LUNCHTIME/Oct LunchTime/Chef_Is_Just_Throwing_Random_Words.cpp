
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

int toDecimal(vector<int> &a){
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += (a[i] * (1LL << i));
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> ones(60);
    for (int i = 0; i < n; i++){
        int x, j = 0;
        cin >> x;
        while (x > 0){
            if (x & 1) ones[j]++;
            x /= 2;
            j++;
        }
    }
    int carry = 0, j = 0;
    vector<int> ans(60);
    for (int i = 0; i < 60; i++){
        int curr = (ones[i] + carry);
        if (curr >= 1) ans[j] = 1;
        carry = curr/2;
        j++;
    }
    cout << toDecimal(ans) << "\n";
}

signed main(){
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}