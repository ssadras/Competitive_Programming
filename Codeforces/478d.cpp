/*
 * author: Seyed Sadra Setarehdan
 * Problem: 478d Red-Green Towers
 * Date: 12-2-2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
int r, g, h;
int dp[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> g;
    for (int i = 0; i <= r; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (h = 1; (h * (h + 1)) / 2 <= r + g; h++) {
    }
    h--;
    dp[0] = 1;

    for (int i = 1; i <= h; i++)
        for (int j = r; j >= i and (i * (i + 1)) / 2 - j <= g; j--)
            dp[j] = (dp[j] + dp[j - i]) % MOD;

    int ans = 0;
    for (int i = max(0, (h * (h + 1)) / 2 - g); i <= r; i++)
        ans = (ans + dp[i]) % MOD;

    cout << ans << "\n";

    return 0;
}