#!/bin/bash

# launch the minimal publisher and subscriber nodes with clean handling of Ctrl+C

cleanup() {
    echo "Restarting ROS 2 daemon to clean up before shutting down..."
    ros2 daemon stop
    sleep 1
    ros2 daemon start
    echo "Terminating all ROS 2 nodes..."
    kill 0
    exit
}

trap cleanup SIGINT SIGTERM

#lunch pub
ros2 run tutorial_package_1 py_minimal_publisher.py &


sleep 2  # Wait for the publisher to start before launching the subscriber
#lunch sub
ros2 run tutorial_package_1 py_minimal_subscriber.py &

#run graph 
ros2 run rqt_graph rqt_graph &

wait  # Wait for all background processes to finish
