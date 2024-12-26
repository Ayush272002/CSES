#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

ll solve(ll n)
{
    vector<ll> dp(n + 1, 0);

    dp[0] = 1;

    int ways = 0;

    for (ll i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[n];
}

int main()
{
    ll n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}