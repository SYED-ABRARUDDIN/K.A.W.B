#!/usr/bin/env python
# coding: utf-8
import sys
import rospy
import moveit_commander
from moveit_commander import PlanningSceneInterface
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Pose
#from scipy.spatial.transform import Rotation

moveit_commander.roscpp_initialize(sys.argv)
scene = PlanningSceneInterface()
robot = moveit_commander.RobotCommander()
arm_group=moveit_commander.MoveGroupCommander("arm")
#rpose=Pose()

x = 0
y = 0  
def talker():
    global y
    global x
    #rospy.loginfo((69-data.position.x)*0.01)
    #rospy.loginfo((data.position.y+3.2)*0.01)
    grasp_pose=Pose()
    print(arm_group.get_current_pose())

    grasp_pose.position.x = 0.0173741
    grasp_pose.position.y = -0.014316393
    grasp_pose.position.z = 0.488778
    grasp_pose.orientation.x = 0.0
    grasp_pose.orientation.y = -0.706825181105
    grasp_pose.orientation.z = 0.0
    grasp_pose.orientation.w = 0.707388269167
    arm_group.set_pose_target(grasp_pose)
   
    plan1=arm_group.go()
 
    #x=data.position.x
    #y=data.position.y


   
if __name__ == '__main__':
    try:
	rospy.init_node('ARM', anonymous=True)
	talker()
	rospy.spin()
    except rospy.ROSInterruptException:
        rospy.loginfo("in")


