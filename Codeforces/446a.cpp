/*
 * author: Seyed Sadra Setarehdan
 * Problem: 446a DZY Loves Sequences
 * Date: 12/10/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
int n, arr[maxn], dp[maxn], ans = 1, l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1])
            l = i;

        dp[i] = i - l + 1;
        int x = 0;
        if (l != 0) {
            x = 1;

            if (l != 1 and arr[l] > arr[l - 2] + 1)
                x += dp[l - 2];

            if (l != i and arr[l + 1] > arr[l - 1] + 1)
                x = max(x, dp[l - 1]);

        }

        ans = max(ans, max(dp[i] + x, dp[i - 1] + 1));
    }

    cout << ans << "\n";

    return 0;
}
