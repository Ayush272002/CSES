#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;

    ll count = 1;
    ll ans = 1;
    for (ll i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            ans = max(ans, count);
        }
        else
        {
            count = 1;
        }
    }

    cout << ans << endl;

    return 0;
}