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
        LL a, b, c;

        for (a = l; a <= r; a++)
        {
            if (m % a == 0)
            {
                b = l, c = l;
                break;
            }
            int rem = m % a;

        
                // int op1 = m + rem;
                b = l;
                c = b + rem;
                //c-b = b+rem-b = rem
                if (c <= r)
                {
                    break;
                }

            // int op2 = m - rem;
            if (m - rem >= a)
            {
                c = l;
                b = c + rem;
                if (b <= r)
                {
                    break;
                }
            }

            //c-b = c - c - rem
        }

        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
