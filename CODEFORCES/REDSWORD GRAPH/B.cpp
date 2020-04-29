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

int m = 8, n = 8, r1, c1, r2, c2;

bool valid(int i, int j)
{
    return (i >= 1 && j >= 1 && i <= m && j <= n);
}

int row[] = {0, 0, -1, 1, -1, -1, 1, 1};
int col[] = {1, -1, 0, 0, 1, -1, 1, -1};
struct Node
{
    int x, y, dist;

    Node(int x, int y, int dist = 0) : x(x), y(y), dist(dist) {}
    bool operator<(const Node &o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

int rook()
{
    if (r1 == r2 || c1 == c2)
        return 1;
    return 2;
}

int bishop()
{

    if ((r1 + c1) % 2 != (r2 + c2) % 2)
        cout << 0;
    else
    {
        if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2)
            cout << 1;
        else
            cout << 2;
    }

    return 0;
}

int king()
{
    return max(abs(r1 - r2), abs(c1 - c2));
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> r1 >> c1 >> r2 >> c2;
    //rook - hor or ver
    cout << rook() << " ";

    //bishop - diagonally
    cout << bishop() << " ";

    //king - hor,ver,dia
    cout << king() << " ";

    return 0;
}
