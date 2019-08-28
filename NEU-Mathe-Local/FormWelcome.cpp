#include "FormWelcome.h"

void FormWelcome::display() {
	setTextSize(50);
	paintText(getCenterX(50, 10), 150, "欢迎使用 NEU Mathe Local");
	paintText(getCenterX(50, 7), 270, "线性代数练习系统");
}

FormWelcome::FormWelcome():FormBase(mouseEvent) {}

void FormWelcome::mouseEventReceiver(int x, int y, int button, int event) {
	if (event == BUTTON_UP) {
		switchWindow(1, 1, 1);
	}
}