#include<iostream>
using namespace std;
int binarysearch2(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid =(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end=mid-1;
    
        }
        mid=(start+end)/2;
    }
    return -1;
}
int binarysearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid = (start+end)/2;
    while(start<=end){
        
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start = mid+ 1;
        }
        else{
            end= mid-1;
        }
        mid=(start+end)/2;
    } 
    return -1;
}



int main(){
    int even[5]={2,22,222,2222,22222};
    int odd[5]={3,33,333,3333,33333};
    int index = binarysearch(even, 5, 2222);
    cout<<"The binarySearch no is " << index <<endl;
    int index2 = binarysearch1(odd,5,33);
    cout<<"The odd number"<<index2<<endl;
    return 0;
}