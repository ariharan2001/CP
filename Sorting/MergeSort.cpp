#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int MAX = 1e9+7;

void merge(int a[],int l,int m,int r){
	int output[r-l+1];
	int i=l,j=m+1,k=0;
	while(i<=m && j<=r){
	  if(a[i] < a[j]) output[k++] = a[i++];
	  else output[k++] = a[j++];
	}
	while(i<=m) output[k++] = a[i++];
	while(j<=m) output[k++] = a[j++];
	
	for(int i=l;i<=r;i++) a[i] = output[i-l];
}

void mergesort(int a[],int l,int r){
	if(l>=r) return;
	
	int mid = l+(r-l)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	merge(a,l,mid,r);
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   mergesort(a,0,n-1);
   for(int i=0;i<n;i++) cout<<a[i]<<" ";
return 0;
}
