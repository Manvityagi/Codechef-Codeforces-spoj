#include <bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n;
    cin >> n;

    vector<int> h(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
        sum += h[i];
    }

    if(sum % n == 0){
        cout << n;
    }
    else
    {
        cout << n-1;
    }
    
  

}