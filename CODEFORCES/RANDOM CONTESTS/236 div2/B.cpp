#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> ideal1(n), ideal2(n);
    int ans1 = 0, ans2 = 0;

    ideal1[0] = a[0];
    for (int i = 1; i < n; i++)
        ideal1[i] = ideal1[i-1] + k;

    ideal2[0] = a[1]-k;
    if (ideal2[0] > 0)
    {
        for (int i = 1; i < n; i++)
            ideal2[i] = ideal2[i-1] + k;

        for (int i = 0; i < n; i++)
            ans2 += (a[i] != ideal2[i]);

    }
    else
    {
        ans2 = INT_MAX;
    }


    for (int i = 0; i < n; i++)
        ans1 += (a[i] != ideal1[i]);

    if (ans1 <= ans2) {
        cout << ans1 << "\n";
        for (int i = 0; i < n; i++)
        {
            if (ideal1[i] > a[i])
                cout << "+ " << i+1 << " " << ideal1[i]-a[i] << "\n";
            else if (ideal1[i] < a[i])
                cout << "- " << i+1 << " " << a[i] - ideal1[i] << "\n";
        }
    }
    else
    {
        cout << ans2 << "\n";
        for (int i = 0; i < n; i++)
        {
            if (ideal2[i] > a[i])
                cout << "+ " << i+1 << " " << ideal2[i]-a[i] << "\n";
            else if (ideal2[i] < a[i])
                cout << "- " << i+1 << " " << a[i] - ideal2[i] << "\n";
        }
    }


}