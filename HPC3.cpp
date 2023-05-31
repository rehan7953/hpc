#include<bits/stdc++.h>
#include <omp.h>
using namespace std;


void findMax(int* arr, int n){

    int maxValue = INT_MIN;
    #pragma omp parallel for reduction(max: maxValue);
    for(int i = 0; i < n; i++){
        if(maxValue < arr[i]){
            maxValue = arr[i];
        }
    }
    cout<<"\n Maximum ->  "<<maxValue;
}


void findMin(int* arr, int n){
    int minValue = INT_MAX;
    #pragma omp parallel for reduction(min: minValue);
    for(int i = 0; i < n; i++){
        if(minValue < arr[i]){
            minValue = arr[i];
        }
    }
    cout<<"\n Minimum ->  "<<minValue;
}



void findSum(int* arr, int n){
    int sum = 0;
    #pragma omp parallel for reduction(+: sum);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout<<"\n Sum ->  "<< sum;
}

void findAvg(int* arr, int n){
    int sum = 0;
    double avg = 0;
    #pragma omp parallel for reduction(+: sum);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = sum/n;
    cout<<"\n Average ->  "<< avg;
}

int main(){
    int n; 
    cout<<"Enter total num to insert in array";
    cin>> n;

    int* arr = new int [n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }


    findMax(arr, n);
    findMin(arr,n);
    findAvg(arr,n);
    findSum(arr, n);

}
