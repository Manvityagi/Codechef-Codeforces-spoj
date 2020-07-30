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
        string s;
        cin >> s;
        int n = s.size();
        int even = 0,odd = 0,len = 0, ans = 0, i, j, k,cnt1,cnt2;
        char i, j, p1, p2;
        //chose (i,j) i - even , j - odd
        for(i = '0'; i <= '9'; i++){
            for(j = '0'; j <= '9'; j++){
                len=0,even=0,odd=0;
                for(k = 0; k < n; k++){
                    if(i == s[k]){
                        if(!(len & 1))
                            even++, len++;
                    }
                    else if(j == s[k]){
                        if(len&1)
                            odd++,len++;
                    }
                }
            }
            if(ans > len){
                ans=len;
                p1=i,p2=j;
                cnt1 = even, cnt2 = odd;
            }
        }
        vector<char> res(ans);
        for(int t = 0; t < ans; t+=2){
            res[t] = p1;
        }
        for(int r = 1; r < ans; r += 2){
            res[r] = p2;
        }

        for(auto a : res){
            cout << a;
        }
        cout << "\n";
    }
    return 0;
}
