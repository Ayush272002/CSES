#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll solve(vector<ll> &coins, ll x, vector<ll> &dp)
{
    if (x == 0)
        return 1;

    if (x < 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    int ways = 0;
    for (auto &coin : coins)
        ways = (ways + solve(coins, x - coin, dp)) % MOD;

    return dp[x] = ways;
}

ll solve2(vector<ll> &coins, ll x)
{
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (auto &coin : coins)
        {
            if (i >= coin)
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    return dp[x];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // vector<ll> dp(x + 1, -1);
    // cout << solve(coins, x, dp) << endl;

    cout << solve2(coins, x) << endl;

    return 0;
}