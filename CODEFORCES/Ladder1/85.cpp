#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> ticket(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ticket[i];
    }

    if (ticket[0] != 25)
    {
        cout << "NO";
        return 0;
    }

    int total = 25;
    vector<int> coins(102, 0);
    coins[25] = 1;
    for (int i = 1; i < n; i++)
    {
        total += 25;

        if (total < (ticket[i] - 25))
        {
            cout << "NO";
            return 0;
        }

        coins[ticket[i]]++;

        if (ticket[i] == 25)
        {
            continue;
        }
        else if (ticket[i] == 50)
        {
            if (coins[25] <= 0)
            {
                cout << "NO";
                return 0;
            }

            coins[25]--;
        }
        else if (ticket[i] == 100)
        {
            if (coins[25] <= 0)
            {
                cout << "NO";
                return 0;
            }

            if (coins[50] > 0)
            {
                coins[50]--;
                coins[25]--;
            }
            else if (coins[25] >= 3)
            {
                coins[25] -= 3;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}