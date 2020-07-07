#include <bits/stdc++.h>
using namespace std;
#define LL long long

 main()
{
    LL n;
    cin >> n;
    LL qx,qy;
    LL bix,biy,bfx,bfy;

    cin >> qx >> qy >> bix >> bfx >> bfx >> bfy;

    if( ( (bix < qx && bfx < qx) || (bix > qx && bfx > qx) ) && ( (biy < qy && bfy < qy) || (biy > qy && bfy > qy)) ){
        cout << "YES";
        return 0;
    }

    cout << "NO";

    return 0;
}
