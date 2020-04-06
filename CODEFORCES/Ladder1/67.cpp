#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ppi pair<int, int>
int main()
{
    int n;
    cin >> n;
    vector<int> seq(n), cnt(8, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
        cnt[seq[i]]++;
    }

    if (cnt[5] != 0 || cnt[7] != 0 || cnt[1] == 0)
    {
        cout << -1;
        return 0;
    }

    vector<string> ans;

    while (cnt[1] > 0 && cnt[2] > 0 && cnt[4] > 0)
    {
        cnt[1]--, cnt[2]--, cnt[4]--;
        ans.push_back("1 2 4");
    }
    while (cnt[1] > 0 && cnt[2] > 0 && cnt[6] > 0)
    {
        cnt[1]--, cnt[2]--, cnt[6]--;
        ans.push_back("1 2 4");
    }
    while (cnt[1] > 0 && cnt[3] > 0 && cnt[6] > 0)
    {
        cnt[1]--, cnt[3]--, cnt[6]--;
        ans.push_back("1 3 6");
    }

    for(auto c : cnt){
        if(c > 0){
            cout << -1;
            return 0;
        }
    }

    for(auto s : ans){
        cout << s << "\n";
    }
}