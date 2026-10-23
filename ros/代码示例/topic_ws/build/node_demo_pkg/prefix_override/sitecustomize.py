import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/jun/文档/学习文件/ros/代码示例/topic_ws/install/node_demo_pkg'
