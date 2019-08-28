#include "RecordWrapper.h"

Vector<RecordUnit> RecordProvider::dataArray;
int RecordProvider::currentChapter = -1;
int RecordProvider::currentSection = -1;
int RecordProvider::countTotal, RecordProvider::countMarked, RecordProvider::countDone;

RecordProvider recordProvider; // Call destroyer function when program exits to save file