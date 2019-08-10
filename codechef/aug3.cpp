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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    LL rad[100000], health[100000];
    for (int i = 1; i <= n; i++) {
      cin >> rad[i];
    }

    LL finalrad[100000] = {
      0
    };

    for (int i = 1; i <= n; i++) {
      int lower = i - rad[i];
      int upper = i + rad[i];
      if(lower <= 0) lower = 1;
      if(upper > n) upper = n;

      for (int j = lower; j <= upper; j++) {
          finalrad[j] += 1; 
      }
    }

    unordered_map < int, int > mp;

    for (int i = 1; i <= n; i++) {
      cin >> health[i];
      mp[health[i]]++;
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {

      if (mp.find(finalrad[i]) == mp.end()) {
        found = true;
        cout << "NO \n";
        break;
      }

     
        if (mp[finalrad[i]] == 0) {
          found = true;
          cout << "NO \n";
          break;    
      }
      mp[finalrad[i]]--;
    }

    if (!found) cout << "YES\n";

  }
  return 0;
}

static
const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();