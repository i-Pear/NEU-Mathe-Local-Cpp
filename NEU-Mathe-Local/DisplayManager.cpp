#include "DisplayManager.hpp"

void DisplayManager::KeyboardEventWrapper(int key, int event) {
		window->keyEventReceiver(key, event);
	}
void DisplayManager::CharEventWrapper(char c) {
		window->charEventReceiver(c);
	}
void DisplayManager::MouseEventWrapper(int x, int y, int button, int event) {
		window->mouseEventReceiver(x, y, button, event);
	}
void DisplayManager::TimerEventWrapper(int timerID) {
		window->timerEventReceiver(timerID);
	}
void DisplayManager::switchWindow(int type, int chapter, int section) {
		// Clear event listeners
		registerKeyboardEvent(NULL);
		registerCharEvent(NULL);
		registerMouseEvent(NULL);
		registerTimerEvent(NULL);
		// Remount form class
		if (type == 1) {
			delete window;
			window = new FormMain(chapter, section);
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
void DisplayManager::initialize() {
		window = NULL;
		beginPaint();
		setTextFont("Microsoft YaHei Light");
		endPaint();
		switchWindow(0, 1, 1);
		repaint();
	}
void DisplayManager::repaint() {
		beginPaint();
		clearDevice();
		window->display();
		endPaint();
	}

FormBase* DisplayManager::window = NULL;

int Setup() {
	initWindow("NEU Mathe Local C++  - Linear Algebra", 300, 200, FormBase::WinWidth, FormBase::WinHeight);
	// Must call 'initWindow' before init display manager
	DisplayManager::initialize();
	return 0;
}