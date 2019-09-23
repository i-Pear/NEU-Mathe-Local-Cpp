#pragma once
#include "list.hpp"
#include <vector>
#include "FormBase.hpp"
#include "RecordWrapper.hpp"
#include "IocService.hpp"

// ��ϰ�����������
class FormMain :public FormBase {
private:
	int chapter; //��ǰ��
	int section; //��ǰС��
	int showingID; //��ǰС���ڣ���ʾ����Ŀid
	bool isShowingAnswer; //�Ƿ�����ʾ��ģʽ���ṩ�����ƺ�����ȡ
	bool isDone; //��ǰ��Ŀ�Ƿ�����ɣ��ṩ�����ƺ�����ȡ
	bool isMarked; //��ǰ��Ŀ�Ƿ񱻱�ǣ��ṩ�����ƺ�����ȡ
	static ostringstream ossInfo; //��Ϣ���ֵĹ����ַ����ϳ����������ڴ�ռ�úͷ�����ʼ������
	static ostringstream ossAnswer; //�����ֵ��ַ����ϳ���
public:
	ProblemData problemData; //��ǰ��ʾ����Ŀ��Ϣ

	inline void loadProblem(); //������Ŀ
	void keyEventReceiver(int key, int event); //��д�İ����¼�����������׽����
	void mouseEventReceiver(int x, int y, int button, int event); //��д������¼�������
	void display(); //��д�Ļ��ƺ���
	FormMain(int chapter, int section); //���캯��
};
