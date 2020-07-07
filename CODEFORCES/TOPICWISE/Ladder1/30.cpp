#include <bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n;
    cin >> n;
    unordered_map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        mp[num] = i;
    }

    ll q;
    cin >> q;

    ll front,back,a,b;

    for(int i = 0; i < q; i++){
        ll query;
        cin >> query;
        front = mp[query];
        back  = n-front+1;

        a += front;
        b += back;
    }

    cout << a << b ;

}