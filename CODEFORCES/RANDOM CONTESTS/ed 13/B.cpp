#include <bits/stdc++.h>
using namespace std;
#define LL long long

bool leap(int y)
{
    return (y % 400 == 0 || y % 100 != 0 && y % 4 == 0);
}

int shift_helper(int y)
{

    if (leap(y))
        return 2;
    return 1;
}

int helper(int y)
{
    int shift = shift_helper(y);
    int nxt = y + 1;

    int days = 0;
    while (1)
    {
        days += shift_helper(nxt);

        if (days % 7 == 0 && leap(y) == leap(nxt))
            return nxt;
        nxt++;
    }

    return nxt;
}

int main()
{
    LL y;
    cin >> y;

    cout << helper(y);
}