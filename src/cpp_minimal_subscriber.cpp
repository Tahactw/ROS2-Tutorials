
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;


class MinimalCppSubscriber : public rclcpp::Node
{
public:
    MinimalCppSubscriber() : Node("minimal_cpp_subscriber")
    {
        subscription_ = create_subscription<std_msgs::msg::String>(
            "/cpp_chatter", 10, std::bind(&MinimalCppSubscriber::topic_callback , this, std::placeholders::_1));
        RCLCPP_INFO(get_logger(), "Hello, world! This is a C++ subscriber node.");
    }

private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(get_logger(), "I heard: '%s'", msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};  


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto minimal_cpp_subscriber = std::make_shared<MinimalCppSubscriber>();
    rclcpp::spin(minimal_cpp_subscriber);
    rclcpp::shutdown();
    return 0;
}