#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // total no. of ways 2 knights can be placed in the chessboard k^2(k^2-1)/2

    for (int k = 1; k <= n; k++)
    {
        ll total = (ll)k * k * (k * k - 1) / 2;
        ll attacking = 4 * (k - 1) * (k - 2);

        cout << total - attacking << endl;
    }

    return 0;
}