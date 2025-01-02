#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum % 2 != 0)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    ll target = sum / 2;
    vector<ll> set1, set2;

    for (ll i = n; i >= 1; i--)
    {
        if (target >= i)
        {
            set1.push_back(i);
            target -= i;
        }
        else
            set2.push_back(i);
    }

    cout << set1.size() << endl;
    for (ll x : set1)
        cout << x << " ";

    cout << endl;

    cout << set2.size() << endl;
    for (ll x : set2)
        cout << x << " ";

    cout << endl;

    return 0;
}