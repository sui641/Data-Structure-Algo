#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <assert.h>

using namespace std;

struct data
{
    int value;
    struct data * next;
};

void print_list(struct data * headder)
{
    struct data * temp = headder ;
    
    int count = 0;
    while (temp!= NULL)
    {
        cout << "current node " << count << " : " << temp->value << " \n";
        temp = temp -> next;
        count ++;
    };

    cout << "\n\n\n";
}

//Search the prior for reconnecting the list
void serched_linked_list(struct data *header, int index, struct data * &prior)
{   
    cout << "Now seraching for the prior of deleted node.\n";
    int count = 0;
    struct data *temp = header;
    struct data *temp_prior = temp; 
    while (count != index)
    {   
        temp_prior = temp;
        temp = temp -> next;
        count ++;
        cout << count << "th node : " << temp -> value << "\n";
    }

    
    prior = temp_prior;

    cout << "\n\n\n";
}

int main (int argc, char ** argv)
{
    int num_insert = atoi(argv[1]);
    int num_delete = atoi(argv[2]);
    

    // Initial the headder
    struct data *headder = new struct data;
    headder -> value = 313;
    headder -> next = NULL;

    //Insersion next to head
    cout << "Insertion starts.\n";
    for (int i=0; i<num_insert; ++i)
    {
        //Record the temp node after head
        struct data * temp = new struct data;
        temp  = headder -> next ;

        struct data *cur_node = new struct data;
        cur_node -> value = rand()%313;
        
        headder -> next = cur_node;
        cur_node -> next = temp;

        print_list (headder);

    }

    //Deletion desired node by index
    cout << "Deletion starts\n";
    for (int j = 0; j < num_delete; ++j)
    {
        int delete_index = rand()%(num_insert-j+1);
        cout << "Desire delete " << delete_index << "th node \n";
        
        if (delete_index == 0){
            headder = headder -> next;
        }
        else
        {
            struct data * prior;

            serched_linked_list(headder, delete_index, prior);

            //struct data *delete_node = prior -> next;
            struct data *new_next = prior -> next -> next ;

            prior -> next = new_next ;
        }

        print_list (headder);

    }
    
    return 0;
    
}