#pragma once
#include "acllib.h"

class FormBase {
protected:
	static int getCenterX(int charSize, int charCount);
public:
	enum listenerMode { charEvent = 1, keyEvent = 2, mouseEvent = 4, timerEvent = 8 }; //提供监听器需求枚举，使用时用|运算符，可以将多个选项合成为一个

	void (*switchWindow)(int, int, int) = NULL; //与DisplayManager通信的切换窗口函数指针，由DisplayManager赋值
	void (*refresh)() = NULL; //与DisplayManager通信的重绘函数指针，由DisplayManager赋值

	static int WinWidth; //窗口宽度 由于ACLlib窗口大小在初始化时确定，这里使用静态
	static int WinHeight; //窗口高度

	// Must be overwritten
	virtual void display() = 0; // 绘制函数 调用窗口派生类进行绘制

	// Can overwrite
	virtual void charEventReceiver(char) {} //输入字符事件接收器，由Display Manager调用，下同
	virtual void keyEventReceiver(int,int){} // 按键事件接收器
	virtual void mouseEventReceiver(int, int, int, int) {} //鼠标事件接收器
	virtual void timerEventReceiver(int) {} //计时器事件接收器

	// Listener properties
	bool hascharEventReceiver; //是否需要接收字符输入事件  提供给Display Manager读取，决定挂载窗口时是否启用该事件转发，下同
	bool haskeyEventReceiver; //是否需要接收按键事件
	bool hasmouseEventReceiver; //是否需要接收鼠标事件
	bool hastimerEventReceiver; //是否需要接收计时器事件

	FormBase(int mode); //构造函数，接收事件接收器需求，初始化基类

};