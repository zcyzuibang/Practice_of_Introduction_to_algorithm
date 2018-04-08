//作者：张长宇 
//功能：实现快速排序 
//日期：2018.4.4  
//
#include <iostream>
#define arr_size 100
using namespace std;
template<typename T>
void quick_sort(T A[],int low,int high){
	if(low<high){
		int index=low;
		T temp;
		for(int i=low;i<high;i++){
			if(A[i]<=A[high]){
				temp=A[i];
				A[i]=A[index];
				A[index]=temp;
				index++;
			}
		}
		temp=A[high];
		A[high]=A[index];
		A[index]=temp;
		quick_sort(A,low,index-1);
		quick_sort(A,index+1,high);	
	}
} 
int main(){
	int a[arr_size]={0};
	int i=0,j=0;
	for(;cin>>a[i];i++){}
	quick_sort(a,0,i-1);
	for(j=0;j<i;j++)	cout<<a[j]<<' ';
	return 0;
}          
