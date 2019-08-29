#pragma once
#include "acllib.h"
#include <string>
#include <sstream>
#include <fstream>
#include "vector.hpp"
using namespace std;

// Class declearition
class ProblemData;
class RecordProvider;

const string BasePath = "D:\\imgout\\";

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
	static Vector<RecordUnit> dataArray;
public:
	enum Answer { A = 1, B, C, D } answer;
	static int currentChapter;
	static int currentSection;
	static int countTotal, countMarked, countDone;

	~RecordProvider();
	static void initialize(int chapter, int section);
	static void saveFile();
	static Answer getAnswer(int index);
	static int getDoneStatus(int index);
	static int getMarkedStatus(int index);
	static void setDoneStatus(int index, int done);
	static void setMarkStatus(int index, int marked);
	static int getCount();
};