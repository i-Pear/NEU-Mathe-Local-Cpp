#pragma once
#include "FormBase.h"

class FormWelcome:public FormBase{
public:
	void display();
	FormWelcome();
	void mouseEventReceiver(int x, int y, int button, int event);
};
