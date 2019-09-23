#pragma once
#include "FormBase.hpp"
#include "FormMain.hpp"
#include "FormSelector.hpp"
#include "FormWelcome.hpp"

// A static toolbox class for controlling forms
class DisplayManager {
public:
	static FormBase* window;

	static void KeyboardEventWrapper(int key, int event); //�����¼�ת����װ��
	static void CharEventWrapper(char c); // �����¼�ת����װ��
	static void MouseEventWrapper(int x, int y, int button, int event); //����¼�ת����װ��
	static void TimerEventWrapper(int timerID); //��ʱ���¼�ת����װ��
	static void switchWindow(int type, int chapter, int section); //�ɴ�����������ã��ṩ�л����ڷ���
	static void initialize(); //��ʼ�������������������ڣ���ӭ���棩
	static void repaint(); //�ɴ�����������ã��ṩ�ػ湦��
};

int Setup();