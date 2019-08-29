#include "FormSelector.hpp"

void FormSelector::mouseEventReceiver(int x, int y, int button, int event) {
	if (event != BUTTON_DOWN)return;

	////////////////////////////////////////////////////////////
	//           //             //             //             //
	//     1     //      2      //      3      //      4      //
	//           //             //             //             //
	////////////////////////////////////////////////////////////
	//           //             //             //             //
	//     5     //      6      //      7      //      8      //
	//           //             //             //             //
	////////////////////////////////////////////////////////////

	int selection = -1;
	{
		if (y <= WinHeight / 2)selection = 0;
		else selection = 4;

		if (x <= WinWidth / 4)selection += 1;
		else if (x <= WinWidth / 2)selection += 2;
		else if (x <= WinWidth * 3 / 4)selection += 3;
		else selection += 4;
	}

	if (chapter == 0) {
		if (selection >= 1 && selection <= 7) {
			chapter = selection;
			refresh();
			return;
		}
	}
	if (selection == 8) {
		chapter = 0;
		refresh();
		return;
	}
	if (chapter == 1) {
		if (selection >= 1 && selection <= 2) {
			switchWindow(1, chapter, selection);
		}
	}
	if (chapter == 2) {
		if (selection >= 1 && selection <= 3) {
			switchWindow(1, chapter, selection);
		}
	}
	if (chapter == 3) {
		if (selection >= 1 && selection <= 3) {
			switchWindow(1, chapter, selection);
		}
	}
	if (chapter == 4) {
		if (selection >= 1 && selection <= 3) {
			switchWindow(1, chapter, selection);
		}
	}
	if (chapter == 5) {
		if (selection >= 1 && selection <= 2) {
			switchWindow(1, chapter, selection);
		}
	}
	if (chapter == 6) {
		if (selection >= 1 && selection <= 2) {
			switchWindow(1, chapter, selection);
		}
	}
	if (chapter == 7) {
		if (selection >= 1 && selection <= 2) {
			switchWindow(1, chapter, selection);
		}
	}
}
void FormSelector::display() {
	ostringstream oss;
	oss << "menu" << chapter << ".jpg";
	putImageScale(IocService::getStaticImage(oss.str()), 0, 0, WinWidth, WinHeight);
}

FormSelector::FormSelector() :FormBase(mouseEvent), chapter(0) {}
