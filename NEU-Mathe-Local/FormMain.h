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

		putImage(&problemData.images[0], (WinWidth - problemData.images[0].width) / 2, (210 - problemData.images[0].height) / 2);
		putImage(&problemData.images[1], (WinWidth / 2 - problemData.images[1].width) / 2, 225);
		putImage(&problemData.images[2], (WinWidth * 3 / 2 - problemData.images[2].width) / 2, 225);
		putImage(&problemData.images[3], (WinWidth / 2 - problemData.images[3].width) / 2, 400);
		putImage(&problemData.images[4], (WinWidth * 3 / 2 - problemData.images[4].width) / 2, 400);

	}
	FormMain(int chapter, int section) :chapter(chapter), section(section), showingID(1), FormBase(mouseEvent|keyEvent) {
		RecordProvider::initialize(chapter, section);
		problemData = IocService::getProblemData(URI(chapter, section, 1));
	}

};
