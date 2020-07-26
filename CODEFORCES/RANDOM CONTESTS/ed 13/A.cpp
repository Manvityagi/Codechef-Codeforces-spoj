#include<bits/stdc++.h>
using namespace std;
#define LL long long 
int main()
{
    LL n, k;
    cin >> n >> k;
    LL ans;
    LL t = n % k ;
    if(t == 0)
    {
        ans = n/k + 1;
    }
    else
    {
        ans = ceil(n/k);
    }

    cout << ans * k;
    
}