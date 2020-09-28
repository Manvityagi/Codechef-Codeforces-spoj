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
    int ans = INT_MAX, base;
    for (int i = 1; i <= 1000; i++) {
        int first = i, curr = 0;
        for (int j = 0; j < n; j++) if (a[j] != first + j*k)curr++;
        if (curr < ans) base = i, ans = curr;
    }
    cout << ans << "\n";
    for (int j = 0; j < n; j++) {
        int now = base + j*k;
        if (a[j] < now) 
            cout << "+ " << j+1 << " " << now-a[j] << "\n";
        else if (a[j] > now) 
            cout << "- " << j+1 << " " << a[j]-now << "\n";
    }
}