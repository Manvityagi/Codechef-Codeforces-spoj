#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        vector<int> divisors;

        int maybe = arr[0] * arr.back();
        // cout << "maybe " << maybe << "\n";
        for (int i = 1; i * i <= maybe; i++)
        {
            if (maybe % i == 0)
            {
                divisors.push_back(i);
                if(i*i != maybe){
                    divisors.push_back(maybe/i);
                }
            } 
        }

        sort(divisors.begin(), divisors.end());
        if (divisors == arr)
        {
            cout << maybe << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
        
    }
}
