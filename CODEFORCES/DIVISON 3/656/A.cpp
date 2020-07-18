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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL x, y, z;
        cin >> x >> y >> z;

        if (x == y && y == z)
        {
            cout << "YES\n";
            cout << x << " " << y << " " << z << "\n";
        }

        LL a, b, c;
        LL x1, y1, z1;

        //case1
        a = x, b = x, c = y;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }
        //2
        a = x, b = x, c = z;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

        //3
        a = x, b = z, c = y;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

        //4
        a = x, b = z, c = z;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

        //5
        a = y, b = x, c = y;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }
        //6
        a = y, b = x, c = z;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

//7
        a = y, b = z, c = y;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

//8
        a = y, b = z, c = z;
        x1 = max(a, b);
        y1 = max(a, c);
        z1 = max(b, c);
        if (x1 == x && y1 == y && z1 == z)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}
