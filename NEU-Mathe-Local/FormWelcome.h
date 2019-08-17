#pragma once
#include "FormBase.h"

class FormWelcome:public FormBase{
public:
	void display() {
		setTextSize(50);
		paintText(GetCenterX(50, 10), 130, "欢迎使用 NEU Mathe Local");
		paintText(GetCenterX(50, 7), 220, "线性代数练习系统");
	}

	FormWelcome():FormBase(mouseEvent) {

	}

	void mouseEventReceiver(int x, int y, int button, int event) {

		//msgBox("Title", "You clicked!", 2);
	}

};

