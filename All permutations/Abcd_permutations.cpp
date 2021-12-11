#include <iostream>
using namespace std;

void print(char arr[],int n)
{
   cout<<arr<<endl;
}

void swap(char s[],int x,int y)
{
	char ch = s[x];
	s[x] = s[y];
	s[y] = ch;
	cout<< s[x] << s[y]<<endl;
}

void permute(char arr[],int ci,int n)
{
	
	if(ci==n-1)
	{
		print(arr,n);
		return;
	}
	for(int i=ci;i<n;i++)
	{
		swap(arr,i,ci);
		permute(arr,ci+1,n);
		swap(arr,i,ci);
	}
}

int main()
{
  char s[]="abcd";
  permute(s,0,4);
return 0;
}
