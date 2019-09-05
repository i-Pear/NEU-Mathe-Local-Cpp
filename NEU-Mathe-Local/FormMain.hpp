#pragma once
#include "list.hpp"
#include <vector>
#include "FormBase.hpp"
#include "RecordWrapper.hpp"
#include "IocService.hpp"

class FormMain :public FormBase {
private:
	int chapter;
	int section;
	int showingID;
	bool isShowingAnswer;
	bool isDone;
	bool isMarked;
	static ostringstream ossInfo;
	static ostringstream ossAnswer;
public:
	ProblemData problemData;

	inline void loadProblem();
	void keyEventReceiver(int key, int event);
	void mouseEventReceiver(int x, int y, int button, int event);
	void display();
	FormMain(int chapter, int section);
};
