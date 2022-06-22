/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1166c A Tale of Two Lands
 * Date: 12/10/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
ll n, ans, a[maxn];
int l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(a, a + n);

    r = 1;

    while (l < n and r < n) {
        if (a[r] - a[l] <= a[l]) {
            ans += r - l;
            r++;
        } else
            l++;
    }

    cout << ans << "\n";
    return 0;
}