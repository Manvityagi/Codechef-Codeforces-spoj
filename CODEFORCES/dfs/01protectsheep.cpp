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

int m, n;

bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}
void erast()
{
    int n;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int movex[] = {-1, 1, 0, 0};
int movey[] = {0, 0, -1, 1};

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (board[i][j] == 'S')
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    int newx = i + movex[dir];
                    int newy = j + movey[dir];
                    if (isValid(newx, newy) && board[newx][newy] == 'W')
                    {
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "YES\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] == '.'){
                cout << "D";
            }
            else if(board[i][j] == 'S'){
                cout << "S";
            }
            else
            {
                cout << "W";
            }
            
        }

        cout << endl;
    }

    return 0;
}
