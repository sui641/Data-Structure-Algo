#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void print_array(int * array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
}

void binary_search (int * array, int size, int target)
{
    int start = 0;
    int end = size-1;
    int found = 0;

    while (start+1 < end)
    {
        int middle = (start + end) / 2;
        cout << middle << "\n";

        if (array[middle] > target)
        {   
            end = middle;
            
        }

        else if (array[middle] < target)
        {
            start = middle;
        }

        else
        {   
            found = 1;
            cout << "Target is " << middle+1 << "th element in the array.\n\n\n";
            break;
        }
    }

    if (found == 0)
    {
        cout << "Target not found\n\n\n";
    }
    
}

// Help function for qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main (int argc, char ** argv)
{
    int array_size = atoi(argv[1]);
    int num_search = atoi(argv[2]);

    //Initialize the arrays
    int *array = new int[array_size];

    for (int i = 0; i < array_size; ++i)
    {
       array[i] = rand()%13; 
    }

    qsort(array, array_size, sizeof(int), cmpfunc);

    print_array(array,array_size);

    cout << "\n";

    for (int i = 0; i< num_search; ++i)
    {
        int search_target = rand()%7;

        cout << "Current Target: " << search_target << "\n";
        binary_search (array, array_size, search_target);

    }

    
    return 0;
}