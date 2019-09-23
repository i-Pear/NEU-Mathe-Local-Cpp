#pragma once
#include "list.hpp"
#include <vector>
#include "FormBase.hpp"
#include "RecordWrapper.hpp"
#include "IocService.hpp"

// 练习界面的主窗口
class FormMain :public FormBase {
private:
	int chapter; //当前章
	int section; //当前小节
	int showingID; //当前小节内，显示的题目id
	bool isShowingAnswer; //是否是显示答案模式，提供给绘制函数读取
	bool isDone; //当前题目是否已完成，提供给绘制函数读取
	bool isMarked; //当前题目是否被标记，提供给绘制函数读取
	static ostringstream ossInfo; //信息文字的共用字符串合成器，减少内存占用和反复初始化开销
	static ostringstream ossAnswer; //答案文字的字符串合成器
public:
	ProblemData problemData; //当前显示的题目信息

	inline void loadProblem(); //加载题目
	void keyEventReceiver(int key, int event); //重写的按键事件接收器，捕捉按键
	void mouseEventReceiver(int x, int y, int button, int event); //重写的鼠标事件接收器
	void display(); //重写的绘制函数
	FormMain(int chapter, int section); //构造函数
};
