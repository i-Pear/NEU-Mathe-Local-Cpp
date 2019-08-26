#pragma once
#include "FormBase.h"

class FormWelcome:public FormBase{
public:
	void display() {
		setTextSize(50);
		paintText(getCenterX(50, 10), 150, "欢迎使用 NEU Mathe Local");
		paintText(getCenterX(50, 7), 270, "线性代数练习系统");
	}
	FormWelcome():FormBase(mouseEvent) {}
	void mouseEventReceiver(int x, int y, int button, int event) {
		if (event == BUTTON_UP) {
			switchWindow(1, 1, 1);
		}
	}
};

