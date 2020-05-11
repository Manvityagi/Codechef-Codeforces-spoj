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
const int MAX_N = 200;
char num[MAX_N];

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d",&n);

        scanf("%s", &num);

        //find the posutnif of first 8, agr n-fpo >= 11. to yes

        int fpo = -1;
        for(int i = 0; i < n; i++){
            if(num[i] == '8'){
                fpo = i;
                break;
            }
        }

        if(fpo == -1){
             cout << "NO\n";
             continue;
        }

        if(n-fpo >= 11){
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }

    return 0;
}
