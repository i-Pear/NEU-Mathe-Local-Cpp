#pragma once
#include "FormBase.hpp"

class FormWelcome:public FormBase{
public:
	void display();//重写的绘制函数
	FormWelcome();
	void mouseEventReceiver(int x, int y, int button, int event); //重写的鼠标事件接收器，用于判断鼠标位置
};
