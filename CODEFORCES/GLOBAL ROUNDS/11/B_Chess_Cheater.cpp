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

int cal(string s)
{
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
    if (s[i] == 'W'){
        if (i && s[i - 1] == 'W')
            ans += 2;
        else
            ans += 1;
        }
	}
    return ans;
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int wins = 0, loss = 0, streaks = 0; 
        vector<int> gaps; 

        for(int i = 0; i < n; i++){
            if(s[i] == 'W') {
               if (i == 0 or s[i-1] == 'L') streaks++;
                wins++;
            } 

            if(s[i] == 'L'){
                loss++;
                if(i == 0 || s[i-1] == 'W') gaps.emplace_back(0);
                gaps.back()++;
            }
        }

        if(wins == 0){
            if(k == 0){
                cout << 0 << "\n"; 
            }else{
                cout << 2*k-1 << "\n";
            }
            continue;
        }

        if(loss <= k){
            cout << 2*n-1 << "\n";
            continue;
        }

        // if(s[0] == 'L') gaps[0] = 1e8;
        if(s[n-1] == 'L') gaps.back() = 1e8;
        
        sort(gaps.begin(),gaps.end()); 
        wins += k; 
        int fill = 0; 
        for(auto g : gaps){
            if(g > k) break;
                k -= g; 
                fill++;
        }

        int ans = 2*wins - (streaks - fill);

        cout << ans << "\n";
    }
    return 0;
}
