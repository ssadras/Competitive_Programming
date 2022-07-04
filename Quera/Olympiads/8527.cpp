// Created by:
// Sadra Setarehdan
// Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
// Date: 7-4-2022

#include<iostream>

using namespace std;
const int maxn = 1e6 + 100;

int n, ans, temp1, temp2;
int a[maxn], b[maxn], c[maxn];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    b[n - 1] = a[n - 1];
    c[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        b[i] = b[i + 1];
        c[i] = c[i + 1];

        if (a[i] > b[i + 1]) {
            b[i] = a[i];
            c[i] = i;
        }
    }

    while (temp1 != n - 1) {
        if (b[temp1 + 1] < a[temp1]) {
            for (int i = temp1 + 1; i < c[temp1 + 1]; i++)
                ans += (b[temp1 + 1] - a[i]);

            temp1 = c[temp1 + 1];
        } else {
            for (int i = temp1 + 1; i < n; i++)
                if (a[i] >= a[temp1]) {
                    temp2 = i;
                    break;
                }

            for (int i = temp1 + 1; i < temp2; i++)
                ans += (a[temp1] - a[i]);

            temp1 = temp2;
        }
    }

    cout << ans << "\n";
    return 0;
}
