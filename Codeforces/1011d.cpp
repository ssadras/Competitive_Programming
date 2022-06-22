/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1011d Rocket
 * Date: 12/3/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 102;
int x, n, t, arr[maxn];

int ask (int b){
    cout<<b<<endl;
    int a;
    cin>>a;
    return a;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        t=ask(1);
        if (t == 0) {
            cout << endl;
            return 0;
        }
        if (t == 1)
            arr[i] = 1;
        if (t == -1)
            arr[i] = -1;
    }

    cout << endl;

    int l = 1, r = x, mid, now = 1;

    while (l <= r) {
        mid = (l + r) / 2;
        t=ask(mid);
        if (t == 0) {
            cout << endl;
            return 0;
        }
        if (arr[now] == -1)
            t *= -1;

        if (t == 1)
            l = mid + 1;
        else
            r = mid - 1;

        now++;
        if (now > n)
            now = 1;
    }

    return 0;
}