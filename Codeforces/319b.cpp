/*
 * author: Seyed Sadra Setarehdan
 * Problem: 319b Psychos in a Line
 * Date: 12-2-2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 1;
int a[maxn], i, ans = 0, c, n;
stack<pair<int, int>> s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i < n + 1; ++i)
        cin >> a[i];

    s.push({a[n], 0});

    for (i = n - 1; i >= 1; --i) {
        c = 0;

        while ((ll) s.size() and a[i] > s.top().first) {
            c = max(s.top().second, c + 1);
            s.pop();
        }

        s.push({a[i], c});

        ans = max(ans, c);
    }

    cout << ans << "\n";

    return 0;
}