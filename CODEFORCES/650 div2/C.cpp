
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
const int MAX_N = 2 * 1e5;
bool printDivisors(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i) // check if divisors are equal
            {
                if ((i & 1) && (!((n / i) & 1)) && n / i != 2)
                    return true;
            }
            else
            {
                if ((i & 1) && (!((n / i) & 1)) && n / i != 2)
                    return true;

                int divisior = n / i;
                // push the second divisor in the vector
                if ((divisior & 1) && (!((n / divisior) & 1)) && n / divisior != 2)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << "FastestFinger\n";
        }
        else if (n & 1 || n == 2)
        {
            cout << "Ashishgup\n";
        }
        else
        {
            if (printDivisors(n))
                cout << "Ashishgup\n";
            else
                cout << "FastestFinger\n";
        }
    }
    return 0;
}
