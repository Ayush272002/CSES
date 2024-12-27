#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
ll solve(vector<ll> &coins, ll target, vector<ll> &dp)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return LLONG_MAX;

    if (dp[target] != -1)
        return dp[target];

    ll curr = LLONG_MAX;

    for (ll i = 0; i < coins.size(); i++)
    {
        if (target - coins[i] >= 0)
        {
            ll sub_res = solve(coins, target - coins[i], dp);
            if (sub_res != LLONG_MAX)
                curr = min(curr, sub_res + 1);
        }
    }

    return dp[target] = curr;
}
*/

ll solve(vector<ll> &coins, ll target)
{
    vector<ll> dp(target + 1, LLONG_MAX);
    dp[0] = 0;

    for (ll coin : coins)
    {
        for (ll j = coin; j <= target; j++)
        {
            if (dp[j - coin] != LLONG_MAX)
                dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    return dp[target];
}

int main()
{
    int n;
    ll x;

    cin >> n >> x;

    vector<ll> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // vector<ll> dp(x + 1, -1);
    // ll result = solve(coins, x, dp);

    ll result = solve(coins, x);

    if (result == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}