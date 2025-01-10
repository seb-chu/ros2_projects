import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sebastianchu/code/ros2_tutorial/ros2_ws_tutorial/install/py_srvcli'
