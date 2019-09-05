#include "RecordWrapper.hpp"

vector<RecordUnit> RecordProvider::dataArray;

int RecordProvider::currentChapter = -1;
int RecordProvider::currentSection = -1;
int RecordProvider::countTotal, RecordProvider::countMarked, RecordProvider::countDone;

RecordProvider recordProvider; // Call destroyer function when program exits to save file

RecordProvider::~RecordProvider() { saveFile(); }

void RecordProvider::initialize(int chapter, int section) {
	try
	{
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
			dataArray.push_back(RecordUnit(tempAns, tempHasDone, tempHasMarked));
			if (tempHasDone)countDone++;
			if (tempHasMarked)countMarked++;
		}
		reader.close();
	}
	catch (const std::exception& ex)
	{
		msgBox("Exception captured", "Failed in reading data file...", 1);
	}
}

void RecordProvider::saveFile() {
	try
	{
		ostringstream oss;
		oss << BasePath << currentChapter << "\\" << currentSection << "\\" << "data.txt";
		ofstream writter;
		writter.open(oss.str(), ios::out);
		writter << dataArray.size() << endl;
		for (auto& i : dataArray) {
			writter << i.answer << " " << i.hasDone << " " << i.hasMarked << endl;
		}
		writter.close();
	}
	catch (const std::exception& ex)
	{
		msgBox("Exception captured", "Failed in saving data file...", 1);
	}
}

RecordProvider::Answer RecordProvider::getAnswer(int index) {
	return (Answer)dataArray[--index].answer;
}

int RecordProvider::getDoneStatus(int index) {
	return dataArray[--index].hasDone;
}

int RecordProvider::getMarkedStatus(int index) {
	return dataArray[--index].hasMarked;
}

void RecordProvider::setDoneStatus(int index, int done) {
	if (dataArray[--index].hasDone == done) return;
	dataArray[index].hasDone = done;
	if (done)countDone++; else countDone--;
}

void RecordProvider::setMarkStatus(int index, int marked) {
	if (dataArray[--index].hasMarked == marked)return;
	dataArray[index].hasMarked = marked;
	if (marked)countMarked++; else countMarked--;
}

int RecordProvider::getCount() {
	return dataArray.size();
}