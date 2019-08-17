#pragma once
#include "hashmap.h"
#include "list.h"
#include "vector.h"
#include "FormBase.h"
#include "RecordWrapper.h"
#include "IocService.h"

class FormMain :public FormBase {
public:
	int chapter;
	int section;
	int showingID;
	ProblemData* problemData;
	void display() {

	}
	FormMain(int chapter, int section) :chapter(chapter), section(section), showingID(1), FormBase(0) {
		RecordProvider::initialize(chapter, section);
		problemData = new ProblemData(chapter, section, 1);
	}

};
