#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr,int st,int mid,int end){
    vector<int> temp;
    int i=st,j=mid+1;
    int invCount=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
            invCount+=(mid-i+1);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &arr,int st,int end){

    while(st<end){
        int mid=(st+end)/2;

        int leftInvCount=mergeSort(arr,st,mid);
        int rightInvCount=mergeSort(arr,mid+1,end);

        int InvCount=merge(arr,st,mid,end);

        return leftInvCount+rightInvCount+InvCount;
    }

    return 0;
} 

int main(){
    vector<int> arr1={6,3,5,2,7};
    vector<int> arr2={1,3,5,10,2,6,8,9};

    int totalInversions =mergeSort(arr2,0,arr2.size()-1);
    cout << "Total Inversions: " << totalInversions << endl;

    return 0;
}