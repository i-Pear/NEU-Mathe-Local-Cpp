#pragma once
#include "FormBase.hpp"
#include "FormMain.hpp"
#include "FormSelector.hpp"
#include "FormWelcome.hpp"

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