//作者：张长宇 
//题目：实现算法导论上机题practice 2.5 
//日期：2018.4.16

#include<iostream> 
#include<vector> 
#define arr_size 16
using namespace std;

void init(int A[][arr_size]){
	for(int i=0;i<arr_size;i++)
		for(int j=0;j<arr_size;j++)
			A[i][j]=100;
	A[0][1]=5,A[0][2]=3;
	A[1][3]=1,A[1][4]=3,A[1][5]=6;
	A[2][4]=8,A[2][5]=7,A[2][6]=6;
	A[3][7]=6,A[3][8]=8;
	A[4][7]=3,A[4][8]=5;
	A[5][8]=3,A[5][9]=3;
	A[6][8]=8,A[6][9]=4;
	A[7][10]=2,A[7][11]=2;
	A[8][11]=1,A[8][12]=2;
	A[9][11]=3,A[9][12]=3;
	A[10][13]=3,A[10][14]=5;
	A[11][13]=5,A[11][14]=2;
	A[12][13]=6,A[12][14]=6;
	A[13][15]=4;
	A[14][15]=3;
}

vector<vector<int> >  Graph(){
	vector<int> layer_1;layer_1.push_back(0);
	vector<int> layer_2;layer_2.push_back(1);layer_2.push_back(2);
	vector<int> layer_3;layer_3.push_back(3);layer_3.push_back(4);layer_3.push_back(5);layer_3.push_back(6);
	vector<int> layer_4;layer_4.push_back(7);layer_4.push_back(8);layer_4.push_back(9);
	vector<int> layer_5;layer_5.push_back(10);layer_5.push_back(11);layer_5.push_back(12);
	vector<int> layer_6;layer_6.push_back(13);layer_6.push_back(14);
	vector<int> layer_7;layer_7.push_back(15);
	vector<vector<int> > graph;
	graph.push_back(layer_1);graph.push_back(layer_2);graph.push_back(layer_3);
	graph.push_back(layer_4);graph.push_back(layer_5);graph.push_back(layer_6);graph.push_back(layer_7);
	return graph;
}

int main(){ 
	int a[arr_size][arr_size]={0};
	init(a);
	int dp[arr_size];
	for(int i=0;i<arr_size;i++){
		dp[i]=100;
	}
	dp[0]=0;
	int count=1;
	vector<vector<int> > graph=Graph();
	int now;
	for(int i=1;i<graph.size();i++){
		for(int k=0;k<graph[i].size();k++){
			for(int j=0;j<graph[i-1].size();j++){
				if(a[graph[i-1][j]][count]==100)	continue;
				now=dp[graph[i-1][j]]+a[graph[i-1][j]][count];
				if(now<dp[count]){
					dp[count]=now;
				}
			}
			count++;
		}
	}
	for(int i=0;i<arr_size;i++){
		cout<<dp[i]<<' ';
	}
	cout<<endl;
	return 0;
} 
