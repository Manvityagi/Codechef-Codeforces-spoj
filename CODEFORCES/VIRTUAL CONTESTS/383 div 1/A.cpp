/*
1 hi cycle ho aur saari nodes, us cycle ka hi part ho, 
Even length cycle - ans = len/2
Odd length cycle  - ans = len
*/

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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
#define int LL
signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(auto i = 1; i <= n; i++) cin >> arr[i]; 
        
        bool possible = 1;
        int res = 1;
        for(int st = 1; st <= n; st++){
            int steps = 1; 
            int end = arr[st]; 
            while(st != end && steps <= n){
                end = arr[end]; 
                steps++;
            }
            if(st != end){
                possible = 0;
                break;
            }
            // cout << res << " " << steps << "\n";
            if(steps & 1) res = (res*steps)/__gcd(res,steps);
            else res = (res*steps/2)/__gcd(res,steps/2);
        }

        if(!possible){
            cout << "-1\n";
            return 0;
        }

        cout << res << "\n";
     }
    return 0;
}
