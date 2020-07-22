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
        LL l, r, m;
        cin >> l >> r >> m;
        LL a = 1, b = 1, c = 1;

        for (a = l; a <= r; a++)
        {
            if (m % a == 0)
            {
                b = l, c = l;
                break;
            }
            int quo = m / a;
            int rem = m % a;
            int add = a * (quo + 1) - m;
            b = l;
            c = b + add;
            if (c <= r)
                break;

            b = r;
            c = b - rem;
            if (c >= l)
                break;
        }

        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
