#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll count = 0;

    for (ll i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            count += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << count << endl;

    return 0;
}