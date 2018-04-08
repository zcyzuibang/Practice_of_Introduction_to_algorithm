//���ߣ��ų��� 
//���ܣ�ʵ���㷨���� exercise 2.3-7
//��Ŀ������һ������ʱ��ΪO(nlgn)���㷨������n�������ļ���S����һ������x�����㷨�ܹ�ȷ��S���Ƿ����������͸պ�Ϊx��Ԫ�� 
//���ڣ�2018.3.16   
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

int BinS(int *p,int x,int low,int high){//���ֲ��� 
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
//			cout<<"�����д�������Ԫ�غ�Ϊx"<<endl; 
			return 1;
		}	
	}
//	cout<<"�����в���������Ԫ�غ�Ϊx"<<endl; 
	return 0;
}
