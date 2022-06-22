/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1043d Mysterious Crime
 * Date: 12/16/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 7;
const int maxm = 15;
int n, m, temp;
int mn[maxn], ren[maxn], a[maxm][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        ren[a[1][i]] = i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = ren[a[i][j]];

    for (int i = 1; i <= n; ++i)
        mn[i] = n;

    for (int i = 1; i <= m; ++i) {
        temp = 1;
        for (int j = 1; j <= n; ++j) {
            if (temp < j)
                ++temp;

            while (temp < n and a[i][temp + 1] == a[i][temp] + 1)
                ++temp;

            mn[a[i][j]] = min(mn[a[i][j]], a[i][temp]);
        }
    }

    ll res = 0;
    int now = 1;
    while (now <= n) {
        temp = mn[now] - now + 1;
        res += 1LL * (temp + 1) * temp / 2LL;
        now = mn[now] + 1;
    }

    cout << res << "\n";
    return 0;
}