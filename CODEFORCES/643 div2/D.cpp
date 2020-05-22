
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
const int MAX_N = 2 * 1e5;
char a[MAX_N];

int main()
{
    LL n,s;
    cin >> n >> s;

    if(n == 1 && s != n){
        cout << "YES\n";
        cout << s << "\n";
        cout << 1 ;
        return 0;
    }

    if(s < 2*n){
        cout << "NO\n";
        return 0;
    } 

    cout << "YES\n";


    for(int i = 1; i <= n-1; i++){
        cout << 1 << " ";
    }

    cout << s-(n-1) << "\n";

    if(s == 2*n)
    cout << n ;
    else
    cout << n+1;

    return 0;
}
