#include <iostream>
#include <vector>

using namespace std;

void conquer(vector<int>& data,int left, int right,int mid){
 int size1 = mid-left+1;
 int size2 = right-mid;

 vector<int> left_array(size1);
 vector<int> right_array(size2);

 for(int i=0; i<size1; i++){
    left_array[i]=data[left+i];
 }

 for(int j=0; j<size2; j++){
    right_array[j]=data[mid+1+j];
 }

 int i=0;
 int j=0;
 int k=left;

 while(i<size1 && j<size2){
    if(left_array[i]<right_array[j]){
        data[k]=left_array[i];
        i++;
    }else{
         data[k]=right_array[j];
        j++;
    }
    k++;
 }
 while(i<size1){
    data[k]=left_array[i];
    i++;
    k++;
 }

 while(j<size2){
    data[k]=right_array[j];
    j++;
    k++;
 }
}

void divide(vector<int>& data,int left, int right){
 if(left>=right){
    return;
 }

 int mid=(left+right)/2;
 divide(data,left,mid);
 divide(data,mid+1,right);
 conquer(data,left,right,mid);
}

int main() {

    int size1, size2;

    cout << "Enter the size of first array: ";
    cin >> size1;

    vector<int> a(size1);

    cout << "Enter the elements of first array: ";
    for(int i = 0; i < size1; i++){
        cin >> a[i];
    }

    cout << "Enter the size of second array: ";
    cin >> size2;

    vector<int> b(size2);

    cout << "Enter the elements of second array: ";
    for(int i = 0; i < size2; i++){
        cin >> b[i];
    }

    int c = size1 + size2;
    int k = 0;

    // Step 1: Combine both arrays
    vector<int> combined(c);

    for(int i = 0; i < size1; i++){
        combined[k] = a[i];
        k++;
    }

    for(int j = 0; j < size2; j++){
        combined[k] = b[j];
        k++;
    }

    // Step 2: Apply merge sort
    divide(combined, 0, combined.size() - 1);

    // Output
    cout << "Sorted array: ";
    for(int x : combined)
        cout << x << " ";

    return 0;
}
