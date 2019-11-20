#include "ros/ros.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"

// call back function called when message is posted on default channel
void defaultCallback(const std_msgs::Int32MultiArray::ConstPtr& array)
{
    // print all the numbers
    for(int i = 0; i < 20; i++)
    {
       ROS_INFO("Index: %d | value: %d \n", i, array->data[i]);
    }
    return;
}

// main function
int main(int argc, char **argv)
{
  // initialize ros
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  // subscribe to default channel with max queue size of 100
  ros::Subscriber sub = n.subscribe("default", 100, defaultCallback);

  // enter a loop to call message callbacks until running conditions are broken
  ros::spin();

  return 0;
}