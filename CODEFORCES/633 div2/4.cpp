#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <chrono>

#define INF 1e9
#define LL_INF 2e18

#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)(x.size()))

#define MOD1 998244353
#define MOD2 666013
#define P1 255
#define P2 2059

#define eps 1e-7

using namespace std;

typedef long long int ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int nmax = 200010;
const int MOD = (1e9) + 7;

int t, n;
int dp[nmax];
bool isLeaf[nmax];
vector <int> leaves, g[nmax];



int main()
{
    //freopen("in1.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) g[i].clear();

    for (int i = 1; i < n; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        g[a].pb(b); g[b].pb(a);
    }

    


    int mn = 1;
    int mx = n - 1;


    printf("%d %d\n", mn, mx);

    // IMPORTANT!!!!!
    // Are you missing something????
    // check limits, int or ll

    return 0;
}