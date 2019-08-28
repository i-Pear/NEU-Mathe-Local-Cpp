#pragma once
#include "FormBase.h"
#include "IocService.h"

class FormSelector :public FormBase {
private:
	int chapter;
public:
	void mouseEventReceiver(int x, int y, int button, int event);
	void display();
	FormSelector();
};
