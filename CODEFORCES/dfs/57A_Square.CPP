#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x1, y1, x2, y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;

    if (y1 == y2 && (y1 == 0 || y1 == n))
    {
        cout << abs(x1 - x2) << endl;
        return;
    }
    if (x1 == x2 && (x1 == 0 || x1 == n))
    {
        cout << abs(y1 - y2) << endl;
        return;
    }
    if ((y1 == 0 && y2 == n) || (y1 == n && y2 == 0))
    {
        cout << min(x1 + x2 + n, n * 3 - x1 - x2) << endl;
        return;
    }
    if ((x1 == 0 && x2 == n) || (x1 == n && x2 == 0))
    {
        cout << min(y1 + y2 + n, n * 3 - y1 - y2) << endl;
        return;
    }
    cout << abs(y1 - y2) + abs(x1 - x2) << endl;
}