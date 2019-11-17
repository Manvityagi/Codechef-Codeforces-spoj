#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, a, b, A, B;
        cin >> n >> x >> a >> b;

         if (a < b)
        {
            A = a;
            B = b;
        }
        else
        {
            A = b;
            B = a;
        }

        int ans = max(abs(B-1),max(abs(n-A),abs(B-A+x)));
        cout << ans << endl;
    }  
    return 0;
}
