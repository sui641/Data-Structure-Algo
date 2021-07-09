#include <iostream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

void print_arr(int *arr, int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << "; ";
    }
}

int find_max(int *arr, int n)
{   
    int max = 0;
    for (int i = 0; i<n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }

    return max;
}

//Given a column as an array, output an array with the sorted column
int *counting_sort(int *col, int *arr, int n)
{   
    int max = find_max(col, n);

    list<int> *count = new list<int>[max+1];
    
    int counter = 0;

    while (counter < n)
    {   
        int cur_ind = col[counter];
        count[cur_ind].push_back(counter);
        counter++;
    }

    int *sort_arr = new int[n];
    int counter_sort = 0;
    for (int i = 0; i < (max+1); i++)
    {
        
        list<int> cur_ind_arr = count[i];
        
        if (!cur_ind_arr.empty())
        {   

            while (!cur_ind_arr.empty() && counter_sort < n)
            {   
                
                int cur_ind = cur_ind_arr.front();
                cur_ind_arr.pop_front();
                sort_arr[counter_sort] = arr[cur_ind];
                counter_sort ++;
            }

        }
    }

    return sort_arr;
}

int *sep_col(int *arr, int size, int digit)
{   
    int cur_mod = digit * 10;
    int cur_div = digit;
    int *single_int = new int[size];
    for (int i = 0; i<size; i++)
    {
        int cur_val = (arr[i] % cur_mod)/cur_div; 
        single_int[i] = cur_val;
    }

    return single_int;
}

int *radix_sort(int *arr, int size)
{
    
    int digit_counter = 1;
    int *sort_array = arr;
    while (find_max(sort_array,size)>digit_counter)
    {
        int *cur_col = sep_col(sort_array,size,digit_counter);
        sort_array = counting_sort(cur_col, sort_array, size);
        digit_counter = digit_counter *10;
    }
    return sort_array;
}


int main()
{
    int myArray[] = {1,12,76,77,10,391,9,0,313,63,98};
    //int mycol[] = {1,2,6,7,0,1,9,0,3,3,8};
    //int *sorted = counting_sort(mycol, myArray, 11);
    //int *sep_myArray = sep_col(myArray, 11, 10);
    //print_arr(sep_myArray,11);
    //cout << "\n";
    int *mySortedArray = radix_sort(myArray, 11);
    print_arr(mySortedArray, 11);
}