#include<bits/stdc++.h>
using namespace std; 
#define pii pair<int,int>
#define F first
#define S second

int main(){
    int n; 
    cin >> n;
    vector<pii> a(n);
    bool wrong = 0;
    for(int i = 0; i < n; i++){
         cin >> a[i].first >> a[i].second;
         if(a[i].F != -1 && a[i].S != -1 && a[i].F >= a[i].S) wrong = 1;
    }

    if(wrong) {cout << "No";return 0;}
    
    sort(a.begin(),a.end());
    for(int i = 0; i < n-1; i++){
        if(a[i].S == -1 || a[i].F ==  -1 || a[i+1].S == -1 || a[i+1].F == -1) continue;
        if(a[i+1].F <= a[i].S){
            if(a[i].S - a[i].F != a[i+1].S - a[i+1].F) {
                wrong = 1;
                break;
            }
        }
    }

    if(wrong) cout << "No";
    else cout << "Yes"; 
}