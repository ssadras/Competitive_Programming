/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1148b Born This Way
 * Date: 12/15/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 10;
ll n, m, ta, tb, k, ans;
ll a[maxn], b[maxn];
bool flag = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> ta >> tb >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    if (k >= n) {
        cout << -1 << "\n";
        return 0;
    }

    ll ptr = 0;
    for (int i = 0; i <= k; i++) {
        while (ptr < m && a[i] + ta > b[ptr])
            ptr++;

        if (ptr + (k - i) >= m)
            flag = true;

        else
            ans = max(ans, b[ptr + (k - i)] + tb);
    }

    if (flag)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}