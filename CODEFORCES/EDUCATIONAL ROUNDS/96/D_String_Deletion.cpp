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
#define pii pair<int,int> 
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
        string s; 
        cin >> s; 
        if(n == 1){
            cout << 1 << "\n"; 
            continue;
        }

        int ans = 0, i = 0;
        vector<int> cnt;  
        cnt.emplace_back(1);
        for(int i = 1; i < n; i++){
            if(s[i-1] == s[i]) {
                cnt.back()++;
            }else{
                cnt.emplace_back(1);
            }
        }

        n = cnt.size(); 

        i = 0;
        int j= 0;
        while(i < n){
            while(j < i) j++;
            while(j < n && cnt[j] == 1) j++;
            if(j == n) i+=2;
            else cnt[j]--,i++; 
            ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
