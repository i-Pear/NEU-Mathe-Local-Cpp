#include "FormWelcome.h"

void FormWelcome::display() {
	setTextSize(50);
	paintText(getCenterX(50, 10), 150, "��ӭʹ�� NEU Mathe Local");
	paintText(getCenterX(50, 7), 270, "���Դ�����ϰϵͳ");
}

FormWelcome::FormWelcome():FormBase(mouseEvent) {}

void FormWelcome::mouseEventReceiver(int x, int y, int button, int event) {
	if (event == BUTTON_UP) {
		switchWindow(1, 1, 1);
	}
}