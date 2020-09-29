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

bool symm(vector<vector<int>> mat){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(mat[i][j] != mat[j][i]) return false;
        }
    }
    return 1;
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
    while (t--)
    {
        LL n, m;
        cin >> n >> m;
        
        if(m & 1) {cout << "NO\n"; continue;}
        bool possible = 0;
        for(int i = 0; i < n; i++){
            vector<vector<int>> curr(2,vector<int>(2));
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    cin >> curr[j][k]; 
                }
            }
            if(!possible && symm(curr)){
                possible = 1;
            }
        }

        if(possible) cout << "YES\n"; 
        else cout << "NO\n"; 
     }
    return 0;
}
