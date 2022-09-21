
#include <iostream>
#include <philosopher.h>
#include <unistd.h>


Philosopher::Philosopher()
{


}

void Philosopher::initialize(int assigned_id,
                std::mutex *left,
                std::mutex *right)
{
    id = assigned_id;
    left_chopstick = left;
    right_chopstick = right;
    std::cout << "Philosopher " << id << " is reading.." << std::endl;
};

void Philosopher::start_eating()
{
    int  iret;
    my_thread = new std::thread( &Philosopher::eat, this);
    my_thread->join();
    std::cout << "Professor " << id << " thread returns:" << iret << std::endl;

};
    
void *Philosopher::eat(Philosopher *my)
{ 
    if (my->id == 1)
    {
        std::unique_lock<std::mutex> lock1(*(my->left_chopstick), std::defer_lock);
        std::cout << "Philosopher " << my->id << " picked up his left chopstick" << std::endl;
        std::unique_lock<std::mutex> lock2(*(my->right_chopstick), std::defer_lock);
        std::cout << "Philosopher " << my->id << " picked up his right chopstick" << std::endl;
        
        std::lock(lock1, lock2);
        std::cout << "Philosopher " << my->id << " is eating" << std::endl;
        usleep(1500000);

    }
    else    
    {
        std::unique_lock<std::mutex> lock1(*(my->right_chopstick), std::defer_lock);
        std::cout << "Philosopher " << my->id << " picked up his right chopstick" << std::endl;
        std::unique_lock<std::mutex> lock2(*(my->left_chopstick), std::defer_lock);
        std::cout << "Philosopher " << my->id << " picked up his left chopstick" << std::endl;
        std::lock(lock1, lock2);

        std::cout << "Philosopher " << my->id << " is eating" << std::endl;
        usleep(15000);
    }
    

    std::cout << "Philosopher " << my->id << " has finished eating" << std::endl;

};

