/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1277b Make Them Odd
 * Date: 12/4/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, y, ans = 0, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    while (a--) {
        ans=0;
        cin >> y;
        set<int> st;
        for (int i = 1; i <= y; ++i) {
            cin >> x;
            if (x % 2 == 0)
                st.insert(x);
        }

        while (!st.empty()) {
            auto it = st.end();
            it--;
            ans++;
            int sq = (*it) / 2;
            st.erase(*it);
            if (sq % 2 == 0)
                st.insert(sq);
        }

        cout << ans << '\n';
    }
    return 0;
}