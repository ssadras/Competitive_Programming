/*
 * author: Seyed Sadra Setarehdan
 * Problem: 567d One-Dimensional Battle Ships
 * Date: 12/11/2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
int n, k, a, m, cur;
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> a;
    cin >> m;
    s.insert(0);
    s.insert(n + 1);
    cur=(n+1)/(a+1);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        auto prv = s.lower_bound(x);
        auto nxt = prv;
        prv--;
        cur -= (*nxt - *prv) / (a + 1);
        cur+=(x-*prv)/(a+1);
        cur+=(*nxt-x)/(a+1);
        s.insert(x);
        if (cur<k){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
    return 0;

    return 0;
}