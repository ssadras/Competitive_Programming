/*
 * author: Seyed Sadra Setarehdan
 * Problem: 923a Primal Sport
 * Date: 12/9/2020
 */

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
int x2, temp1, a[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x2;
    for (int i = 2; i <= x2; i++)
        if (!a[i])
            for (int j = i * 2; j <= x2; j += i)
                a[j] = i;

    temp1 = x2;
    for (int i = x2 - a[x2] + 1; i <= x2; i++)
        if (i - a[i] + 1 < temp1)
            temp1 = i - a[i] + 1;

    cout << temp1 << "\n";
}