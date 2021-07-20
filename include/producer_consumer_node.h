#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <mutex>
#include <deque>
#include "consumer.h"

class ProducerConsumerNode {
public:
  
    ros::NodeHandle& nh_;

    explicit ProducerConsumerNode(ros::NodeHandle &nh);

    ros::Timer timer_;
    ros::Publisher pub_int_;
    ros::Subscriber sub_int_;

    void
    CallbackProducer(const ros::TimerEvent&);

    void
    CallbackConsumer(const std_msgs::Int64ConstPtr& msg_int);

    int int_number;

    std::mutex door;

    std::deque<int> stack;

    Consumer::Ptr consumer_1_;
    Consumer::Ptr consumer_2_;

};

