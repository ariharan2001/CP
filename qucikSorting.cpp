#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r,int pivot){
     int i = l-1;
     for(int j=l;j<r;j++){
         if(arr[j]<pivot){
             i++;
             int temp = arr[i];
             arr[i] = arr[j];
             arr[j] = temp;
         }
     }
   int temp = arr[++i];
   arr[i] = pivot;
   arr[r] = temp;
   return i;
}

void quickSort(int arr[],int l,int r){
    if(l>=r) return;
    int p = partition(arr,l,r,arr[r]);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,r);
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}
