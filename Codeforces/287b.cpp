/*
 * author: Seyed Sadra Setarehdan
 * Problem: 287b Pipeline
 * Date: 12-1-2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, l, r, mid, temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    r = k + 2;

    while (l + 1 < r) {
        mid = (l + r) >> 1;
        temp = k * (k + 1) / 2 - (mid - 1) * mid / 2 - (k - mid);
        if (temp >= n)
            l = mid;
        else
            r = mid;
    }

    if (l == 0 or l == k + 1) {
        cout << -1 << "\n";
        return 0;
    }

    cout << k - l + 1 << "\n";
    return 0;
}