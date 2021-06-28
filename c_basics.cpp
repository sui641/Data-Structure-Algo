#include <iostream> 
#include <ctime>
#include <thread>
using namespace std;

// Function 
int adder(int a, int b)
    {
    return a+b;
    }

void adder_res(int a, int b, int &res)
    {
    res = a+b;
    }

int main (int argc, char **argv){

    // Hello World - if-else & for loop
    if (argc == 1)
        printf ("You have no input statement.\n");

    if (argc >1) {
        cout << "You have " << argc-1 << " statement.\n";
        for (int i = 1; i < argc; ++i)
            cout << "Statement " << i << " is " << argv[i] << "\n";
        
    }

    // Runtime - ifelse vs switch 
    int dummy = 0;
    time_t ifelse_begin, ifelse_end;
    time (&ifelse_begin);
    for (int i = 0; i<200; ++i)
        {
        if (i%2 == 1)
            this_thread::sleep_for(1ms);
        else 
            this_thread::sleep_for(1ms);
        }   

    time (&ifelse_end);
    double ifelse_dur = difftime(ifelse_end,ifelse_begin);
    cout << "ifelse duration: " << ifelse_dur << "ms\n";
    
    time_t switch_begin, switch_end;
    time (&switch_begin);
    int i = 0;
    while (i<200)
        {
            int status = (i%2 == 1);
            switch(status)
                {
                case 0:
                    this_thread::sleep_for(1ms);
                    break;
                case 1:
                    this_thread::sleep_for(1ms);
                    break;
                }
            i++;
        }
    time (&switch_end);
    double switch_dur = difftime(switch_end,switch_begin);
    cout << "switch duration: " << switch_dur << "ms\n";
    
    int first = atoi(argv[1]);
    int second = atoi(argv[2]);
    
    cout << "Returned result is " << adder(first, second) << "\n";
    
    int res = 0;
    adder_res(first,second,res);
    cout << "Reference result is "<< res << "\n";

    // Array
    int **arr_2d_new = new int*[5];
    for (int i = 0; i < 5; i++)
        arr_2d_new[i] = new int[5];

    cout << arr_2d_new << "\n";
    return 0;
}