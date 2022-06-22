/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1140c Playlist
 * Date: 12/4/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;
int n, k;
ll res = 0, sum = 0;
pair<int, int> a[maxn];
set<pair<int, int> > s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i].second >> a[i].first;

    sort(a, a + n);

    for (int i = n - 1; i >= 0; i--) {
        s.insert(make_pair(a[i].second, i));
        sum += a[i].second;

        while (s.size() > k) {
            auto it = s.begin();
            sum -= (*it).first;
            s.erase(it);
        }

        res = max(res, sum * a[i].first);
    }

    cout << res << "\n";
    return 0;
}