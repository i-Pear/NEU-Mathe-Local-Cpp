#pragma once
#include "FormBase.hpp"

class FormWelcome:public FormBase{
public:
	void display();//��д�Ļ��ƺ���
	FormWelcome();
	void mouseEventReceiver(int x, int y, int button, int event); //��д������¼��������������ж����λ��
};
