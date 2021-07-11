#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;


class Hash
{
    int V;
    list<int> *element;

public:
    Hash(int V);
    void insert_ele(int val);
    void delete_ele(int val);
    int hash_function(int key);
    void print_hash();

};

Hash::Hash(int V)
{   
    //#of slots/keys in the hash table
    this -> V = V;
    //Initialize V lists for each key
    element = new list<int>[V];
}

int Hash::hash_function(int key)
{
    return (key%V);
}

void Hash::insert_ele(int val)
{
    int cur_key = hash_function(val);
    list<int> cur_list = element[cur_key];
    bool found = (find(cur_list.begin(),cur_list.end(),val)!=cur_list.end());
    cout << found;
    if (!found)
    {
        element[cur_key].push_back(val);
        
    }
    //cout << cur_list.front() << "\n";
}

void Hash::delete_ele(int val)
{
    int cur_key = hash_function(val);
    list<int> cur_list = element[cur_key];
    element[cur_key].remove(val);
     
}

void Hash::print_hash()
{   
    for (int i= 0; i<V; i++)
    {
        list<int> cur_list = element[i];
        cout << i << ": " ;
        list<int> :: iterator j;
        for (j = cur_list.begin(); j != cur_list.end(); ++j)
        {
            cout << *j << "; ";
        }
    
    
        cout << "\n";
    }
}

int main()
{   
    Hash h(7);
    //int r = h.hash_function(1);
    //cout << r << "\n";
    h.insert_ele(1);
    h.insert_ele(13);
    h.insert_ele(6);
    h.insert_ele(1);
    h.insert_ele(3);
    h.insert_ele(19);

    cout << "Before deletion: \n";
    h.print_hash();


    h.delete_ele(19);
    h.delete_ele(6);
     h.delete_ele(100);

    cout <<"\n\n";
    cout <<"After deletion: \n";
    h.print_hash();

    return 0;
}