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
        int m, n, sx, sy;
        cin >> n >> m >> sx >> sy;
        vector<pair<int,int>> ans;
        ans.emplace_back(sx,sy);
        ans.emplace_back(1,sy);
        ans.emplace_back(1,1);

        for(int i = 1; i <= n; i++){
            if(i & 1){
                for(int j = 1; j <= m; j++){
                    if( (i == sx && j == sy) || (i == 1 && j == sy) || (i == 1 && j == 1)) continue;
                        ans.emplace_back(i,j);
                }
            }
            else{
                for(int j = m; j >= 1; j--){
                    if( (i == sx && j == sy) || (i == 1 && j == sy) || (i == 1 && j == 1)) continue;
                        ans.emplace_back(i,j);
                }
            }
        }
        
        cout << ans.size() << "\n";
        for(auto p : ans){
            cout << p.F << " " << p.S << "\n";
        }

     }
    return 0;
}
