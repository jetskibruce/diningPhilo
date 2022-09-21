

//#include <chopstick.h>
#include <thread>
#include <mutex>

class Philosopher
{
public:
    Philosopher();
    void initialize(int assigned_id,
                    std::mutex *left,
                    std::mutex *right);
    void start_eating();


private:
    int id;
   
    std::mutex *left_chopstick;
    std::mutex *right_chopstick;
    std::thread *my_thread;
    static void* eat(Philosopher *my);
};