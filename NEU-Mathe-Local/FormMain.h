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
	bool isShowingAnswer;
	bool isDone;
	bool isMarked;

	ProblemData problemData;

	inline void loadProblem() {
		problemData = IocService::getProblemData(URI(chapter, section, showingID));
		isMarked = RecordProvider::getMarkedStatus(showingID);
		isDone = RecordProvider::getDoneStatus(showingID);
	}

	void keyEventReceiver(int key, int event) {
		if (event != KEY_DOWN)return;
		if (key == 13) { // enter
			// show answer
			isShowingAnswer = !isShowingAnswer;
		}
		else {
			if (isShowingAnswer) return;
		}
		if (key == 39) { // ��
			if (showingID == RecordProvider::getCount() - 1) {
				return;
			}
			showingID++;
			loadProblem();
		}
		if (key == 37) { // ��
			if (showingID == 1) {
				return;
			}
			showingID--;
			loadProblem();
		}
		if (key == 17) { // ctrl
			if (isDone) {
				RecordProvider::setDoneStatus(showingID, 0);
			}
			else {
				RecordProvider::setDoneStatus(showingID, 1);
			}
			isDone = !isDone;
		}
		if (key == 32) {} // space

		refresh();
	}
	void mouseEventReceiver(int x, int y, int button, int event) {
		if (event != BUTTON_DOWN)return;
		if (isMarked) {
			RecordProvider::setMarkStatus(showingID, 0);
		} else {
			RecordProvider::setMarkStatus(showingID, 1);
		}
		isMarked = !isMarked;
		refresh();
	}
	void display() {
		if (!isShowingAnswer) {
			putImage(&problemData.images[0], (WinWidth - problemData.images[0].width) / 2, (210 - problemData.images[0].height) / 2);
			putImage(&problemData.images[1], (WinWidth / 2 - problemData.images[1].width) / 2, 225);
			putImage(&problemData.images[2], (WinWidth * 3 / 2 - problemData.images[2].width) / 2, 225);
			putImage(&problemData.images[3], (WinWidth / 2 - problemData.images[3].width) / 2, 400);
			putImage(&problemData.images[4], (WinWidth * 3 / 2 - problemData.images[4].width) / 2, 400);
			if (isMarked) {
				// show marked icon
				putImageTransparent(IocService::getStaticImage("mark.jpg"), 12, 12, 54, 71, WHITE);
			}
			if (isDone) {
				// show done icon
				putImageTransparent(IocService::getStaticImage("done.jpg"), 800, 12, 80, 71, WHITE);
			}
		} else {
			putImage(&problemData.images[5], (WinWidth / 2 - problemData.images[5].width) / 2, 250);
		}
	}
	FormMain(int chapter, int section) :chapter(chapter), section(section), showingID(1), isShowingAnswer(false), isMarked(false), FormBase(mouseEvent|keyEvent) {
		RecordProvider::initialize(chapter, section);
		loadProblem();
	}
};
