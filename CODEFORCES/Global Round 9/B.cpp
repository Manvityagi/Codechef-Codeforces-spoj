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

bool valid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        bool possible = true;
        loop(i, 0, n) loop(j, 0, m) cin >> arr[i][j];

        loop(i, 0, n)
        {
            loop(j, 0, m)
            {
                int cnt = 0;
                loop(k, 0, 4)
                {
                    int newx = i + movex[k];
                    int newy = j + movey[k];
                    if (valid(newx, newy))
                        cnt++;
                }

                if (cnt > arr[i][j])
                {
                    cout << "NO\n";
                    possible = false;
                    break;
                }
                arr[i][j] = cnt;
            }
            if (!possible)
                break; 
        }

        if (possible)
        {
            cout << "YES\n";
            loop(i, 0, n)
            {
                loop(j, 0, m)
                {
                    cout << arr[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
