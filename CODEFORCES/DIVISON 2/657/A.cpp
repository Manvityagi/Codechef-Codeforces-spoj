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
int countFreq(string &txt, string &pat)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
        {
            res++;
            j = 0;
        }
    }

    return res;
}

void qhelp(string &s, int st, int end)
{

    for (int i = st; i < end; i++)
    {
        if (s[i] == '?')
        {
            s[i] = 'd';
        }
    }
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        bool found = 0;
        int n;
        cin >> n;
        string str;
        cin >> str;
        string target = "abacaba";
        int f = countFreq(str, target);
        if (n < 7 || f >= 2)
        {
            cout << "no\n";
            continue;
        }
        int freq = 0;
        for (int i = 0; i + 6 < n; ++i)
        {
            bool flag = true;
            for (int j = 0; j < 7; ++j)
            {
                if (target[j] != str[i + j] && str[i + j] != '?')
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                freq = 0;
                string t = str;
                qhelp(t, 0, i);
                for (int j = i; j < i + 7; ++j)
                    t[j] = target[j - i];
                qhelp(t, i + 7, n);
                for (int p = 0; p + 7 <= n; ++p)
                {
                    bool flag = true;
                    for (int j = 0; j < 7; ++j)
                    {
                        if (t[p + j] != target[j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        freq++;
                }
                if (freq == 1)
                {
                    cout << "yes\n";
                    cout << t << "\n";
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
            cout << "no\n";
    }
    return 0;
}
