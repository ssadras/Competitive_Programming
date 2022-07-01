# Created by:
# Sadra Setarehdan
# Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
# Date: 6-22-2022

#include<iostream>

using namespace std;


int main() {
    int n;
    long long int m=1;
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        m = m * i;
    }

    cout<<m<<endl;
    return 0;

}
