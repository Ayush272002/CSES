#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    set<ll> st;

    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        st.insert(val);
    }

    cout << st.size() << endl;
}