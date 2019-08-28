#pragma once
#include "FormBase.h"
#include "FormMain.h"
#include "FormSelector.h"
#include "FormWelcome.h"

// A static toolbox class for controlling forms
class DisplayManager {
public:
	static FormBase* window;

	static void KeyboardEventWrapper(int key, int event);
	static void CharEventWrapper(char c);
	static void MouseEventWrapper(int x, int y, int button, int event);
	static void TimerEventWrapper(int timerID);
	static void switchWindow(int type, int chapter, int section);
	static void initialize();
	static void repaint();
};

int Setup();