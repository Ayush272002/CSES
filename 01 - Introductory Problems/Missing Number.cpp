#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll expectedSum = n * (n + 1) / 2;

    ll sum = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll val;
        cin >> val;
        sum += val;
    }

    cout << (expectedSum - sum) << endl;
    return 0;
}