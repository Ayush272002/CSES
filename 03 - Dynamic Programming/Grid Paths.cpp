#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll solve(vector<vector<char>> &grid, int r, int c, vector<vector<ll>> &dp)
{
    if (r == grid.size() - 1 && c == grid[0].size() - 1 && grid[r][c] == '.')
        return 1;

    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '*')
        return 0;

    if (dp[r][c] != -1)
        return dp[r][c];

    ll ans = 0;
    ans += solve(grid, r + 1, c, dp);
    ans %= MOD;

    ans += solve(grid, r, c + 1, dp);
    ans %= MOD;

    return dp[r][c] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[0][0] == '*')
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    cout << solve(grid, 0, 0, dp) << endl;
    return 0;
}