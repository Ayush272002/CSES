#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

typedef long long ll;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

ll MOD = 1e9 + 7;

ll solve(vector<ll> &coins, ll target, int idx, vector<vector<ll>> &dp)
{
    if (target == 0)
        return 1;

    if (idx >= coins.size() || target < 0)
        return 0;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    ll count = 0;

    // take
    count += solve(coins, target - coins[idx], idx, dp);

    // skip
    count += solve(coins, target, idx + 1, dp);

    return dp[idx][target] = count % MOD;
}

ll solve2(vector<ll> &coins, ll x)
{
    int n = coins.size();
    vector<vector<ll>> dp(n, vector<ll>(x + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (i > 0)
                dp[i][j] = dp[i - 1][j];

            if (j >= coins[i])
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i]]) % MOD;
        }
    }

    return dp[n - 1][x];
}

ll solve3(vector<ll> &coins, ll x)
{
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (ll coin : coins)
    {
        for (ll j = coin; j <= x; j++)
        {
            if (j - coin >= 0)
            {
                dp[j] = (dp[j] + dp[j - coin]) % MOD;
            }
        }
    }

    return dp[x];
}

ll solve4(vector<ll> &coins, ll target)
{
    int n = coins.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - coins[i - 1];

            if (left >= 0)
                (dp[i][j] += dp[i][left]) %= MOD;
        }
    }

    return dp[n][target];
}

void optimalSol()
{
    int mod = 1e9 + 7;
    int n, target;
    cin >> n >> target;
    vector<int> x(n);
    for (int &v : x)
        cin >> v;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - x[i - 1];
            if (left >= 0)
            {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    cout << dp[n][target] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fastio();
    auto start1 = high_resolution_clock::now();

    // int n;
    // ll x;

    // cin >> n >> x;

    // vector<ll> coins(n);
    // for (int i = 0; i < n; i++)
    //     cin >> coins[i];

    // vector<vector<ll>> dp(n, vector<ll>(x + 1, -1));

    // cout << solve(coins, x, 0, dp) << endl;

    // cout << solve2(coins, x) << endl;

    // cout << solve3(coins, x) << endl;

    // cout << solve4(coins, x) << endl;

    optimalSol();

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    cerr << "Time: " << duration.count() / 1000 << endl;
    return 0;
}