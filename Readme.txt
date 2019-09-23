NEU Mathe Local用户手册
V1.0

【操作】
此程序使用键盘和鼠标操作  目前设定的快捷键如下：
←		上一题
→		下一题
Ctrl		标记/取消标记为已做过
Enter		查看/关闭 答案
点击题干		标记/取消标记为好题/易错题
C键 (Change)	进入章节选择界面


【数据文件位置】
由于需要外部文件 且不同编译环境下相对路径有差别
请先将 "NEUML-Img Source.zip" 中的内容解压到D盘根目录
即程序以 D:\NEUML-Source 作为数据文件路径

【成员分工】
<list.hpp>及<FormWelcome.h><FormWelcome.cpp>由组员 李昀静 编写
其余代码由组长 刘添夷 编写

【编译注意事项】
如果vs提示找不到某文件路径，请在解决方案管理器窗口中移除"NEU-Mathe-Local.rc"文件
这可能是由于vs记录了绝对路径造成的