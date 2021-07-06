#include <iostream>
#include <assert.h>

using namespace std;

//Using array to implement the max heap, insertion and deletion

#define MAX 1000

//Print the heap 
void print_heap(int arr[], int size)
{
    cout << "Here is the max heap.\n";
    for (int i = 0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}


//Insertion:
//1. Add an element to the array as last element, which is the bottom of the tree.
//2. Allocate the element in the proper position by comparing. 
void allocate_ele(int arr[], int ele_index)
{
    if (ele_index == 0)
    {
        return;
    }

    int cur_ele = arr[ele_index];
    int cur_parent_index = (ele_index-1)/2;
    int cur_parent = arr[cur_parent_index];
    
    if (cur_ele > cur_parent)
    {   
        swap( arr[ele_index], arr[cur_parent_index]);
        allocate_ele(arr, cur_parent_index);
        
    }

}   

void insertion(int arr[], int &heap_size, int ele)
{
    arr[heap_size] = ele;
    allocate_ele(arr,heap_size);
    heap_size++;
    
}


//Deletion: 
//0.Search the element index which needs to be deleted
//1.Replace that element by the last element in the array
//2.Delete the last element
//3.Adjust the location by comparison
int search_ele(int arr[], int heap_size, int ele)
{   
    int ind = -1;
    for (int i = 0; i<heap_size; i++)
    {
        if (arr[i] == ele)
        {
            ind = i;
            break;
        }
    }
    return ind;
}

void adjust_ele(int arr[], int del_ind)
{
    int left = (del_ind*2) + 1;
    int right = (del_ind*2) + 2;

    if (arr[del_ind] < arr[left])
    {
        swap(arr[del_ind],arr[left]);
        adjust_ele(arr,left);
    }

    else if (arr[del_ind] < arr[right])
    {
        swap(arr[del_ind],arr[right]);
        adjust_ele(arr,right);
    }

    else
    {
        return;
    }
    
}

void deletion(int arr[], int &heap_size, int ele)
{
    int del_ind = search_ele(arr,heap_size,ele);

    if (del_ind == heap_size - 1)
    {   
        heap_size --;
        return;
    }
    else 
    {
        swap(arr[del_ind],arr[heap_size-1]);
        heap_size --;

        adjust_ele(arr,del_ind);
    }
    

}

int main()
{
    int init_arr[MAX] = {13,7,9,1,3,5};
    int init_size = 6;
    insertion(init_arr, init_size, 17);
    insertion(init_arr, init_size, 10);
    insertion(init_arr, init_size, 19);
    insertion(init_arr, init_size, 0);
    insertion(init_arr, init_size, 2);
    
    print_heap(init_arr,init_size);
    cout << "\n";

    deletion(init_arr, init_size, 10);
    deletion(init_arr, init_size, 17);
    deletion(init_arr, init_size, 2);
    print_heap(init_arr, init_size);
    cout << "\n";
    
}