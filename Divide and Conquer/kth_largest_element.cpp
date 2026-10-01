#include <iostream>
#include <vector>

using namespace std;


// Partition function
int partitionArray(
    vector<int>& arr,
    int left,
    int right
)
{
    int pivot = arr[right];

    int index = left;


    for(int i = left; i < right; i++)
    {
        if(arr[i] > pivot)
        {
            swap(
                arr[i],
                arr[index]
            );

            index++;
        }
    }


    swap(
        arr[index],
        arr[right]
    );


    return index;
}



// Quick Select function
int quickSelect(
    vector<int>& arr,
    int left,
    int right,
    int k
)
{
    if(left <= right)
    {
        int position = partitionArray(
            arr,
            left,
            right
        );


        if(position == k)
        {
            return arr[position];
        }


        else if(position > k)
        {
            return quickSelect(
                arr,
                left,
                position - 1,
                k
            );
        }


        else
        {
            return quickSelect(
                arr,
                position + 1,
                right,
                k
            );
        }
    }


    return -1;
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



    int k;

    cin >> k;



    // Convert kth largest to index
    int index = k - 1;



    cout << quickSelect(
        arr,
        0,
        n - 1,
        index
    );


    return 0;
}
