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
const int MAX_N = 2e5 + 5;
char a[MAX_N];

//opening bracket hai to jiski height choti hai, usme dalengem
//closing bracket hai to jis group ki height badi hai usme dalenge

int main()
{
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    //0       //1
    int seta = 0, setb = 0;

    for (int i = 0; i < n; i++)
    {
        bool who = 0;

        if (s[i] == '(')
        {
            if (setb < seta)
            {
                who = 1;
            }
        }
        else
        {
            if (setb > seta)
            {
                who = 1;
            }
        }

        printf("%d", who);

        int add = s[i] == '(' ? 1 : -1;

        //who pe depend karta hai, seta me add kiya hai ya setb me
        if (who)
        {
            setb += add;
        }
        else
        {
            seta += add;
        }
    }

    puts("");
    return 0;
}