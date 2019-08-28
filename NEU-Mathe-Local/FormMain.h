#pragma once
#include "list.h"
#include "vector.h"
#include "FormBase.h"
#include "RecordWrapper.h"
#include "IocService.h"

class FormMain :public FormBase {
private:
	int chapter;
	int section;
	int showingID;
	bool isShowingAnswer;
	bool isDone;
	bool isMarked;
public:
	ProblemData problemData;

	inline void loadProblem();
	void keyEventReceiver(int key, int event);
	void mouseEventReceiver(int x, int y, int button, int event);
	void display();
	FormMain(int chapter, int section);
};
