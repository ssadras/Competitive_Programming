/*
 * author: Seyed Sadra Setarehdan
 * Problem: c Vacation
 * Date: 11-12-2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n, dp[maxn][3], a[maxn], b[maxn], c[maxn];

int solve(int day, int before) {
    if (day == n - 1) {
        if (before == 0)
            return max(b[day], c[day]);
        else if (before == 1)
            return max(a[day], c[day]);
        else if (before == 2)
            return max(a[day], b[day]);
        else
            return max(a[day], max(b[day], c[day]));
    }
    if (before != -1)
        if (dp[day][before] != -1)
            return dp[day][before];

    int ans[3] = {0, 0, 0};
    if (before != 0)
        ans[0] = a[day] + solve(day + 1, 0);
    if (before != 1)
        ans[1] = b[day] + solve(day + 1, 1);
    if (before != 2)
        ans[2] = c[day] + solve(day + 1, 2);
    //cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<"\n";
    return dp[day][before] = max(ans[0], max(ans[1], ans[2]));

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    cout << solve(0, -1) << "\n";

    return 0;
}
