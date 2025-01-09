#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(ll n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    ll temp = n;

    while (temp > 0)
    {
        int digit = temp % 10;
        temp /= 10;

        if (digit > 0)
            ans = min(ans, 1 + solve(n - digit, dp));
    }

    return dp[n] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << solve(n, dp) << endl;

    return 0;
}