#include<bits/stdc++.h>
using namespace std; 
//if there is A/T, also need T/A, 
//if there is G/C, also need C/G

int main(){
    int n; 
    cin >> n; 
    string s; 
    cin >> s;
    
    vector<int> a(n), t(n), g(n), c(n); 
    for(int i = 0; i < n; i++){
        if(i){
            a[i] += a[i-1]; 
            t[i] += t[i-1];
            g[i] += g[i-1];
            c[i] += c[i-1];
        }
        if(s[i] == 'A') a[i]++;
        if(s[i] == 'T') t[i]++;
        if(s[i] == 'G') g[i]++;
        if(s[i] == 'C') c[i]++;
    }

    int ans = 0;
    for(int st = 0; st < n; st++){
        for(int end = st; end < n; end++){
            int cnta = st ? a[end] - a[st-1] : a[end];
            int cntt = st ? t[end] - t[st-1] : t[end]; 
            int cntg = st ? g[end] - g[st-1] : g[end]; 
            int cntc = st ? c[end] - c[st-1] : c[end];

            if(cnta == cntt && cntg == cntc) ans++; 
        }
    }
    cout << ans;
}