//作者：张长宇 
//题目：实现算法导论上机题practice 2.3 
//功能：Longest Common Substring
//日期：2018.4.15

#include<iostream> 
#include<vector> 
using namespace std;

bool  Longest_Commom_Substring(vector<char> a,vector<char> b,vector<char>&c){
	vector<char> substring;
	int m=a.size();
	int n=b.size();
	if(m>n){
		vector<char> temp;temp=a;a=b;b=temp;
		int tmp; tmp=m;m=n;n=tmp;
	}
	int i,j;
	for(i=0;i<m;i++){
		substring.clear();
		int index=0;
		for(j=0;j<n;j++){
			if(i+index>m)	break;
			if(a[i+index]==b[j]){
				index++;
				substring.push_back(b[j]);
				if(substring.size()>c.size()){
					c=substring;
				} 
			} 
			else {
				substring.clear();
				index=0;	
			}
		}
		
	} 
	return 0;
}

vector<char>  Longest_Commom_Substring_dp(vector<char> a,vector<char> b){
	int m=a.size();
	int n=b.size();
	if(m>n){
		vector<char> temp;temp=a;a=b;b=temp;
		int tmp; tmp=m;m=n;n=tmp;
	}
	int substring_dp[m][n];
	vector<char> longest_substring;
	int max=0;
	int index=0;
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				substring_dp[i][j]=1;
				if(j>0&&i>0&&substring_dp[i-1][j-1]!=0){
					substring_dp[i][j]=substring_dp[i-1][j-1]+1;
					
				}
				if(substring_dp[i][j]>max){
						max=substring_dp[i][j];
						index=i;
				}
			} 
			else	substring_dp[i][j]=0;
		}
	} 
	for(i=0;i<max;i++)	longest_substring.push_back(a[index-max+1+i]);
	return longest_substring;
}

int main(){
	vector<char> a;
	vector<char> b;
	char ch;
	for(int i=0;;i++){
		cin>>ch;
		a.push_back(ch);
		if(cin.get()=='\n')	break;
	}
	for(int i=0;;i++){
		cin>>ch;
		b.push_back(ch);
		if(cin.get()=='\n')	break;
	}
//	vector<char> c;
//	Longest_Commom_Substring(a,b,c);
	vector<char> c=Longest_Commom_Substring_dp(a,b);
	cout<<'c'<<c.size();
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<' ';
	}
	
	cout<<endl;
	return 0;
}
