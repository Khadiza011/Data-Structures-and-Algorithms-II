#include <iostream>
#include <vector>

using namespace std;


// Count reverse pairs between two halves
long long countPairs(
    vector<int>& arr,
    int left,
    int mid,
    int right
)
{
    long long count = 0;


    int j = mid + 1;


    for(int i = left; i <= mid; i++)
    {
        while(j <= right &&
              (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }


        count += (j - (mid + 1));
    }


    return count;
}



// Merge two sorted halves
void mergeArray(
    vector<int>& arr,
    int left,
    int mid,
    int right
)
{
    vector<int> temp;


    int i = left;
    int j = mid + 1;



    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }



    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }



    while(j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }



    for(int k = left; k <= right; k++)
    {
        arr[k] = temp[k-left];
    }
}



// Merge sort with reverse pair count
long long mergeSort(
    vector<int>& arr,
    int left,
    int right
)
{
    long long count = 0;


    if(left < right)
    {
        int mid = (left + right) / 2;


        count += mergeSort(
            arr,
            left,
            mid
        );


        count += mergeSort(
            arr,
            mid + 1,
            right
        );


        count += countPairs(
            arr,
            left,
            mid,
            right
        );


        mergeArray(
            arr,
            left,
            mid,
            right
        );
    }


    return count;
}



int main()
{
    int n;


    cin >> n;


    vector<int> arr(n);



    // Taking array input
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }



    cout << mergeSort(
        arr,
        0,
        n-1
    );


    return 0;
}
