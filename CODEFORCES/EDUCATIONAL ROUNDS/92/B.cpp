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
#define V vector
#define loop(i, a, b) for (int i = a; i < b; i++)
const int N = 1e5+1;
LL n, total_moves, left_moves;
vector<int> a(N);
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

//prev - last time left move tha ya right 
//prev - 0 = left, 1- right
int calculate(int idx, int moves, int left, int prev, int dp[100001][100001][][][])
{
    if(moves <= 0 || idx >= n) return 0;
    if(dp[idx][moves][left][prev] != -1) return dp[idx][moves][left][prev];
    int op1 = INT_MAX, op2 = INT_MAX;

    //op1 - move to right
    if(idx+1 < n)
    op1 = a[idx] + a[idx+1] + calculate(idx+1,moves-1,left,1, dp);

    //op2 - move to left 
        //not possible when 
            //1. left <= 0
            //2. prev = l 
        if(left <= 0 || prev == 0 || idx-1 < 0)
            op2 = INT_MAX;
        else
        {
            op2 = a[idx] + a[idx-1] + calculate(idx+1,moves-1,left-1,0, dp);
        }
        

    dp[idx][moves][left][prev] = max(op1,op2);
    return max(op1,op2);
}
void solve()
{
    cin >> n >> total_moves >> left_moves;
    for (auto &i : a) cin >> i;
    int dp[n][total_moves+1][left_moves+1][2];
    memset(dp,-1,sizeof(dp));
    cout << calculate(0,0,0,1,dp) << "\n";
}
int main()
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
       solve();
    }
    return 0;
}
