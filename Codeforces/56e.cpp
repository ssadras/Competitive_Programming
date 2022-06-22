/*
 * author: Seyed Sadra Setarehdan
 * Problem: 56e Domino Principle
 * Date: 12/11/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
int n, h[maxn], dp[maxn], ans[maxn], temp0, temp1;
pair<int, int> a[maxn], temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> h[i];
        a[i].second = i;
    }

    sort(a, a + n);

    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        temp = make_pair(a[i].first + h[a[i].second], -1);
        temp0 = lower_bound(a, a + n, temp) - a - 1;
        temp1 = i + 1;
        while (temp1 <= temp0) {
            if (temp1 + dp[temp1] - 1 >= temp0)
                break;

            temp1 = temp1 + dp[temp1];
        }

        if (temp1 <= temp0)
            dp[i] = temp1 - i + dp[temp1];

        else
            dp[i] = temp0 - i + 1;

    }

    for (int i = 0; i < n; i++)
        ans[a[i].second] = dp[i];

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    cout << "\n";
    return 0;
}
