#include <bits/stdc++.h>
using namespace std;

pair<int,int> findFirstTwo(vector<int>& arr, int left, int right)
{
    if(left==right)
    {
        return {arr[left],INT_MAX};
    }

    int mid=(left+right)/2;

    pair<int,int> leftResult=findFirstTwo(arr,left,mid);
    pair<int,int> rightResult=findFirstTwo(arr,mid+1,right);

    int first=INT_MAX;
    int second=INT_MAX;

    vector<int> values;

    values.push_back(leftResult.first);
    values.push_back(leftResult.second);
    values.push_back(rightResult.first);
    values.push_back(rightResult.second);

    for(int i=0;i<4;i++)
    {
        if(values[i]<first)
        {
            second=first;
            first=values[i];
        }
        else if(values[i]<second)
        {
            second=values[i];
        }
    }

    return {first,second};
}

int main()
{
    int n;

    cout<<"Enter the size : "<<endl;
    cin>>n;

    vector<int>arr;

    cout<<"Enter the array : "<<endl;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<endl;

    if(n<2)
    {
        cout<<"At least two waiting times are required"<<endl;
        return 0;
    }

    pair<int,int> result=findFirstTwo(arr,0,n-1);

    cout<<"First two waiting times in the report:"<<endl;
    cout<<result.first<<" "<<result.second<<endl;

    return 0;
}
