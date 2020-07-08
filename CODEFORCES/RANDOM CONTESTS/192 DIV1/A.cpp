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

//is there at least 1 row contianig all Es
bool isRowE(vector<vector<char>> arr)
{
    int n = arr.size();

    bool allE = true;
    loop(i, 0, n)
    {
        bool dot = false;
        loop(j, 0, n)
        {
            if (arr[i][j] == '.')
            {
                dot = true;
                break;
            }
        }
        if (!dot)
            return true;
    }
    return false;
}

bool isColE(vector<vector<char>> arr)
{
    int n = arr.size();

    bool allE = true;
    loop(i, 0, n)
    {
        bool dot = false;
        loop(j, 0, n)
        {
            if (arr[j][i] == '.')
            {
                dot = true;
                break;
            }
        }
        if (!dot)
            return true;
    }
    return false;
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    LL n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> ans;
    unordered_set<int> rows, cols;

    bool f1 = isRowE(arr);
    bool f2 = isColE(arr);

    if (f1 && f2)
    {
        cout << -1 << "\n";
    }

    //agar koi row E se bhari hai to colwise traverse karke aayega ans
    // vice versa for col

    if (isColE)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == '.')
                {
                    ans.emplace_back(i + 1, j + 1);
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == '.')
                {
                    ans.emplace_back(j + 1, i + 1);
                    break;
                }
            }
        }
    }

    for (auto p : ans)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
