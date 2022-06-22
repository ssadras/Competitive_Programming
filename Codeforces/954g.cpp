/*
 * author: Seyed Sadra Setarehdan
 * Problem: 954g Castle Defense
 * Date: 12/8/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 500500;
const ll INF = 1e18;
ll a[maxn], sum[maxn];
int b[maxn];
int n, r;
ll k;

int check(ll mid) {
    for (int i = 1; i <= n; i++)
        sum[i] = 0;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] + a[i] < mid) {
            ll add = mid - (sum[i] + a[i]);
            res += add;
            if (res > k)
                return 0;
            sum[i] += add;
            if (i + 2 * r < n)
                sum[i + 2 * r + 1] -= add;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + b[i];

    for (int i = 1; i <= n; i++)
        a[i] = sum[min(n, i + r)] - sum[max(1, i - r) - 1];


    ll lo = 0, hi = 2 * INF + 1;

    while (lo + 1 < hi) {
        ll mid = lo + hi >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << "\n";
    return 0;
}