//作者：张长宇 
//功能：实现算法导论 exercise 2.3-7
//题目：描述一个运行时间为O(nlgn)的算法，给定n个整数的集合S和另一个整数x，该算法能够确定S中是否存在两个其和刚好为x的元素 
//日期：2018.3.16   
//
#include <iostream>
#define arr_size 100
#define arr_count 9
using namespace std;

void Merge(int A[], int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int B[arr_size];
	int C[arr_size];
	for (int i = 0; i<n1; i++)	B[i] = A[low + i ];
	for (int i = 0; i<n2; i++)	C[i] = A[mid + i+1];
	int a_count = 0, b_count = 0;
	for (int i = 0; i<high - low +1; i++) {
		if (a_count >= n1&&b_count<n2) {
			A[low+i] = C[b_count];
			b_count++;
			continue;
		}
		if (b_count >= n2&&a_count<n1) {
			A[low+i] = B[a_count];
			a_count++;
			continue;
		}
		if (B[a_count] <= C[b_count]) {
			A[low+i] = B[a_count];
			a_count++;
		}
		else {
			A[low+i] = C[b_count];
			b_count++;
		}
	}
}

void Merge_Sort(int A[], int low, int high) {
	if (low<high) {
		int mid = (low + high) / 2;
		Merge_Sort(A, low, mid);
		Merge_Sort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}

int BinS(int *p,int x,int low,int high){//二分查找 
	int low_new,high_new,token;
	if(low<high){
		token=(low+high)/2;
		if(x==p[token])	return 1;
		else if(x<p[token]) return BinS(p,x,low,token);
		else return BinS(p,x,token+1,high);
	}
	return 0;
} 

int main(){
	int a[arr_size]={0};
	int i,j;
	for(i=1;;i++){
		cin>>a[i-1];
		if(cin.get()=='\n') break;
	}
	int x;
	cin >> x;
	Merge_Sort(a,0,i-1);
	for(int j=0;j<i;j++){
		if(BinS(a,x-a[j],0,i-1)){
//			cout<<"集合中存在两个元素和为x"<<endl; 
			return 1;
		}	
	}
//	cout<<"集合中不存在两个元素和为x"<<endl; 
	return 0;
}
