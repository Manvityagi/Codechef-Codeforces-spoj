#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <stdlib.h>
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back

//topdown
int n,W,wt[1001];
int dp[1001][1001];
int solve(int i,int w){
	if(i>n)
	   return w;
	if (dp[i][w]!=-1)
	  return dp[i][w];
      
	  if((wt[i]+w)<=W)
	dp[i][w]=max(solve(i+2,w+wt[i]),solve(i+1,w));
	else
	 dp[i][w]=solve(i+1,w);
	 return dp[i][w];
 }
int main(){
    int t;
    scanf("%d",&t);
    FOR(j,1,t+1){
		scanf("%d %d",&n,&W);
		FOR(i,1,n+1){
			scanf("%d",&wt[i]);
		}
		 memset(dp,-1,sizeof dp);
		printf("Scenario #%d: %d\n",j,solve(1,0));
	}
}



///////BOTTOM-UP/////////
#include<stdio.h>
typedef int ll;
ll max(ll a,ll b)
{
 if(a>b)
 return a;
 else return b;
}
ll bb[1002];
ll dp[1002][1002];
int main()
{
 ll t,n,k,f=1;
 scanf("%lld",&t);
 while(t--)
 {
 scanf("%d%d",&n,&k);
 for(ll i=2;i<=n+1;i++)
 scanf("%d",&bb[i]);
 for(ll i=2;i<=n+1;i++)
 {
 for(ll j=0;j<=k;j++)
 {
 if(j==0)
 dp[i][j]=0;
 else
 {
 if(bb[i]<=j)
 dp[i][j]=max(bb[i]+dp[i-2][j-bb[i]],dp[i-1][j]);
 else
 dp[i][j]=dp[i-1][j];
 }
 }
 }
 printf("Scenario #%d: %d\n",f++,dp[n+1][k]);
}
 return 0;
}