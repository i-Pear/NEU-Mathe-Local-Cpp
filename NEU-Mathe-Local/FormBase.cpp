#include "FormBase.hpp"

int FormBase::WinWidth = 980;
int FormBase::WinHeight = 520;

int FormBase::getCenterX(int charSize, int charCount) {
	return (WinWidth - charSize * charCount) / 2;
}

FormBase::FormBase(int mode) {
	// Set listener properties
	hascharEventReceiver = (bool)(mode & (1 << 0));
	haskeyEventReceiver = (bool)(mode & (1 << 1));
	hasmouseEventReceiver = (bool)(mode & (1 << 2));
	hastimerEventReceiver = (bool)(mode & (1 << 3));
}