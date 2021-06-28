#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <stdio.h>

using namespace std;

struct data 
{
    int value;
    struct data * next;
};

void print_list(struct data *headder)
{
    struct data *temp = headder;

    int counter = 0;
    while (temp != NULL)
    {
        if (counter == 0)
        {
            cout << "Head" << " : " << temp -> value << "\n";
        }
        else 
        {
            cout << counter << "th node " << " : " << temp -> value << "\n";
        }

        temp = temp -> next;
        counter ++;
        
    }
}

int main (int argc, char ** argv)
{
    int num_insert = atoi(argv[1]);
    int num_delete = atoi(argv[2]);

    //Initial head
    struct data *headder = new struct data;
    headder -> value = 313;
    headder -> next = NULL;

    //Insert nodes
    cout << "Insertion Begins \n\n";
    for (int i = 0; i < num_insert; ++i)
    {
        // Initial current node
        struct data *cur_node = new struct data;
        cur_node -> value = rand()%313;

        // Record the temp node as headder
        struct data *temp_node = headder;
        
        //Make new linkage and reserve FIFO order 
        cur_node -> next = temp_node;
        headder = cur_node;

        print_list(headder);

        cout << "\n\n\n";

    }

    // Deletion
    // Delete the tail as the insertion always happen at the head
    cout << "Deletion Begins \n\n";
    for (int j = 0; j < num_delete; ++j)
    {
        struct data *temp = headder;
        while (temp -> next -> next!= NULL)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;

        print_list(headder);

        cout << "\n\n\n";
    }
    
    
    return 0;

}