#pragma once
#include "FormBase.hpp"
#include "IocService.hpp"

class FormSelector :public FormBase {
private:
	int chapter;
public:
	void mouseEventReceiver(int x, int y, int button, int event);
	void display();
	FormSelector();
};
