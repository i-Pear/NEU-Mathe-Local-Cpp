#include "RecordWrapper.h"

Vector<RecordUnit> RecordProvider::dataArray;
int RecordProvider::currentChapter;
int RecordProvider::currentSection;

RecordProvider recordProvider; // Call destroyer function when program exits to save file