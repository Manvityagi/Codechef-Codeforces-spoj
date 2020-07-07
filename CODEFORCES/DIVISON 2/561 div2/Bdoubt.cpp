#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    //5 se bada ek multiple zaroor hona chahiye
    //Find a,b, st , a*b=n such that a, b >= 5

    //5 se n/2 tak divide karke dekh sakte hai

    //i >= 5 && n%i == 0 && n/i >= 5

    if (n < 25)
    {
        cout << -1 << "\n";
        return 0;
    }
    int row = -1;
    int col = -1;
    bool possible = false;
    for (int i = 5; i <= n / 2; i++)
    {
        if (n % i == 0 && n / i >= 5)
        {
            possible = true;
            row = i;
            col = n / i;
            break;
        }
    }

    if (!possible)
    {
        cout << -1 << "\n";
        return 0;
    }

    //row1
    cout << "aeiou";
    //row1 cols 6 to col
    for (int i = 6; i <= col; i++)
    {
        cout << 'a';
    }

    //row2
    cout << "eioua";
    //row2 cols 6 to col
    for (int i = 6; i <= col; i++)
    {
        cout << 'e';
    }

    //row3
    cout << "iouae";
    //row2 cols 6 to col
    for (int i = 6; i <= col; i++)
    {
        cout << 'i';
    }

    //row4
    cout << "ouaei";
    //row2 cols 6 to col
    for (int i = 6; i <= col; i++)
    {
        cout << 'o';
    }

    //row5
    cout << "ouaei";
    //row2 cols 6 to col
    for (int i = 6; i <= col; i++)
    {
        cout << 'u';
    }

    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    int v = 0;
    for (int i = 6; i <= row; i++)
    {
        cout << "aeiou";

        for (int j = 6; j <= col; j++)
        {
            cout << vowel[v % 4];
            v++;
        }
    }

    puts("");
}

// aeiou a eioua e iouae i ouaei o ouaei u aeiou m
//mannn it is vowly, aayush ko dikhana ye
