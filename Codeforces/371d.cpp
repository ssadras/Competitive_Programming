/*
 * author: Seyed Sadra Setarehdan
 * Problem: 371d Vessels
 * Date: 12/4/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const ll inf = 1e17;

ll ns[N], a[N], b[N];
int n, m, t, x, y;

void add(ll temp1, ll temp2) {
    ll ans;
    ans = max(b[temp1] + temp2 - a[temp1], 0ll);
    b[temp1] += temp2 - ans;

    if (ans > 0ll)
        add(ns[temp1], ans);

    if (b[ns[temp1]] == a[ns[temp1]])
        ns[temp1] = ns[ns[temp1]];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ns[i] = i + 1;
    }

    a[n] = inf;
    cin >> m;

    while (m--) {
        cin >> t >> x;
        x--;
        t--;
        if (t)
            cout << b[x] << endl;
        else {
            cin >> y;
            add(x, y);
        }
    }

    return 0;
}

