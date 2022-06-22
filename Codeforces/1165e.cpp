/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1165e Two Arrays and Sum of Functions
 * Date: 12/9/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;
const int MOD = 998244353;
int n;
vector<int> a,b;
vector<pair<ll, int>> val;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    sort(b.begin(), b.end());

    val.resize(n);
    for (int i = 0; i < n; ++i) {
        val[i].first = (i + 1) * 1ll * (n - i) * a[i];
        val[i].second = i;
    }

    sort(val.rbegin(), val.rend());

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + (val[i].first % MOD * 1LL * b[i]) % MOD) % MOD;

    cout << ans << "\n";

    return 0;
}