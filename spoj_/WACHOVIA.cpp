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
//bottom up, tabulation

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int W,n,i,w;
    	cin>>W>>n;
    	vector<int> wt(n),val(n);
      for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

         vector<vector<int>> K(n+1, vector<int>(W+1));
     for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
      cout << "Hey stupid robber, you can get " << K[n][W] << ".\n";
    }
    return 0;
}



static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();
