#include<iostream>
using namespace std;
void merge(int* arr,int s,int e)
{
int mid=s+(e-s)/2;

 int len1=mid-s+1;
 int len2= e-mid;

 int* first=new int[len1];
 int* second=new int[len2];

  int k=s;
  for(int i=0;i<len1;i++){
first[i]=arr[k++];
}
k=mid+1;
for(int i=0;i<len2;i++){
    second[i]=arr[k++];
}

 int indexlen1=0;
 int indexlen2=0;
  k=s;
 while(indexlen1<len1 && indexlen2<len2){
    if(first[indexlen1]<=second[indexlen2]){
        arr[k]=first[indexlen1];
        indexlen1++;
    }
 else{
    arr[k]=second[indexlen2];
    indexlen2++;
 }
 }
 while(indexlen1<len2){
    arr[k]=first[indexlen1];
    indexlen1++;
 }
  while(indexlen2<len2){
    arr[k]=second[indexlen2];
    indexlen2++;
 }
}
void mergesort(int* arr,int s,int e){
    if(s<=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr,s, e);

}
int main(){
   int arr[5]={3,5,8,1,9};
   int n=5;
  
   mergesort(arr, 0, n-1);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<""<<endl;
   }
   return 0;
}