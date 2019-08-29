#pragma once
#include "FormBase.hpp"

class FormWelcome:public FormBase{
public:
	void display();
	FormWelcome();
	void mouseEventReceiver(int x, int y, int button, int event);
};
