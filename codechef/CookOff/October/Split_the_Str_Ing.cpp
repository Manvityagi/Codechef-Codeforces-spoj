
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
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
#define int LL
int w, n;
vector<int> x;

bool solve(){
   int n; 
   cin >> n; 
   string s; 
   cin >> s;
   
   for(int i = 0; i < n-1; i++){
       if(s[i] == s[n-1]) return 1;
   }
   return 0;
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
    cin >> t;
    while (t--){
        if(solve()) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}