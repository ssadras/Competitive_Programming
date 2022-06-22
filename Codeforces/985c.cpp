/*
 * author: Seyed Sadra Setarehdan
 * Problem: 985c Liebig's Barrels
 * Date: 12/9/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
ll n, k, l, ans;
ll a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> l;
    for (int i = 0; i < n * k; i++)
        cin >> a[i];

    sort(a, a + n * k);

    if (a[n - 1] - a[0] > l) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        ans += a[i];

    int m = 1;

    for (int i = n; i <= n * k - k; i++) {
        if (a[i] - a[0] <= l) {
            ans += a[i];
            ans -= a[m++];
        } else
            break;

        if (m % k == 0)
            m++;
    }
    cout << ans << "\n";
    return 0;
}