#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD1 1000000007
#define MOD2 1000000009

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

        LL n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> C(n, vector<int>(k));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> C[i][j];
            }
        }

        std::random_device rd;                       // obtain a random number from hardware
        std::mt19937 eng(rd());                      // seed the generator
        std::uniform_int_distribution<> distr(1, m); // define the range

        for (int i = 0; i < n; i++)
        {

            cout << distr(eng) << " ";
        }

        cout << "\n";
    }
    return 0;
}
