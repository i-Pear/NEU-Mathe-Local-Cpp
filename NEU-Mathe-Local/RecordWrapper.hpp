#pragma once
#include "acllib.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

// Class declearition
class ProblemData;
class RecordProvider;

const string BasePath = "D:\\NEUML-Source\\"; //��Դ��·��

//���ڰ�װ�����¼����
class RecordUnit {
public:
	RecordUnit():answer(1),hasDone(0),hasMarked(0){}
	RecordUnit(int answer, int hasDone, int hasMarked) :answer(answer), hasDone(hasDone), hasMarked(hasMarked) {}
	int answer;
	int hasDone;
	int hasMarked;
};

class RecordProvider {
private:
	static vector<RecordUnit> dataArray;
public:
	enum Answer { A = 1, B, C, D } answer; //��ö��
	static int currentChapter; //��ǰ��id
	static int currentSection; //��ǰС��id
	static int countTotal, countMarked, countDone; //ͳ������

	~RecordProvider(); //����������������cpp����һ��ʵ�����������ڳ���ر�ʱ�����������������ܽ�������Ϣ���浽�ļ���
	static void initialize(int chapter, int section); //����ָ���½ڵ�ȫ����Ϣ���ڴ�
	static void saveFile(); //�����ļ�
	static Answer getAnswer(int index); //����ָ����Ŀ��
	static int getDoneStatus(int index); //����ָ����Ŀ��������
	static int getMarkedStatus(int index); //����ָ����Ŀ������
	static void setDoneStatus(int index, int done); //����ָ����Ŀ��������
	static void setMarkStatus(int index, int marked); //����ָ����Ŀ������
	static int getCount(); //���ص�ǰ�½���Ŀ����
};