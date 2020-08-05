#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, a, b, v;
    cin >> k >> a >> b >> v;

    // b++;
    int ans = 0, temp = 0;
    while (b > 0 && a > 0)
    {
        int sec = min(b+1, k);
        b -= (k-1);
        ans++;
        a -= (sec*v);
    }
    // cout << a << "\n";
    if (a > 0)
        temp = (a + v - 1) / v;
    ans += temp;
    // cout << temp << "\n";

    cout << ans;
}