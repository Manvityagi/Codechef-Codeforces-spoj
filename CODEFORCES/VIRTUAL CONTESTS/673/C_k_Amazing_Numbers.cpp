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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n); 
        vector<int> pos[n+1]; 
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            pos[arr[i]].push_back(i); 
        }

        vector<int> ans(n+2,n+n);

        for(int i = 1; i <= n; i++){
            int start = -1;
            int mx = 0;
            for(int j : pos[i]){
                mx = max(mx,j-start);
                start = j;
            }
            mx = max(mx,n-start);

            ans[mx] = min(ans[mx],i);
        }


        int mn = n+n; 

        for(int i = 1; i <= n; i++){
            mn = min(mn,ans[i]); 
            if(mn > n) cout << -1 << " "; 
            else cout << mn << " ";
        }
        cout << "\n";
     }
    return 0;
}
