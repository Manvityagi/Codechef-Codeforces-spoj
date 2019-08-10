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

int main() {
    int t;
    cin>>t;
    while(t--)
    {
    	LL N, K;
    	cin >> N >> K;
    	
    	if(N == K) {cout << "YES \n"; }
    	else
    	if(K == 1){
    	 cout << "NO \n";
    	}
    	else
    	if(N/K != K){
    	    cout << "YES \n";
    	}
    	else
    	cout << "NO \n" ;
    	//first candidate
    // 	LL eachBox = N/K;
    // 	bool flag = false;
    // 	for(int i = 1; i <= N; i += K)
    // 	{
    // 	    if(i != eachBox) {
    // 	        cout << "NO \n";
    // 	        flag = true;
    	        
    // 	        break;
    // 	    }
    // 	}
    	
    // 	if(!flag)
    //       {
    //             cout << "YES \n";
    //       }
    
   
    	
    	
    }
    return 0;
}



static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();