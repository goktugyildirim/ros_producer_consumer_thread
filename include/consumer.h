#include <iostream>
#include <memory>
#include <mutex>
#include <deque>
#include <future>
#include <ros/ros.h>
class Consumer {
public:
    using Ptr = std::shared_ptr<Consumer>;
    int consumer_id;
    explicit Consumer(const int& consumer_id_);

    std::shared_future<void> future_;

    void StartConsumer(std::deque<int> &stack, std::mutex &door);
    void Run(std::deque<int>& stack, std::mutex& door);

};
