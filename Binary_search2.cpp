#include<iostream>
using namespace std;
int fibb(int even[],int n, int key){
    int start=0;
    int end = n-1;
    
    int mid = start+(end-start)/2;
    int ans = -1;
    while(start<=end){
        if(even[mid]==key){
            ans = mid;
            start = mid-1;
        }
        else if(key<even[mid]){
            start= mid+1;
        }
        else if(key>even[mid]){
            end = mid-1;
        }
        mid= start+(end-start)/2;
    }
    return ans;
}


int fibblast(int even[],int n, int key){
    int start=0;
    int end = n-1;
    
    int mid = start+(end-start)/2;
    int ans = -1;
    while(start<=end){
        if(even[mid]==key){
            ans = mid;
            start = mid+1;
        }
        else if(key<even[mid]){
            start= mid+1;
        }
        else if(key>even[mid]){
            end = mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
int main(){
    int even[9] = {1,2,3,3,3,3,3,3,5};
    cout << "The 1st occurance result is "<< fibb(even,9,3);
    cout<<"The last occurance result is "<< fibblast(even,9,3);
    return 0;

}