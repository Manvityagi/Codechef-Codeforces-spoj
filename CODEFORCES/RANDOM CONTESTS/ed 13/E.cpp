#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(n)); //prob i defeats j
    //p[i][j] + p[j][i] = 1
    //p[i][i] = 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];
        
    
}