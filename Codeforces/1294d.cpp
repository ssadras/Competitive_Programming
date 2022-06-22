/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1294d MEX maximizing
 * Date: 12/5/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q, x,cur;
set<pair<int, int>> vals;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q >> x;
    vector<int> mods(x);

    for (int i = 0; i < x; ++i)
        vals.insert(make_pair(mods[i], i));

    for (int i = 0; i < q; ++i) {
        cin >> cur;
        cur %= x;
        vals.erase(make_pair(mods[cur], cur));
        mods[cur]++;
        vals.insert(make_pair(mods[cur], cur));
        cout << (*(vals.begin())).first * x + (*(vals.begin())).second << "\n";
    }

    return 0;
}