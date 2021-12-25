#include<bits/stdc++.h>
using namespace std;
int *st;
// array implementation of segment tree

int buildSt(int arr[],int l,int r,int ind){
	if(l==r){
     st[ind] = arr[l];
	 return arr[l];		
	}
	int mid = l+(r-l)/2;
	st[ind] = buildSt(arr,l,mid,ind*2+1) + buildSt(arr,mid+1,r,ind*2+2);
    return st[ind];
}

int main(){
	int arr[5] = {1,2,3,4,5},n=5;
	int x = 2 * pow(2,(int)ceil(log2(n))) - 1;
	st = new int[x];
	buildSt(arr,0,n-1,0);
	for(int i=0;i<x;i++){
		cout<<st[i]<<" ";
	}
return 0;
}
