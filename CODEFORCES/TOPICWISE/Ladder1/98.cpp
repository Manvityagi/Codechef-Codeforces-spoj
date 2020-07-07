#include <bits/stdc++.h>
using namespace std;
int n, k, i, a[100001], b[100001], p1, p2;
main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    for (i = 0; i < n; i++)
    {
        if (b[i] != a[i])
        {
            p2 = i;
            k++;
            if (k == 1)
                p1 = i;
        }
    }
    reverse(a + p1, a + 1 + p2);
    for (i = 0; i < n; i++)
    {
        if (b[i] != a[i])
        {
            cout << "no";
            return 0;
        }
    }
    cout << "yes" << endl
         << p1 + 1 << " " << p2 + 1;
}