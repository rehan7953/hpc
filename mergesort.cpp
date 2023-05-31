#include<bits/stdc++.h>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void merrge (int * arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid -s +1;
    int len2 = e-mid;

    vector<int>v1(len1);
    vector<int>v2(len2);


    int index = s;


    for (int i = 0; i < len1; i++)
    {
        v1[i] = arr[index++];
    }

    index = mid +1;

     for (int i = 0; i < len2; i++)
    {
        v2[i] = arr[index++];
    }


    index = s;
    int i = 0;
    int j = 0;

    while (i<len1 && j < len2)
    {
        if(v1[i] < v2[j]){
            arr[index++] = v1[i++];
        }
        else{
            arr[index++] = v2[j++];
        }
    }

    while (i<len1)
    {
        arr[index++] = v1[i++];
    }
    
    while (j<len2)
    {
        arr[index++] = v2[j++];
    }
}

void mergesort(int *arr, int s, int e){

    if(s >= e){
        return;
    }

    int mid = s + (e-s)/2;
    #pragma omp parallel sections
    {

        #pragma omp section
        {
            	mergesort(arr,s,mid);   	 
        }

        #pragma omp section
        {
            	mergesort(arr,mid+1,e);    
        }
    }
    merrge(arr, s, e);
}



int main()
{
	int *a,n,i;
	cout<<"\n enter total no of elements=>";
	cin>>n;
	a= new int[n];

	cout<<"\n enter elements=>";
	for(i=0;i<n;i++)
	{
    	cin>>a[i];
	}
   //	 start=.......
//#pragma omp…..
	mergesort(a, 0, n-1);
//          stop…….
	cout<<"\n sorted array is=>";
	for(i=0;i<n;i++)
	{
    	cout<<"\n"<<a[i];
	}
  	// Cout<<Stop-Start
	return 0;
}
