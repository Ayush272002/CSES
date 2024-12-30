#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll y, x;
    cin >> y >> x;

    if (y > x)
    {
        if (y % 2 == 0)
            cout << (y * y - (x - 1)) << endl;
        else
            cout << ((y - 1) * (y - 1)) + 1 + (x - 1) << endl;
    }
    else
    {
        if (x % 2 == 0)
            cout << (x - 1) * (x - 1) + 1 + (y - 1) << endl;
        else
            cout << x * x - (y - 1) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}