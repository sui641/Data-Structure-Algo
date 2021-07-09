#include <iostream>
#include <algorithm>

using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << "; ";
    }
}


int *merge_array(int *A, int *B, int sizeA, int sizeB)
{
    
    int *result = new int[sizeA+sizeB];
    
    int A_ind = 0;
    int B_ind = 0;
    
    int counter = 0;
    while (counter < sizeA + sizeB)
    {   
         
        if (A_ind >= sizeA)
        {
            result[counter] = B[B_ind];
            counter++;
            B_ind++;
        }
        else if(B_ind >= sizeB)
        {
            result[counter] = A[A_ind];
            counter++;
            A_ind++;
        }
        else if (A[A_ind] < B[B_ind])
        {
            result[counter] = A[A_ind];
            A_ind++;
            counter = counter+1;
        }
        else if (A[A_ind] > B[B_ind])
        {
            result[counter] = B[B_ind];
            B_ind++; 
            counter = counter+1;
        }
        else
        {
            result[counter] = A[A_ind];
            result[counter+1] = B[B_ind];
            counter = counter +2;
            A_ind++;
            B_ind++;
        }
    }
    
    return result;
}

void merge(int *arr, int left, int right, int mid)
{   
    
    int subA_size = mid - left +1;
    int subB_size = right - mid;

    int *subA = new int[subA_size];
    int *subB = new int[subB_size];

    for (int i = 0; i<subA_size; i++)
    {
        subA[i] = arr[left+1];
    }
    for (int j = 0; j<subB_size; j++)
    {
        subB[j] = arr[mid+1+j];
    }

    arr = merge_array(subA, subB, subA_size, subB_size);

}

void merge_sort(int *arr, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int mid = begin +(end-begin) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, begin, end, mid);


}


int main()
{
    //int A[] = {2,3,7,9,13};
    //int B[] = {3,6,7,11,19,21};

    //int *r = merge_array(A,B,5,6);

    int myArray[] = {2,6,3,5,1,10,7,0};
    int myArray_size = sizeof(myArray)/sizeof(myArray[0]);

    merge_sort(myArray, 0, 7);

    print_array(myArray,myArray_size);

    cout << "\n\n\n";


}
