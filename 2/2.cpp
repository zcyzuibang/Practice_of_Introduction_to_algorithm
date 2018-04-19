//作者：张长宇 
//题目：实现算法导论上机题practice 2.2 
//功能：Longest Common Subsequence
//日期：2018.4.16

#include<iostream> 
#include<vector> 
using namespace std;

inline int max(int a,int b){
	return a>b?a:b;
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
	int i,j;
	for(i=0;i<m;i++){
		substring_dp[i][0]=0;
		if(a[0]==b[i]){
			substring_dp[i][0]=1;	
		}	
		if(i>0){
				substring_dp[i][0]=max(substring_dp[i][0],substring_dp[i-1][0]);
		}
	}
	for(j=0;j<n;j++){
		substring_dp[0][j]=0;
		if(b[0]==a[j]){
			substring_dp[0][j]=1;
			
		}	
		if(j>0)	{
				substring_dp[0][j]=max(substring_dp[0][j],substring_dp[0][j-1]);
		}
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			substring_dp[i][j]=max(substring_dp[i-1][j],substring_dp[i][j-1]);
			if(a[i]==b[j]){
				substring_dp[i][j]=max(substring_dp[i][j],substring_dp[i-1][j-1]+1);
			}		
		}
	} 
	int index;
	int max_size=substring_dp[i-1][j-1];
	
	for(index=max_size-1;index>=0;){
		if(n-1>0&&substring_dp[m-1][n-1]==substring_dp[m-1][n-2])	--n;
		else if(m-1>0&&substring_dp[m-1][n-1]==substring_dp[m-2][n-1])	--m;
		else{
			longest_substring.push_back(b[n-1]);
			--index;
			--m;
			--n;
		}
	}
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
	vector<char> c=Longest_Commom_Substring_dp(a,b);
//	cout<<'c'<<c.size();
	int size=c.size();
	for(int i=0;i<size;i++){
		cout<<c[size-i-1]<<' ';
	}
	cout<<endl;
	return 0;
}
