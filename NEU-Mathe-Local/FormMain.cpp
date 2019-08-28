#include "FormMain.h"

inline void FormMain::loadProblem() {
	problemData = IocService::getProblemData(URI(chapter, section, showingID));
	isMarked = RecordProvider::getMarkedStatus(showingID);
	isDone = RecordProvider::getDoneStatus(showingID);
}

void FormMain::keyEventReceiver(int key, int event) {
	if (event != KEY_DOWN)return;
	if (key == 13) { // enter
		// show answer
		isShowingAnswer = !isShowingAnswer;
	}
	else {
		if (isShowingAnswer) return;
	}
	if (key == 39) { // ¡ú
		if (showingID == RecordProvider::getCount() - 1) {
			return;
		}
		showingID++;
		loadProblem();
	}
	if (key == 37) { // ¡û
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
	if (key == 67) { // select chapter
		switchWindow(2, 0, 0);
		return;
	}

	refresh();
}

void FormMain::mouseEventReceiver(int x, int y, int button, int event) {
	if (event != BUTTON_DOWN)return;
	if (isMarked) {
		RecordProvider::setMarkStatus(showingID, 0);
	}
	else {
		RecordProvider::setMarkStatus(showingID, 1);
	}
	isMarked = !isMarked;
	refresh();
}

void FormMain::display() {

	if (!isShowingAnswer) {
		putImage(&problemData.images[0], (WinWidth - problemData.images[0].width) / 2, (210 - problemData.images[0].height) / 2);
		putImage(&problemData.images[1], (WinWidth / 2 - problemData.images[1].width) / 2, 230);
		putImage(&problemData.images[2], (WinWidth * 3 / 2 - problemData.images[2].width) / 2, 230);
		putImage(&problemData.images[3], (WinWidth / 2 - problemData.images[3].width) / 2, 405);
		putImage(&problemData.images[4], (WinWidth * 3 / 2 - problemData.images[4].width) / 2, 405);
		if (isMarked) {
			// show marked icon
			putImageTransparent(IocService::getStaticImage("mark.jpg"), 12, 12, 54, 71, WHITE);
		}
		if (isDone) {
			// show done icon
			putImageTransparent(IocService::getStaticImage("done.jpg"), 890, 12, 80, 71, WHITE);
		}
		ostringstream ossInfo;
		ossInfo << "Inside this chapter :    Total=" << RecordProvider::countTotal << "    NotDone=" << RecordProvider::countTotal - RecordProvider::countDone
			<< "    Marked=" << RecordProvider::countMarked;
		line(0, 493, WinWidth, 493);
		setTextFont("Segoe UI");
		setTextSize(18);
		paintText(10, 498, ossInfo.str().c_str());
		setBrushColor(RGB(230, 230, 230));
		rectangle(400, 495, 700, 518);
		setBrushColor(RGB(6, 176, 37));
		rectangle(400, 496, 400 + 300 * RecordProvider::countDone / RecordProvider::countTotal, 517);

	}
	else {
		putImage(&problemData.images[5], (WinWidth / 2 - problemData.images[5].width) / 2, 250);
	}
}

FormMain::FormMain(int chapter, int section) :chapter(chapter), section(section), showingID(1), isShowingAnswer(false), isMarked(false), FormBase(mouseEvent | keyEvent) {
	RecordProvider::initialize(chapter, section);
	loadProblem();
}
