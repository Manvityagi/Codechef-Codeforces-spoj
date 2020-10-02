
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
        string s;
        cin >> s; 

        bool ee = 0, oo = 0;
        for(int i = 1; i < n; i++){
            if(i & 1){
                if( (s[i-1]-'0') & 1) oo = 1;
            }
            else{
                if( !((s[i-1]-'0') & 1) ) ee = 1;
            }
        } 

        if(n & 1){
            if(oo) cout << "1\n";
            else cout << "2\n";
        }
        else{
            if(ee) cout << "2\n";
            else cout << "1\n";
        }

        //n even - kisi even pos pe agar even number hai to Breach(2)
        //n odd - kisi odd pos pe agar odd number hai to Raze(1)
    }
    return 0;
}
