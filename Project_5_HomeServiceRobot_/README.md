# Home Service Robot
This is the capstone project of the Robotics Software Engineer Nanodegree.
This document explains the ROS packages used in this project. In this project, the goal of the robot is to go to a **Pick-Up Zone** and oick up the object, **marker** in this project, and then go to a **Drop-off Zone**. 
To acheive this, ROS packages were used for Mapping, Localization and Navigation.

## Mapping
**RTAB-Map Package**
RTAB-Map (*Real-Time Appearance-Based Mapping*) is an RGB-D SLAM approach based on a global loop closure detector with real-time constraints. Using this package, we can create a 2D occupancy grid map that can be used for navigating the robot.


## Localization
**AMCL Package**
AMCL (*Adaptive Monte Carlo Localization*) is a probabilistic localization system for a robot which implements adaptive Monte Carlo localization approach while using a particle filter to track the pose of the robot against a known map.


## Navigation
**ROS Navigation Stack**
Using this package, we can creates a path for the robot based on Dijkstra's algorithm while avoiding obstacle along the way.


