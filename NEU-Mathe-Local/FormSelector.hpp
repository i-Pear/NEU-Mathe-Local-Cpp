#pragma once
#include "FormBase.hpp"
#include "IocService.hpp"

//ѡ�½��棬�ṩ���ӻ��½��л�
class FormSelector :public FormBase {
private:
	int chapter; //�ݴ浱ǰ�������id
public:
	void mouseEventReceiver(int x, int y, int button, int event); //��д������¼��������������ж����λ��
	void display(); //��д�Ļ��ƺ���
	FormSelector();// �չ��캯��
};
