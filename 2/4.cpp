#include <iostream>
#define arr_size 100
using namespace std;

template<typename T>
T Largest_Sum_of_Subarray_dp(T A[],int a_size){
	T max=A[0],sum_dp[a_size];
	sum_dp[0]=A[0];
	for(int i=1;i<a_size;i++){
		if(sum_dp[i-1]+A[i]>A[i])	{
			sum_dp[i]=sum_dp[i-1]+A[i];
			if(sum_dp[i]>max)	max=sum_dp[i];	
		}
		else sum_dp[i]=A[i];
	}
	return max;
}

template<typename T>
T Largest_Sum_of_Subarray(T A[],int a_size){
	T max=A[0],sum=0;
	for(int i=0;i<a_size;i++){
		if(sum+A[i]>0)	{
			sum+=A[i];
			if(sum>max)	max=sum;	
		}
		else sum=0;
	}
	if(max<0){
		for(int i=0;i<a_size;i++){
			if(A[i]>max)	max=A[i];
		}
	}
	return max;
}

int main(){
	int a[arr_size];
	int i=0;
	for(;cin>>a[i];i++){}
	cout<<Largest_Sum_of_Subarray_dp(a,i)<<endl;
	return 0;
}

