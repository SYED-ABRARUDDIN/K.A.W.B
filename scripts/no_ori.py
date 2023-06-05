import sys
import rospy
import moveit_commander
import copy
import moveit_msgs.msg
import geometry_msgs.msg



moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node('int300_arm_testing',anonymous= True)

robot = moveit_commander.RobotCommander()
scene = moveit_commander.PlanningSceneInterface()
arm_group=moveit_commander.MoveGroupCommander("arm")

display_trajectory_publisher = rospy.Publisher('/move_group/display_planned_path',moveit_msgs.msg.DisplayTrajectory) 


pose_target = geometry_msgs.msg.Pose()
pose_target.position.x = -0.138051444983
pose_target.position.y = 0.0173428747624
pose_target.position.z = 0.266571489403
pose_target.orientation.w = 0.00751653667659
arm_group.set_pose_target(pose_target)

plan1=arm_group.plan()

rospy.sleep(5)

arm_group.go(wait=True)

moveit_commander.roscpp_shutdown()


