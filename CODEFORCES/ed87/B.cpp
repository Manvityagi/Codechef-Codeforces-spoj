

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
const int MAX_N = 2 * 1e5;
char a[MAX_N];
const int no_of_chars = 256;
#define int LL


void play()
{
    for(int i = 0; i < 6; i++)
    {
        
    }
}
int solve(string str, string pat)
{
    int len1 = str.length();
    if (len1 < 3)
    {
        return -1;
    }

    int mp_pat[no_of_chars] = {0};
    int mp_str[no_of_chars] = {0};

    for (int i = 0; i < 3; i++)
        mp_pat[pat[i]]++;

    int st = 0, st_index = -1, min_len = INT_MAX;

    int cnt = 0;
    for (int j = 0; j < len1; j++)
    {
        mp_str[str[j]]++;

        if (mp_pat[str[j]] != 0 &&
            mp_str[str[j]] <= mp_pat[str[j]])
            cnt++;

        if (cnt == 3)
        {
            while (mp_str[str[st]] > mp_pat[str[st]] || mp_pat[str[st]] == 0)
            {
                if (mp_str[str[st]] > mp_pat[str[st]])
                    mp_str[str[st]]--;
                st++;
            }
            int len_window = j - st + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                st_index = st;
            }
        }
    }

    if (st_index == -1)
    {
        return 0;
    }

    return min_len;
}

main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() < 3)
        {
            cout << 0 << "\n";
            continue;
        }
        string pat = "123";
        cout << solve(s, pat) << "\n";
    }

    return 0;
}
