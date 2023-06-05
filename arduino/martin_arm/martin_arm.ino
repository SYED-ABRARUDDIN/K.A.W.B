#include <ros.h>
#include <sensor_msgs/JointState.h>
#include <math.h>
#include <Servo.h>
#include <geometry_msgs/Pose.h>
ros::NodeHandle nh;

Servo axis1,axis2a,axis2b,axis3,axis4,axis5,end_eff;

double angle_r[6] = {0, 0, 0, 0, 0, 0};
double angle_d[6] = {0, 0, 0, 0, 0, 0};
double angle_r_3_n = 180;
int w;


void cmd_cb(const sensor_msgs::JointState& cmd_arm)
{ 
  //char buffer[50];
  angle_r[0] = cmd_arm.position[0];
  angle_r[1] = cmd_arm.position[1];
  angle_r[2] = cmd_arm.position[2];
  angle_r[3] = cmd_arm.position[3];
  angle_r[4] = cmd_arm.position[4];
  angle_r[5] = cmd_arm.position[5];
  for (w = 0; w < 6; w++) angle_d[w] = ((angle_r[w] * 180) / (PI)); //(180*7)/22=52.27
  //sprintf (buffer, "out  %ld %ld ", me_saw[0], mov[0]);
  //nh.loginfo(buffer);
  angle_r_3_n = map(angle_r[3],0,180,180,0);
}

ros::Subscriber<sensor_msgs::JointState> sub("/joint_states", cmd_cb);


void setup() {
  //Serial.begin(9600);
  axis1.attach(7);
  axis2a.attach(8);
  axis2b.attach(9);
  axis3.attach(10);
  axis4.attach(11);
  axis5.attach(12);
//  end_eff.attach(13);
  

  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.subscribe(sub);

  
}

void loop() {
  Serial.print(angle_d[0]);
  Serial.print("   ");  
  Serial.print(angle_d[1]);
  Serial.print("   ");  
  Serial.print(angle_d[2]);
  Serial.print("   ");  
  Serial.print(angle_r_3_n);
  Serial.print("   ");  
  Serial.print(angle_d[4]);
  Serial.print("   ");  
  Serial.print(angle_r[3]); 
  Serial.println("   "); 

  axis1.write(angle_d[0]);
  axis2a.write(angle_d[1]);
  axis2b.write(angle_d[1]);
  axis3.write(angle_d[2]);
  axis4.write(angle_r_3_n);
  axis5.write(angle_d[4]);
  //end_eff.write(angle_d[5]);

  nh.spinOnce();
  delay(1);
}
