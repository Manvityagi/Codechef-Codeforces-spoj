#include <iostream>
using namespace std;

string x, ans;
int t;

void f()
{
    if (cin >> x)
    {
        ans += x;
        if (x == "pair")
        {
            ans += "<";
            f();
            ans += ",";
            f();
            ans += ">";
        }
    }
    else
    {
        t = 1;
    }
}

int main()
{
    int o;
    cin >> o;
    f();
    if (cin >> x || t)
        cout << "Error occurred";
    else
        cout << ans;
    return 0;
}