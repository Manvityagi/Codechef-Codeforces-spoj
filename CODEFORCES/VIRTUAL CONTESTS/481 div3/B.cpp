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
    // cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        string s; 
        cin >> s;
        int ans = 0, currx = 0; 
        for(int i = 0; i < n; i++){
            if(s[i] == 'x') currx++;
            else currx = 0; 
            if(currx == 3){
                ans++;
                currx = 2;
            }
        }

        cout << ans;
     }
    return 0;
}
