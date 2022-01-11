#include<bits/stdc++.h>
using namespace std;

int sum(int bit[],int index){
   int sum = 0;
   index += 1;
   while(index > 0){
       sum += bit[index];
       index -= index & (-index);
   }
return sum;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10},n=sizeof(a)/sizeof(int);
    int bit[n+1];
    for(int i=0;i<n;i++) bit[i] = 0;
    for(int i=0;i<10;i++){
       int index = i+1;
       while(index <= n){
           bit[index] += a[i];
           index += index & (-index);
       }
    }
   cout<<sum(bit,4)<<endl; // from index 0 - 4 (1+2+3+4+5 = 15)
 return 0;
}
