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
        int n = s.size(),max_len = 0;
        char even,odd,echar,ochar;
        for(even = '0'; even <= '9'; even++){
            for(odd = '0'; odd <= '9'; odd++){
                int ecnt = 0, ocnt = 0, curr_len = 0;
                for(int k = 0; k < n; k++){
                    if(even == s[k] && !(curr_len & 1)){
                        ecnt++,curr_len++;
                    }
                    else if(odd == s[k] && (curr_len & 1)){
                        ocnt++,curr_len++;
                    }
                }
                if(even!=odd)
                    curr_len = 2*min(ocnt,ecnt);
                else
                    curr_len = ocnt+ecnt;                
                if(curr_len > max_len){
                    max_len = curr_len;
                    echar = even, ochar = odd;
                }
            }
        }
        cout << n - max_len << "\n";
    }
    return 0;
}