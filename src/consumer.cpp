#include "consumer.h"


Consumer::Consumer(const int& consumer_id_)
:consumer_id(consumer_id_)
{
    std::cout << "Consumer " << consumer_id << " is initialized!" << std::endl;
}


void
Consumer::Run(std::deque<int> &stack, std::mutex &door)
{
    while (ros::ok())
    {
        door.lock();
        if (!stack.empty())
        {
            // Do somethings !!!
            //std::cout << "Running " << consumer_id << ". consumer. Data: " << stack.front() << std::endl;
            stack.pop_front();
        }
        door.unlock();
        sleep(0.5); // Simulating latency for brute force stuffs
    }

}

void
Consumer::StartConsumer(std::deque<int> &stack, std::mutex &door)
{
    future_ = std::async(std::launch::async,
                         &Consumer::Run,
                         this,
                         std::ref(stack), std::ref(door));
}


