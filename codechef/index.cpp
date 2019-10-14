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
#define INF LONG_MAX
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<endl;
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x,y) cout<<x<<" "<<y<<endl;
#define N 400100
#define LD long double
#define PR pair<LD,LL>

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main() {
  static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();

  LL t;
  cin >> t;
  while (t--) {
    LL n, ans = 0;
    cin >> n;
    unordered_map < LL, LL > umap;
    LL seq[n];

    for (LL j = 0; j < n; j++) {
      cin >> seq[j];
      LL num = seq[j];
      ans = max(ans, umap[seq[j]]);

      for (LL i = 1; i <= num/2 ; i++) {
        if (num % i == 0) {
          umap[i]++;
          if (num / i != i)
            umap[num / i]++;
        }
      }
    }
    cout << ans << "\n";
  }
}




