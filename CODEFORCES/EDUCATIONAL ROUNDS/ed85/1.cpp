#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool wrong = false;
        vector<int> play, clear;
        vector<int> origplay, origclear;
        vector<pair<int, int>> data(n);
        for (int i = 0; i < n; i++)
        {
            int p, c;
            cin >> p >> c;
            if (c > p)
            {
                wrong = true;
            }
                        play.push_back(p);
                        origplay.push_back(p);
                        clear.push_back(c);
                        origclear.push_back(c);
            // data[i] = make_pair(p, c);
        }

        if (wrong)
        {
            cout << "NO\n";
            continue;
        }

        sort(play.begin(), play.end());
        sort(clear.begin(), clear.end());

        // if (play != origplay || clear != origclear)
        // {
        //     cout << "NO\n";
        //     continue;
        // }
        
        // cout << wrong;

        // for (int i = 1; i < n; i++)
        // {
        //     if (origplay[i] == origplay[i - 1] && origclear[i] !=  origclear[i - 1])
        //     {
        //         cout << "NO\n";
        //         wrong = true;
        //         break;
        //     }
        // }
        
        // cout << wrong;

        if(!wrong){
            cout << "YES\n";
            continue;
        }
    }
    return 0;
}
