#pragma once
#include "FormBase.hpp"
#include "IocService.hpp"

//选章界面，提供可视化章节切换
class FormSelector :public FormBase {
private:
	int chapter; //暂存当前进入的章id
public:
	void mouseEventReceiver(int x, int y, int button, int event); //重写的鼠标事件接收器，用于判断鼠标位置
	void display(); //重写的绘制函数
	FormSelector();// 空构造函数
};
