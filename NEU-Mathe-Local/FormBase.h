#pragma once
#include "acllib.h"

class FormBase {
public:
	enum listenerMode { charEvent = 1, keyEvent = 2, mouseEvent = 4, timerEvent = 8 };

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

	static int GetCenterX(int charSize, int charCount){
		return (WinWidth - charSize * charCount) / 2;
	}
	FormBase(int mode) {
		// Set listener properties
		hascharEventReceiver = (bool)(mode & (1 << 0));
		haskeyEventReceiver = (bool)(mode & (1 << 1));
		hasmouseEventReceiver = (bool)(mode & (1 << 2));
		hastimerEventReceiver = (bool)(mode & (1 << 3));
	}

};
