#include<iostream>
using namespace std;
void partition(int arr[],int s,int e){
    int pivot=int e;
    int i=s-1;
    for(int j=s;j<e;j++){
        arr[i]<arr[e]

    }
}
void quickshort(int arr[],int s,int e){
    if(s>=e)
    return;

p=partition(arr,s,e);

quiclsort(arr,s,e);
quicksort(arr,p+1,e);
}