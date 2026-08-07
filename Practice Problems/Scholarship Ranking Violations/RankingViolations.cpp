#include <bits/stdc++.h>
using namespace std;

int countViolation(vector<double>& arr, int left, int right)
{
    if(left>=right)
    {
        return 0;
    }

    int mid=(left+right)/2;

    int leftCount=countViolation(arr,left,mid);
    int rightCount=countViolation(arr,mid+1,right);

    int middleCount=0;

    if(arr[mid]<arr[mid+1])
    {
        middleCount=1;
    }

    return leftCount+rightCount+middleCount;
}

int main()
{
    int n;

    cout<<"Enter the size : "<<endl;
    cin>>n;

    vector<double>arr;

    cout<<"Enter the array : "<<endl;

    for(int i=0;i<n;i++)
    {
        double x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<endl;

    int result=countViolation(arr,0,n-1);

    cout<<"Total ranking violations = "<<result<<endl;

    return 0;
}
