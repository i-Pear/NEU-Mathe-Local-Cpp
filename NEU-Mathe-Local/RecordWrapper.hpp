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

const string BasePath = "D:\\NEUML-Source\\"; //资源基路径

//用于包装做题记录的类
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
	enum Answer { A = 1, B, C, D } answer; //答案枚举
	static int currentChapter; //当前章id
	static int currentSection; //当前小节id
	static int countTotal, countMarked, countDone; //统计数据

	~RecordProvider(); //析构函数，此类在cpp中有一个实例，作用是在程序关闭时，调用析构函数，能将最后的信息保存到文件中
	static void initialize(int chapter, int section); //加载指定章节的全部信息到内存
	static void saveFile(); //保存文件
	static Answer getAnswer(int index); //返回指定题目答案
	static int getDoneStatus(int index); //返回指定题目已完成情况
	static int getMarkedStatus(int index); //返回指定题目标记情况
	static void setDoneStatus(int index, int done); //更改指定题目已完成情况
	static void setMarkStatus(int index, int marked); //更改指定题目标记情况
	static int getCount(); //返回当前章节题目数量
};