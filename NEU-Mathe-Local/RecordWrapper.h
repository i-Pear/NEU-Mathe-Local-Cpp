#pragma once
#include "acllib.h"
#include <string>
#include <sstream>
#include <fstream>
#include "vector.h"
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

	~RecordProvider() { saveFile(); }
	static void initialize(int chapter, int section) {

		if (currentChapter != -1 && currentSection != -1) {
			saveFile();
		}

		currentChapter = chapter;
		currentSection = section;

		ostringstream oss;
		oss << BasePath << chapter << "\\" << section << "\\" << "data.txt";
		ifstream reader;
		reader.open(oss.str(), ios::in);

		dataArray.clear();
		countTotal = 0;
		countMarked = 0;
		countDone = 0;
		int n;
		reader >> n;
		countTotal = n;
		int tempAns, tempHasDone, tempHasMarked;
		for (int i = 0; i < n; i++) {
			reader >> tempAns >> tempHasDone >> tempHasMarked;
			dataArray.PushBack(RecordUnit(tempAns, tempHasDone, tempHasMarked));
			if (tempHasDone)countDone++;
			if (tempHasMarked)countMarked++;
		}
		reader.close();
	}
	static void saveFile() {
		ostringstream oss;
		oss << BasePath << currentChapter << "\\" << currentSection << "\\" << "data.txt";
		ofstream writter;
		writter.open(oss.str(), ios::out);
		writter << dataArray.Size() << endl;
		for (auto& i : dataArray) {
			writter << i.answer << " " << i.hasDone << " " << i.hasMarked << endl;
		}
		writter.close();
	}
	static Answer getAnswer(int index) {
		return (Answer)dataArray[--index].answer;
	}
	static int getDoneStatus(int index) {
		return dataArray[--index].hasDone;
	}
	static int getMarkedStatus(int index) {
		return dataArray[--index].hasMarked;
	}
	static void setDoneStatus(int index, int done) {
		if (dataArray[--index].hasDone == done) return;
		dataArray[index].hasDone = done;
		if (done)countDone++; else countDone--;
	}
	static void setMarkStatus(int index, int marked) {
		if (dataArray[--index].hasMarked == marked)return;
		dataArray[index].hasMarked = marked;
		if (marked)countMarked++; else countMarked--;
	}
	static int getCount() {
		return dataArray.Size();
	}
};