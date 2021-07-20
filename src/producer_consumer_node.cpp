#include "producer_consumer_node.h"

ProducerConsumerNode::ProducerConsumerNode(ros::NodeHandle &nh)
: nh_(nh), int_number(0)
{
    timer_ = nh_.createTimer(ros::Duration(0.1),
         &ProducerConsumerNode::CallbackProducer, this);
    pub_int_ = nh_.advertise<std_msgs::Int64>("/number", 10);
    sub_int_ = nh_.subscribe("/number", 30, &ProducerConsumerNode::CallbackConsumer, this);

    consumer_1_ = std::make_shared<Consumer>(1);
    consumer_2_ = std::make_shared<Consumer>(2);
    consumer_1_->StartConsumer(stack, door);
    consumer_2_->StartConsumer(stack, door);
}

void
ProducerConsumerNode::CallbackProducer(const ros::TimerEvent &)
{
    std_msgs::Int64 msg_int;
    msg_int.data = int_number;
    pub_int_.publish(msg_int);
    int_number++;
}

void ProducerConsumerNode::CallbackConsumer(const std_msgs::Int64ConstPtr& msg_int)
{
    door.lock();
    stack.push_back(msg_int->data);
    door.unlock();
}




