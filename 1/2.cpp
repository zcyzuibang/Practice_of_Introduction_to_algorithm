//作者：张长宇 
//题目：实现优先队列 
//日期：2018.4.7 


#include <iostream>
#define arr_size 100
using namespace std;

template<typename T>
inline
void Swap(T A[],int x,int y){
	T temp=A[x];
	A[x]=A[y];
	A[y]=temp;
}

int Parent(int i){
	return i/2;
} 

int Left(int i){
	return i*2;
}

int Right(int i){
	return i*2+1;
}

int A_length=0;

template<typename T>
void MAX_HEAPIFY(T A[],int i){
	int l=Left(i);
	int r=Right(i);
	int largest=i;
	if(l<=A_length&&A[l]>A[i])	largest=l;
	if(r<=A_length&&A[r]>A[largest])	largest=r;
	if(largest!=i){
		Swap(A,i,largest);
		MAX_HEAPIFY(A,largest);
	}
}

template<typename T>
void BUILD_MAX_HEAPIFY(T A[],int i){
	for(int j=i/2;j>=1;j--){
		MAX_HEAPIFY(A,j);
	}
}

template<typename T>
void INSERT(T A[],T x){
	int i=A_length;
	A[i]=x;
	A_length++;
	while(i>1&&A[Parent(i)]<A[i]){
		Swap(A,i,Parent(i));	
		i=Parent(i);
	}
}

template<typename T>
T MAXIMUM(T A[]){
	return A[1];
}

template<typename T>
T EXTRACT_MAX(T A[]){
	T max=A[1];
	A[1]=A[A_length-1];
	A_length-=1;
	MAX_HEAPIFY(A,1);
	return max;
}

template<typename T>
void INSRASE_KEY(T A[],int i,T x){
	A[i]=x;
	if(A[Parent(i)]<A[i]){
		while(i>1&&A[Parent(i)]<A[i]){
			Swap(A,i,Parent(i));
			i=Parent(i);
		}	
	}
	else MAX_HEAPIFY(A,i);
	
}

int main(){
	int A[arr_size]={0};
	int i;
	for(A_length=1;cin>>A[A_length];A_length++){
	}
//	cout<<A_length<<endl;
	BUILD_MAX_HEAPIFY(A,A_length-1);
	
	for(int j=1;j<A_length;j++){
		cout<<"A["<<j<<"]: "<<A[j]<<endl;
	}
	cout <<"MAXIMUM: "<<MAXIMUM(A)<<endl;
	cout <<"EXTRACT_MAX: "<<EXTRACT_MAX(A)<<endl;
	for(int j=1;j<A_length;j++){
		cout<<"A["<<j<<"]: "<<A[j]<<endl;
	}
	INSERT(A,99);
	cout<<"insrdt: "<<endl;
	for(int j=1;j<A_length;j++){
		cout<<"A["<<j<<"]: "<<A[j]<<endl;
	}
	INSRASE_KEY(A,2,5);
	cout<<"insrdt: "<<endl;
	for(int j=1;j<A_length;j++){
		cout<<"A["<<j<<"]: "<<A[j]<<endl;
	}
	return 0;
}




