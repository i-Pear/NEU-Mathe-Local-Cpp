#pragma once
#include "acllib.h"

class FormBase {
protected:
	static int getCenterX(int charSize, int charCount);
public:
	enum listenerMode { charEvent = 1, keyEvent = 2, mouseEvent = 4, timerEvent = 8 };

	void (*switchWindow)(int, int, int) = NULL;
	void (*refresh)() = NULL;

	static int WinWidth;
	static int WinHeight;

	// Must be overwritten
	virtual void display() = 0;

	// Can overwrite
	virtual void charEventReceiver(char) {} 
	virtual void keyEventReceiver(int,int){}
	virtual void mouseEventReceiver(int, int, int, int) {}
	virtual void timerEventReceiver(int) {}

	// Listener properties
	bool hascharEventReceiver;
	bool haskeyEventReceiver;
	bool hasmouseEventReceiver;
	bool hastimerEventReceiver;

	FormBase(int mode);

};
