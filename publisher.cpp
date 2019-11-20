#include "ros/ros.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <sstream>


int main(int argc, char **argv)
{
  // initialize ros
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  // notify master an Int32MultiArray will be published to default channel with 
  // buffer of 100 messages
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32MultiArray>("default", 100);
  // run loop at 10 Hz
  ros::Rate loop_rate(10);

  // only run loop while ros is in active state
  while (ros::ok())
  {	
    // initialize output array
    std_msgs::Int32MultiArray array;
    array.data.clear();
    
    // fill array with numbers 1 - 19
    for (int i = 0; i < 20; i++) {
      array.data.push_back(i);
    }
    
    // broadcast message
    chatter_pub.publish(array);
    ROS_INFO("Array published \n");

    for (int i = 0; i < 20; i++) {
      ROS_INFO("Index: %d | value: %d \n", i, array.data[i]);
    }

    // used for callbacks if program is also a subscriber (dormant now)
    ros::spinOnce();
    // delay program to slow publishing rate
    loop_rate.sleep();

  }

  return 0;
}
