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
const int MAX_N = 200;
char num[MAX_N];

//i will ask 1,1 ; 2,2 ; 3,5; 4,5
vector<int> hidden = {4, 8, 15, 16, 23, 42};
int main()
{
    vector<int> arr = {4, 8, 15, 16, 23, 42};
    vector<int> ans(7);
    cout << "? 1 1";
    cout << endl;
    cin >> ans[1];
    ans[1] = sqrt(ans[1]);

    cout << "? 2 2";
    cout << endl;
    cin >> ans[2];
    ans[2] = sqrt(ans[2]);

    int t34, t45;
    cout << "? 3 4";
    cout << endl;
    cin >> t34;

    cout << "? 4 5";
    cout << endl;
    cin >> t45;
    int t34a, t34b, t45a, t45b;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] * arr[j] == t34)
            {
                t34a = arr[i];
                t34b = arr[j];
            }
            else
            {
                t45a = arr[i];
                t45b = arr[j];
            }
        }
    }

    if (t34a == t45a || t34a == t45b)
    {
        ans[4] = t34a;
    }
    else if (t34b == t45a || t34b == t45b)
    {
        ans[4] = t34b;
    }

    ans[3] = t34 / ans[4];
    ans[5] = t45 / ans[4];
    int sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        sum += ans[i];
    }
    ans[6] = 108 - sum;

    cout << "! ";
    for (int i = 1; i <= 6; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}