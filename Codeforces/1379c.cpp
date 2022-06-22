/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1379c Choosing flowers
 * Date: 12-1-2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
const int INF = 1e9 + 100;
int t, n, m, num;
ll temp, ans, part[maxn];
pair<int, int> f[maxn];

int lowbd(int x) {
    int l = 0, r = m + 2;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (f[mid].first >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
            cin >> f[i].first >> f[i].second;

        f[0] = {-1, 0};
        sort(f, f + m + 1);

        f[m + 1] = {INF, 0};

        part[m + 1] = 0;
        for (int i = m; i > 0; i--)
            part[i] = part[i + 1] + f[i].first;

        ans = 0;
        for (int i = 1; i <= m; i++) {
            temp = 0;
            int ind = lowbd(f[i].second);

            if (ind > i) {
                temp = f[i].first;
                ind = max(ind, m + 1 - n + 1);
                num = n - (m + 1 - ind + 1);
            } else {
                ind = max(ind, m + 1 - n);
                num = n - (m + 1 - ind);
                if (ind > i) {
                    temp = f[i].first;
                    ind++;
                    num = n - (m + 1 - ind + 1);
                }
            }

            temp += part[ind];
            temp += 1ll * num * f[i].second;
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
    return 0;
}