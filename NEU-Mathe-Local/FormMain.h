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
	ProblemData problemData;

	void keyEventReceiver(int, int) {

	}
	void mouseEventReceiver(int, int, int, int) {

	}
	void display() {

	}
	FormMain(int chapter, int section) :chapter(chapter), section(section), showingID(1), FormBase(mouseEvent|keyEvent) {
		RecordProvider::initialize(chapter, section);
		problemData = IocService::getProblemData(URI(chapter, section, 1));

	}

};
