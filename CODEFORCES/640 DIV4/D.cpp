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
const int MAX_N = 200 * 1000 + 5;
char a[MAX_N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int &a : A)
            cin >> a;

        int X = 0, Y = 0, moves = 0;
        int turn = 0, last = 0;
        int start = 0, end = N;

        while (start < end)
        {
            int current = 0;

            if (turn == 0)
            {
                while (start < end && current <= last)
                    current += A[start++];

                X += current;
            }
            else
            {
                while (start < end && current <= last)
                    current += A[--end];

                Y += current;
            }

            moves++;
            turn = 1 - turn;
            last = current;
        }

        cout << moves << ' ' << X << ' ' << Y << '\n';
    }

    return 0;
}
