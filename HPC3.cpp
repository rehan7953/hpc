#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>

using namespace std;

void findMin(vector<int>& arr) {
  int minValue = INT_MAX;
  #pragma omp parallel for reduction(min: minValue)
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < minValue) {
      minValue = arr[i];
    }
  }
  cout << "Minimum value: " << minValue << endl;
}

void findMax(vector<int>& arr) {
  int maxValue = INT_MIN;
  #pragma omp parallel for reduction(max: maxValue)
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }
  cout << "Maximum value: " << maxValue << endl;
}

void findSum(vector<int>& arr) {
  int sum = 0;
   #pragma omp parallel for reduction(+: sum)
   for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
  }
  cout << "Sum: " << sum << endl;
}

void findAverage(vector<int>& arr) {
  int sum = 0;
  #pragma omp parallel for reduction(+: sum)
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
  }
  cout << "Average: " << (double)sum / arr.size() << endl;
}

int main() {
  int n;
  cout<<"Enter total number to insert -> ";
  cin>>n;
  
  vector<int> arr(n);
  cout<<"\nEnter an element -> ";
  for(int i = 0; i < n; i++){
  	cin>>arr[i];
  }
  
  cout<<endl; 
  
  findMin(arr);
  findMax(arr);
  findSum(arr);
  findAverage(arr);
}
