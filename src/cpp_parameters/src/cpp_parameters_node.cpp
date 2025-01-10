#include <chrono>
#include <functional>
#include <string>

#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

// class MinimalParam : public rclcpp::Node
// {
// public:
//   MinimalParam()
//   : Node("minimal_param_node")
//   {
//     this->declare_parameter("my_parameter", "world"); //default == string type

//     timer_ = this->create_wall_timer(
//       1000ms, std::bind(&MinimalParam::timer_callback, this)); // callback every 1s
//   }

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam()
  : Node("minimal_param_node")
  {
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = "This parameter is mine!"; // can specify text descr of param and constriants.

    this->declare_parameter("my_parameter", "world", param_desc);

    timer_ = this->create_wall_timer(
      1000ms, std::bind(&MinimalParam::timer_callback, this));
  }

  

  void timer_callback()
  {
    std::string my_param = this->get_parameter("my_parameter").as_string(); //gets node param and stores it in my_param

    RCLCPP_INFO(this->get_logger(), "Hello %s!", my_param.c_str()); // confirms logged my_param

    std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("my_parameter", "world")};
    this->set_parameters(all_new_parameters); //sets my_param to default world (string type)
  }



private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}