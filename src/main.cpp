#include <philosopher.h>
#include <iostream>

using namespace std;


int main()
{
    const int no_of_philosophers = 7;    
  
    cout << "Start the gathering." << endl;
    //create chopstics
    std::mutex chop_sticks[no_of_philosophers];
   
    //create philosophers
    Philosopher professors[no_of_philosophers];
    
    //Philosophers Start reading
    for(int i = 0; i < no_of_philosophers; i++) {

          if (i == no_of_philosophers -1)
          
                  professors[i].initialize( i+1,  &chop_sticks[i],  &chop_sticks[0] );
            else
                  professors[i].initialize( i+1,  &chop_sticks[i],  &chop_sticks[i+1] );

    }

    for(int i = 0; i < no_of_philosophers; i++) {

          professors[i].start_eating();
    }

    return 0;
}