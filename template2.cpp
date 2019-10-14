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
#define LD long double
#define PR pair<LD,LL>
 
const int N = 5e3 + 5 ;
 
int dp[N][N] ;
int n , p ;
int helper(int arya , int sansa , int round ){
	if(arya < sansa*p) return 0 ;
	if(round == n) {
		return 1 ;
	}
	if(dp[round][sansa] != -1) return dp[round][sansa] ;
	dp[round][sansa] = (helper(arya,sansa+1,round+1) + helper(arya+1,sansa,round+1))%MOD1 ;
	return dp[round][sansa] ;
}
 
int main() {
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();

	int t ;
	cin >> t;
	while(t--){
		cin >> n >> p ;
		for(int i = 0 ; i  <= n ; i++){
			for(int j = 0 ; j <= n ; j++) dp[i][j] = -1 ;
		}
		cout << helper(0,0,0) << '\n' ;
	}
	return 0;
}