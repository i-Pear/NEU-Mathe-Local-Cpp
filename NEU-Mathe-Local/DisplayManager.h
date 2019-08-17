#pragma once
#include "FormBase.h"
#include "FormMain.h"
#include "FormSelector.h"
#include "FormWelcome.h"

// A static toolbox class for controlling forms
class DisplayManager {
public:
	enum WindowType { Main, Welcome, Selector };
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
	static void switchWindow(WindowType type, int chapter = 0, int section = 0) {
		// Clear event listeners
		registerKeyboardEvent(NULL);
		registerCharEvent(NULL);
		registerMouseEvent(NULL);
		registerTimerEvent(NULL);
		// Remount form class
		if (type == Main) {
			delete window;
			window = new FormMain(chapter,section);
		}
		if (type == Welcome) {
			delete window;
			window = new FormWelcome();
		}
		if (type == Selector) {
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

		repaint();
	}
	static void initialize() {
		window = NULL;
		setTextFont("Microsoft YaHei Light");
		switchWindow(Welcome);
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
	initWindow("NEU Mathe Local", 300, 200, FormBase::WinWidth, FormBase::WinHeight);
	// Must call 'initWindow' before init display manager
	DisplayManager::initialize();
	return 0;
}