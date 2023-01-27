#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int i = m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(arr1[i]>arr2[j]){
                arr1[k] = arr1[i];
                i--;
                k--;
            }else{
                arr1[k] = arr2[j];
                j--;
                k--;
            }
        }
        while(j>=0){
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        
    }
int main(){
    int m=4,n=3;
    vector<int> arr1={1,2,3,9,0,0,0};
    vector<int> arr2={4,5,6};
    merge(arr1,m,arr2,n);
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}