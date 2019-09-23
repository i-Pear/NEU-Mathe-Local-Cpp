#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include "acllib.h"
#include "RecordWrapper.hpp"
#include "list.hpp"
using namespace std;

// Universal Resource Identifier
// ��;�ǰ�װ��Ŀ��λ����Ϣ��������������Ŀ�����֤�������ڴ���ʱ�Ĳ���������ͬʱ���ڲ���
class URI {
public:
	int chapter; //��Ŀ��id
	int section; //��ĿС��id
	int index; //��Ŀ��С���е����

	URI(int chapter, int section, int index); //���캯��
};

bool operator == (const URI&, const URI&); //�����������������ڱȽ�
bool operator < (const URI&, const URI& ); //��������������ʹ����Ա�STL�еĲ�����ʹ��


//���ڷ�װ��Ŀ��Ϣ�İ�װ��
class ProblemData {
public:
	static ostringstream oss; //
	URI uri; //��Ŀ��λ����Ϣ
	ACL_Image images[6]; //��Ŀ������ͼƬ
	enum Answer { A = 1, B, C, D } answer;

	ProblemData();// Build an empty data unit for init
	ProblemData(int chapter, int section, int index); //���캯�����Զ�������Դ
	ProblemData(const URI& uri); //URI��װ����������
	Answer getAnswer() const; //���ش�ֵ
	void _loadImage(int chapter, int section, int index); //����ͼƬ������̫���ӣ�����Ϊһ������
	~ProblemData(); //�����������ͷ�ͼƬ����Դ
};

class IocService {
private:
	static const unsigned int maxCapacity; //��󻺴�����������ʱ���ͷŲ�������Դ
	static list<ProblemData> cachedList; //�������Ŀ�б�
	static map<string,ACL_Image> staticList; //����ĳ���UI��Դ�б����ᱻ�ͷ�
public:
	static ProblemData& getProblemData(int chapter, int section, int index); //�ⲿ���ʽӿڣ�������Ҫ����Ŀ��Ϣ
	static ProblemData& getProblemData(URI destUri); //URI��װ���Ϸ�����
	static ACL_Image* getStaticImage(string name); //�ⲿ���ʽӿڣ����ؾ�̬��Դ��Ϣ
};
