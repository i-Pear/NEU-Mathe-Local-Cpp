#pragma once
#include "FormBase.h"

class FormWelcome:public FormBase{
public:
	void display() {
		setTextSize(50);
		paintText(GetCenterX(50, 10), 130, "��ӭʹ�� NEU Mathe Local");
		paintText(GetCenterX(50, 7), 220, "���Դ�����ϰϵͳ");
	}

	FormWelcome():FormBase(mouseEvent) {

	}

	void mouseEventReceiver(int x, int y, int button, int event) {

		//msgBox("Title", "You clicked!", 2);
	}

};

