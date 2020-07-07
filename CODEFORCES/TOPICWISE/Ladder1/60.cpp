#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <vector>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <map>
#include <algorithm>

#define fo(i, m, n) for (int i = m; i < n; i++)
#define pii pair<int, int>
#define gt(n) scanf("%d", &n)
#define ii pair<int, int>

using namespace std;
int n, m;
char arr[100][100];
int main()
{
    gt(n), gt(m);
    fo(i, 0, n)
    {
        fo(k, 0, m)
        {
            cin >> arr[i][k];
        }
    }
    char cur = 'B';
    fo(i, 0, n)
    {
        fo(k, 0, m)
        {
            if (arr[i][k] == '.')
            {
                cout << cur;
            }
            else
                cout << '-';
            cur = cur == 'B' ? 'W' : 'B';
        }
        if (m % 2 == 0)
            cur = cur == 'B' ? 'W' : 'B';
        cout << endl;
    }

    return 0;
}