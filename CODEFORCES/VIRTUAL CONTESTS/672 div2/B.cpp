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

int findMSB(int x){
    int cnt = 0, msb; 
    while(x > 0){
        if(x%2) msb = cnt; 
        x /= 2;
    }
    return msb; 
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
        LL n;
        cin >> n;
        vector<LL> a(n); 
        map<int,int> mp; 
        for(auto &i : a) {
            cin >> i;
            int msb = findMSB(i);
            mp[msb]++;
        } 
        int ans = 0;

        for(auto x : mp){
            int curr = x.second; 
            ans += ((curr) * (curr - 1))/2;
        }

        cout << ans << "\n";
     }
    return 0;
}
