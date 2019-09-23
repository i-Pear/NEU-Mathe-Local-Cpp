#pragma once
#include "FormBase.hpp"
#include "FormMain.hpp"
#include "FormSelector.hpp"
#include "FormWelcome.hpp"

// A static toolbox class for controlling forms
class DisplayManager {
public:
	static FormBase* window;

	static void KeyboardEventWrapper(int key, int event); //按键事件转发包装器
	static void CharEventWrapper(char c); // 输入事件转发包装器
	static void MouseEventWrapper(int x, int y, int button, int event); //鼠标事件转发包装器
	static void TimerEventWrapper(int timerID); //计时器事件转发包装器
	static void switchWindow(int type, int chapter, int section); //由窗口派生类调用，提供切换窗口服务
	static void initialize(); //初始化操作，加载启动窗口（欢迎界面）
	static void repaint(); //由窗口派生类调用，提供重绘功能
};

int Setup();