#include <iostream>
using namespace std;
 
void merge(int array[], int left, int mid,int right)
{
    int subA1 = mid - left + 1;
    int subA2 = right - mid;
 
    int leftA[subA1],rightA[subA2];
 
    for (int i = 0; i < subA1; i++){
        leftA[i] = array[left + i];
    }
    for (int j = 0; j < subA2; j++){
        rightA[j] = array[mid + 1 + j];
    }
 
    int indexA = 0,indexB = 0; 
    int indexMA = left;
 
    while (indexA < subA1 && indexB < subA2) {
        if (leftA[indexA] <= rightA[indexB]) {
            array[indexMA] = leftA[indexA];
            indexA++;
        }
        else {
            array[indexMA] = rightA[indexB];
            indexB++;
        }
        indexMA++;
    }
    while (indexA < subA1) {
        array[indexMA] = leftA[indexA];
        indexA++;
        indexMA++;
    }
    while (indexB < subA2) {
        array[indexMA] = rightA[indexB];
        indexB++;
        indexMA++;
    }
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return; 
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[] = { 14,33,7,10,35,19,42,44 };
    int len = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Before Sortint : ";
    printArray(arr, len);
    mergeSort(arr, 0, len - 1);

    cout << "After Sorting : ";
    printArray(arr, len);
    return 0;
}

