// Created by:
// Sadra Setarehdan
// Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
// Date: 6-22-2022

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main (void){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
    cin>>n;
    int a[n];
    
    for (int i=0;i<n;i++){
    	cin>>a[i];
	}
	
	for  (int i=1;i<n-1;i++){
		if (a[i-1]<a[i] and a[i]>a[i+1]){
			cout<<"Ey baba :(\n";
			return 0;
		}
	}
	
	cout<<"Bah Bah! Ajab jooji!\n";
    return 0;
}
