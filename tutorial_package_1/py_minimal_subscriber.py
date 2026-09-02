#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class pyMinimalSubscriber(Node):
    def __init__(self):
        super().__init__('py_minimal_subscriber')

        self.subscriber_1 = self.create_subscription(
            String,
            'py_topic',
            self.listener_callback_1,
            10)
        self.subscriber_1

    def listener_callback_1(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)



def main(args=None):
    rclpy.init(args=args)
    py_minimal_subscriber = pyMinimalSubscriber()
    rclpy.spin(py_minimal_subscriber)
    py_minimal_subscriber.destroy_node()
    rclpy.shutdown()



if __name__ == '__main__':
    main()

    