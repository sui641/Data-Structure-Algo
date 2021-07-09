#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << "; ";
    }
}

void selection_sort(int arr[], int n)
{
    //Find the min in the array, then swap with current position
    for (int i = 0; i<n; i++)
    {   
        int j = i;
        int min_index = j;
        while (j<n)
        {   
            if (arr[min_index]>arr[j])
            {
                min_index = j;
            }
            j++;
        }
       swap(arr[min_index],arr[i]);
    }
}


void insertion_sort(int arr[],int n)
{   
    if (n<=1)
    {
        return; 
    }

    for (int i=1; i<n; i++)
    {   
        int j = i-1;
        while (j>=0)
        {   
            //cout << j;
            int k = j+1;
            if (arr[j]>arr[k])
            {
                swap(arr[j],arr[k]);
            }
            j--;
        }
    } 
}

int main()
{
    int arr[] = {5,1,2,7,9,13,1,11,17,8,8,0,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr,n);
    cout << "Selection sort: ";

    //insertion_sort(arr,n);
    //cout << "Insertion sort: ";
    print_array(arr,n);

    cout << "\n\n\n";
}