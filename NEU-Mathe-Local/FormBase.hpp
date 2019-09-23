#pragma once
#include "acllib.h"

class FormBase {
protected:
	static int getCenterX(int charSize, int charCount);
public:
	enum listenerMode { charEvent = 1, keyEvent = 2, mouseEvent = 4, timerEvent = 8 }; //�ṩ����������ö�٣�ʹ��ʱ��|����������Խ����ѡ��ϳ�Ϊһ��

	void (*switchWindow)(int, int, int) = NULL; //��DisplayManagerͨ�ŵ��л����ں���ָ�룬��DisplayManager��ֵ
	void (*refresh)() = NULL; //��DisplayManagerͨ�ŵ��ػ溯��ָ�룬��DisplayManager��ֵ

	static int WinWidth; //���ڿ�� ����ACLlib���ڴ�С�ڳ�ʼ��ʱȷ��������ʹ�þ�̬
	static int WinHeight; //���ڸ߶�

	// Must be overwritten
	virtual void display() = 0; // ���ƺ��� ���ô�����������л���

	// Can overwrite
	virtual void charEventReceiver(char) {} //�����ַ��¼�����������Display Manager���ã���ͬ
	virtual void keyEventReceiver(int,int){} // �����¼�������
	virtual void mouseEventReceiver(int, int, int, int) {} //����¼�������
	virtual void timerEventReceiver(int) {} //��ʱ���¼�������

	// Listener properties
	bool hascharEventReceiver; //�Ƿ���Ҫ�����ַ������¼�  �ṩ��Display Manager��ȡ���������ش���ʱ�Ƿ����ø��¼�ת������ͬ
	bool haskeyEventReceiver; //�Ƿ���Ҫ���հ����¼�
	bool hasmouseEventReceiver; //�Ƿ���Ҫ��������¼�
	bool hastimerEventReceiver; //�Ƿ���Ҫ���ռ�ʱ���¼�

	FormBase(int mode); //���캯���������¼����������󣬳�ʼ������

};