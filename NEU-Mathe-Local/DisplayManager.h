#pragma once
#include "FormBase.h"
#include "FormMain.h"
#include "FormSelector.h"
#include "FormWelcome.h"

// A static toolbox class for controlling forms
class DisplayManager {
public:
	static FormBase* window;

	static void KeyboardEventWrapper(int key, int event) {
		window->keyEventReceiver(key, event);
	}
	static void CharEventWrapper(char c) {
		window->charEventReceiver(c);
	}
	static void MouseEventWrapper(int x, int y, int button, int event) {
		window->mouseEventReceiver(x, y, button, event);
	}
	static void TimerEventWrapper(int timerID) {
		window->timerEventReceiver(timerID);
	}
	static void switchWindow(int type, int chapter, int section) {
		// Clear event listeners
		registerKeyboardEvent(NULL);
		registerCharEvent(NULL);
		registerMouseEvent(NULL);
		registerTimerEvent(NULL);
		// Remount form class
		if (type == 1) {
			delete window;
			window = new FormMain(chapter,section);
		}
		if (type == 0) {
			delete window;
			window = new FormWelcome();
		}
		if (type == 2) {
			delete window;
			window = new FormSelector();
		}
		// Remount event listeners
		if (window->haskeyEventReceiver) {
			registerKeyboardEvent(KeyboardEventWrapper);
		}
		if (window->hascharEventReceiver) {
			registerCharEvent(CharEventWrapper);
		}
		if (window->hasmouseEventReceiver) {
			registerMouseEvent(MouseEventWrapper);
		}
		if (window->hastimerEventReceiver) {
			registerTimerEvent(TimerEventWrapper);
		}

		window->switchWindow = switchWindow;
		window->refresh = repaint;

		repaint();
	}
	static void initialize() {
		window = NULL;
		beginPaint();
		setTextFont("Microsoft YaHei Light");
		endPaint();
		switchWindow(0, 1, 1);
		repaint();
	}
	static void repaint() {
		beginPaint();
		clearDevice();
		window->display();
		endPaint();
	}
};

FormBase* DisplayManager::window = NULL;

int Setup() {
	initWindow("NEU Mathe Local - Linear Algebra", 300, 200, FormBase::WinWidth, FormBase::WinHeight);
	// Must call 'initWindow' before init display manager
	DisplayManager::initialize();
	return 0;
}