#include <iostream>
#include <ros/ros.h>
#include "producer_consumer_node.h"



int
main(int argc, char** argv) {

    ros::init (argc, argv, "producer_consumer_node");
    ros::NodeHandle nh;

    ProducerConsumerNode producerConsumerNode(nh);

    ros::spin ();
    ros::waitForShutdown();

    return 0;
}
