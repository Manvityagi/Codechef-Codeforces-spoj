#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ppi pair<int, int>
int main()
{
    int n, m;
    cin >> n >> m;
    queue<ppi> c;
    for (int i = 0; i < n; i++)
    {
        int candy;
        cin >> candy;
        c.push(make_pair(i + 2, candy));
    }
    int last = n;
    while (!c.empty())
    {
        auto curr = c.front();
        c.pop();
        if (curr.second < m)
        {
            c.push(make_pair(curr.first, m - curr.second));
            last = curr.first;
        }
    }

    cout << last;
}