#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD1 1000000007
#define MOD2 1000000009

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t;
    cin >> t;
    while (t--)
    {

        LL n;
        cin >> n;
        // cout << "ANS FOR " << n << "\n";

        if (n == 1)
        {
            cout << 1 << "\n";
            cout << 1 << "\n";
            cout << 1 << " " << 1 << "\n";
            continue;
        }

        if (n == 2)
        {
            cout << n/2 << "\n";
            cout << 2 << " " << 1 << " " << 2 << "\n";
            continue;
        }

        cout << n/2 << endl;

        cout << 3 << " " << 1 << " " << 2 << " " << 3 << "\n";

        for (LL i = 4; i <= n; i += 2)
        {

            //1 ya 2 ka decision for number of elements
            if (i == n && !(n & 1))
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 2 << " ";
            }

            cout << i << " ";
            if (i + 1 <= n)
            {
                cout << i + 1 << " ";
            }

            cout << "\n";
        }
    }
    return 0;
}
