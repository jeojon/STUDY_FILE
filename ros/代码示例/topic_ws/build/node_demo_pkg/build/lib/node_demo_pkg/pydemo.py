import rclpy
from rclpy.node import Node

def dd():
    for i in range(9):
        for j in range(9):
            print(f"{i}*{j} = {i*j}", end="\t")
        print("\n")

def main(): 
    rclpy.init() # 为通信做初始化工作
    node = Node("pnode") # 创建一个节点变量


    node.get_logger().info("woshijun") # 用于获取日志文件 node.get_logger 这个命令后加的是或取得日志的级别,如info, warn等
    dd()
    node.get_logger().warn("woshipython")



    rclpy.spin(node) # 运行这个节点


    rclpy.destroy_node(node) # 销毁节点Python接口
    rclpy.shutdown() # 关闭节点Python接口