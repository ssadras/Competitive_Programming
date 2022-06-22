/*
 * author: Seyed Sadra Setarehdan
 * Problem: 761d Dasha and Very Difficult Problem
 * Date: 12/9/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 10;
pair<ll, pair<ll, ll>> c[maxn];
pair<ll, ll> m[maxn];
ll a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, l, r;
    cin >> n >> l >> r;
    for (ll i = 1; i <= n; i++) {
        cin >> c[i].second.first;
        c[i].second.second = i;
    }

    for (ll i = 1; i <= n; i++)
        cin >> c[i].first;

    sort(c + 1, c + n + 1);

    for (ll i = 1; i <= n; i++)
        a[i] = c[i].second.first;

    b[1] = l;
    for (ll i = 2; i <= n; i++) {
        ll s = l - a[i], e = r - a[i];
        if (b[i - 1] - a[i - 1] > e) {
            cout << -1 << "\n";
            return 0;
        }

        ll d = max(b[i - 1] - a[i - 1] + 1, s);
        b[i] = d + a[i];
        if (b[i] > r or b[i] < l) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (ll i = 1; i <= n; i++) {
        m[i].first = c[i].second.second;
        m[i].second = b[i];
    }

    sort(m + 1, m + n + 1);

    for (ll i = 1; i <= n; i++)
        cout << m[i].second << ' ';

    cout << "\n";
    return 0;
}