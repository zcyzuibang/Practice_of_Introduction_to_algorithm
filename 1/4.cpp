//作者：张长宇 
//题目：实现算法导论上机题practice 1.4 
//功能：．	Give a divide and conquer algorithm for the following problem: 
//			you are given two sorted lists of size m and n, 
//			and are allowed unit time access to the ith element of each list.
// 			Give an O(lg m + lgn) time algorithm for computing the kth largest element in the union of the two lists. 
//			(For simplicity, you can assume that the elements of the two lists are distinct).
//日期：2018.4.7   

#include <iostream>
#include <vector>
#define arr_size 100
#define arr_count 9
using namespace std;

template<typename T>
vector<int> Divide(T m[], T n[], int ml, int mh, int nl, int nh) {
	vector<int> index;//保存两个数组拆分的位置 
	if (ml<mh&&nl<nh) {// m，n数组都不只剩一个元素 
		int mm = (ml + mh) / 2;
		int nm = (nl + nh) / 2;
		if (m[mm] <= n[nm + 1] && n[nm] <= m[mm + 1]) {
			index.push_back(mm);
			index.push_back(nm);
			return index;
		}
		else if (m[mm]>n[nm + 1]) {
			return Divide(m, n, ml, mm, nm + 1, nh);
		}
		else return Divide(m, n, mm + 1, mh, nl, nm);
	}
	else if (ml == mh&&nl == nh) {//m，n数组都只剩一个元素 
		if (m[mh] < n[nh]) {
			index.push_back(mh);
			index.push_back(nh-1);
			return index;
		}
		else {
			index.push_back(mh-1);
			index.push_back(nh);
			return index;
		}
	}
	else if (ml == mh) {//m数组只剩一个元素，n不只剩一个元素 
		int nm = (nl + nh) / 2;
		if (m[mh] <= n[nm + 1] && n[nm] <= m[mh]) {
			index.push_back(mh);
			index.push_back(nm);
			return index;
		}
		else if (m[mh]>n[nm + 1]) {
			return Divide(m, n, ml, mh, nm + 1, nh);
		}
		else return Divide(m, n, mh , mh, nl, nm);
	}
	else if (nl == nh) {//n数组只剩一个元素，m不只剩一个元素 
		int mm = (ml + mh) / 2;
		if (m[mm] <= n[nh] && n[nh] <= m[mm+1]) {
			index.push_back(mm);
			index.push_back(nh);
			return index;
		}
		else if (m[mm]>n[nh]) {
			return Divide(m, n, ml, mm, nh, nh);
		}
		else return Divide(m, n, mm + 1, mh, nl, nh);
	}
}

template<typename T>
T Kth_Largest(int k, T m[], T n[], int ml, int mh, int nl, int nh){
	vector<int> index=Divide(m, n, ml, mh, nl, nh);
	if(index[0]==0){//m数组中最小的元素都比n数组中最大的大 
		if(k<=mh) {
			return m[mh-k+1];
		}
		else {
			return n[nh-(k-mh)+1];
		}
	}
	if(index[1]==0){//n数组中最小的元素都比m数组中最大的大 
		if(k<=nh) {
			return n[nh-k+1];	
		}
		else {
			return m[mh-(k-nh)+1];
		}
	}
//	for(int i=0;i<2;i++)	cout<<index[i]<<endl;
	int num_right=mh-index[0]+nh-index[1];
	if(num_right==k) {
		return m[index[0]+1]>n[index[1]+1]?n[index[1]+1]:m[index[0]+1];
		//分解之后右边的元素个数等于k，返回右边第k大的数（m[index[0]+1]与n[index[1]+1]中小的数） 
	}
	else if(num_right>k){//分解之后右边的元素个数大于k，在右边寻找第k大的数
		return Kth_Largest(k,m,n,index[0]+1,mh,index[1]+1,nh);
	}
	else {//分解之后右边的元素个数小于k，在左边寻找第k-num_right大的数
		return Kth_Largest(k-num_right,m,n,ml,index[0],nl,index[1]);
	}
}

int main() {
	int m[arr_size] = { 0 };
	int n[arr_size] = { 0 };
	int mh, nh;
	for( mh=1;;mh++ ){//输入数组m的元素 
		cin >> m[mh];
		if(cin.get()=='\n')break;
	}
	for( nh=1;;nh++){//输入数组n的元素 
		cin >> n[nh];
		if(cin.get()=='\n')break;
	}
	cout<<"m: "<<mh<<" n: "<<nh<<endl;
	int k;//输入要找的第k大 
	cin >> k;
//	cout<<k<<endl;
//	vector<int> index=Divide(m, n, 1, mh, 1, nh);
//	for(int i=0;i<2;i++)	cout<<index[i]<<endl;
	cout<<Kth_Largest(k,m, n, 1, mh, 1, nh)<<endl;
	system("pause");
	return 0;
}
