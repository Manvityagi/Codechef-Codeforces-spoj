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
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<endl;
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x,y) cout<<x<<" "<<y<<endl;
#define N 400100
#define LD long double
#define PR pair<LD,LL>
typedef pair<int,int> ppi;

///WHY THIS GIVES TLE
const int INF = 999999999;
vector < int > nit(1024), oxy(1024), wt(1024);  

int SCUBA(int ncap, int ocap, int ci,vector < vector < vector < int > > > dp) {
  //base case

  if (dp[ncap][ocap][ci] != -1)
    return dp[ncap][ocap][ci];

  if ((ncap == 0 && ocap == 0)) {
    dp[ncap][ocap][ci] = 0;
  } else
  if (ci == 0) {
    dp[ncap][ocap][ci] = INF;
  } else {
    int inc = wt[ci-1] + SCUBA(max(ncap - nit[ci-1], 0), max(ocap - oxy[ci-1], 0),ci - 1,dp);
    int exc = SCUBA(ncap, ocap, ci - 1,dp);

    dp[ncap][ocap][ci] = min(inc, exc);
  }

  return dp[ncap][ocap][ci];

}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int ncap, ocap,n;
    scanf("%d %d %d",&ocap,&ncap,&n);

    for (int i = 0; i < n; i++)
      scanf("%d %d %d", &oxy[i], &nit[i], &wt[i]);

    vector < vector < vector < int > > > dp(ncap + 1, vector < vector < int > > (ocap + 1, vector < int > (n, -1)));

    printf("%d\n",SCUBA(ncap, ocap, n, dp));

  }
  return 0;
}

///why is this accepted
// #include <vector>
// #include <list>
// #include <map>
// #include <set>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <bitset>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <sstream>
// #include <iostream>
// #include <iomanip>
// #include <cstdio>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// #include <cstring>
// #include <climits>
// #include <stdlib.h>
// #include <stdio.h>
// using namespace std;
// #define REP(i,n) for(int i=0; i<n; i++)
// #define FOR(i,st,end) for(int i=st;i<end;i++)
// #define db(x) cout << (#x) << " = " << x << endl;
// #define mp make_pair
// #define pb push_back
// typedef long long int ll;

// const int MAX = 1024;
// const int INF = 999999999;

// int N, O, n, t, cs;
// int nitro[MAX], oxi[MAX], w[MAX];
// int dp[MAX][22][80], visited[MAX][22][80];

// int solve(int i, int co, int cn) 
// {
// 	if(dp[i][co][cn]!=-1){
// 		return dp[i][co][cn];
// 	}
// 	if(co==0&&cn==0){
// 		dp[i][co][cn]= 0;
// 	}
// 	else if(i==0){//if we considered all cylinders and if co and cn are still not equal to zero
// 		//then its not possible to satisfy the required condition. Hence return INF in order to eliminate all
// 		//recursive paths leading to this status
// 		dp[i][co][cn]= INF;
// 	 }else{
// 		//either select the ith cylinder or move on to i-1th cylinder
// 		//Be careful about the index:
// 		//ith cylinder oxi[i-1] capacity of oxygen and nitro[i-1] capacity of nitrogen
// 		dp[i][co][cn]=min(solve(i-1,co,cn),solve(i-1,max(co-oxi[i-1],0),max(cn-nitro[i-1],0))+w[i-1]);
// 	}
// 	return dp[i][co][cn];
// }

// int main() 
// {
// 	scanf("%d", &t);
// 	while(t--){
		
// 		scanf("%d %d %d", &O, &N, &n);
// 		for(int i=0;i<n+1;i++)
// 			for(int j=0;j<O+1;j++)
// 				for(int k=0;k<N+1;k++)
// 					dp[i][j][k]=-1;
	
// 		for(int i = 0; i < n; i++) 
//             scanf("%d %d %d", &oxi[i], &nitro[i], &w[i]);
// 		//dp[n][O][N] gives the minimum total weight of cylinders required to have O and N capacity of oxygen
// 		//and nitrogen (capacity of oxygen and nitrogen can exceed)
// 		printf("%d\n", solve(n, O, N));
// 	}
// 	return 0;
// }