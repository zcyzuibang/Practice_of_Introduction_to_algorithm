//作者：张长宇 
//题目：实现算法导论上机题practice 2.1 
//功能：Matrix-chain product
//日期：2018.4.16

#include <iostream>
#include <vector>
#include <limits.h>
#include <iomanip>
#include <stdlib.h>
#define max 10
using namespace std;

void MATRIX_CHAIN_ORDER(vector<int> p,vector<vector<int> > &m,vector<vector<int> > &s){
	int n=p.size()-1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			m[i][j]=0;
			s[i][j]=0;
		}
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}

void PRINT_OPTIMAL_PARENGS(vector<vector<int> > s,int i,int j){
	if(i==j){
		cout<<'A'<<i;
	}
	else{
		cout<<'(';
		PRINT_OPTIMAL_PARENGS(s,i,s[i][j]);
		PRINT_OPTIMAL_PARENGS(s,s[i][j]+1,j);
		cout<<')';
	}
}

int main(){
	vector<int> p;
	int num;
	while(1){
		cin>>num;
		p.push_back(num);
		if(cin.get()=='\n')break;
	}
//	p.push_back(30);p.push_back(35);p.push_back(15);p.push_back(5);p.push_back(10);p.push_back(20);p.push_back(25);
	arr_size=p.size();
	vector<int> a(arr_size);
	vector<vector<int> > m(arr_size,a);
	vector<vector<int> > s(arr_size,a);
	
	MATRIX_CHAIN_ORDER(p,m,s);
/*	for(int i=1;i<arr_size;i++){
		for(int j=0;j<arr_size;j++){
			cout <<setw(6)<<m[i][j];
		}
		cout<<endl;
	}*/	
	PRINT_OPTIMAL_PARENGS(s,1,arr_size-1);

	return 0;
}

