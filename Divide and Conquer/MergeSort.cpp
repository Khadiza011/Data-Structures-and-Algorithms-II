#include<iostream>
#include<vector>

using namespace std;

void conquer(vector<int>& data, int left, int right, int mid)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    vector<int> left_array(size1);
    vector<int> right_array(size2);

    for(int i = 0; i < size1; i++)
    {
        left_array[i] = data[left + i];
    }

    for(int j = 0; j < size2; j++)
    {
        right_array[j] = data[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < size1 && j < size2)
    {
        if(left_array[i] <= right_array[j])
        {
            data[k] = left_array[i];
            i++;
        }
        else
        {
            data[k] = right_array[j];
            j++;
        }

        k++;
    }

    while(i < size1)
    {
        data[k] = left_array[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        data[k] = right_array[j];
        j++;
        k++;
    }
}

void divide(vector<int>& data, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    divide(data, left, mid);
    divide(data, mid + 1, right);

    conquer(data, left, right, mid);
}

int main()
{
    int n;

    cout<<"ENTER ARRAY SIZE: ";
    cin>>n;

    vector<int> data(n);

    cout<<"ENTER ARRAY: ";

    for(int i = 0; i < n; i++)
    {
        cin>>data[i];
    }

    divide(data, 0, n - 1);

    cout<<"SORTED ARRAY (MERGE SORT): ";

    for(int i = 0; i < n; i++)
    {
        cout<<data[i]<<" ";
    }

    return 0;
}
