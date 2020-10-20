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
#define all(a) a.begin(), a.end()
#define pii pair<int,int>
#define loop(i, a, b) for (int i = a; i < b; i++)
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
    while (t--){
       int n;
       cin >> n; 

       vector<vector<char>> grid(n,vector<char>(n));

       for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               cin >> grid[i][j];
           }
       }

       if(grid[0][1] == grid[1][0] && (grid[n-2][n-1] == grid[n-1][n-2] && grid[0][1] != grid[n-2][n-1])){
           cout << 0 << "\n";
           continue;
       }
        int c = 0; 
        vector<pii> ans;
        if(grid[0][1] == grid[1][0]) {
            char st = grid[0][1]; 
            if(st == grid[n-2][n-1]) {
                c++;
                ans.emplace_back(n-2,n-1);
            } 
            if(st == grid[n-1][n-2]) {
                c++;
                ans.emplace_back(n-1,n-2);
            } 
        } else if (grid[n-2][n-1] == grid[n-1][n-2]){
            char end = grid[n-1][n-2]; 
            if(end == grid[0][1]) {
                c++;
                ans.emplace_back(0,1);
            } 
            if(end == grid[1][0]) {
                c++;
                ans.emplace_back(1,0);
            } 
        } else {
             int st = grid[0][1];
             
             c++; 
             ans.emplace_back(1,0); 

            c++;
            if(grid[n-1][n-2] == st){
                ans.emplace_back(n-1,n-2);
            } else {
                ans.emplace_back(n-2,n-1);
            }

        }

        cout << c << "\n";

        for(auto p :ans){
            cout << p.F+1 << " " << p.S+1 << "\n";
        }

    }
    return 0;
}
