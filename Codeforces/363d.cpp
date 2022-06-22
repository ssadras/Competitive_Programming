/*
 * author: Seyed Sadra Setarehdan
 * Problem: 363d Renting Bikes
 * Date: 12/3/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10, inf = 1e9;

ll n, m, a, b[maxn], p[maxn];

bool check(ll mid) {
    ll aa = a;
    ll j = n - mid;

    for (ll i = 0; i < mid; i++, j++)
        aa -= max(0LL, p[i] - b[j]);

    if (aa >= 0)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a;
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    for (ll i = 0; i < m; i++)
        cin >> p[i];

    sort(b, b + n);
    sort(p, p + m);

    ll l = 0, r = min(n, m);
    while (l < r - 1) {
        ll mid = (l + r) >> 1;
        if (check(mid) == 1)
            l = mid;
        else
            r = mid;
    }

    if (check(l + 1) == 1)
        l++;

    ll sum = 0;
    for (ll i = 0; i < l; i++)
        sum += p[i];

    cout << l << " " << max(0LL, sum-a)<<"\n";

    return 0;
}