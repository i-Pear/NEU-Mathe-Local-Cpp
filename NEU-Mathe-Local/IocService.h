#pragma once
#include <iostream>
#include <queue>
#include <sstream>
#include <map>
#include "acllib.h"
#include "RecordWrapper.h"
#include "list.h"
using namespace std;

// Universal Resource Identifier
class URI {
public:
	int chapter;
	int section;
	int index;

	URI(int chapter, int section, int index):chapter(chapter),section(section),index(index){}
	bool operator == (const URI& b)const {
		return (chapter == b.chapter && section == b.section && index == b.index);
	}
	bool operator < (const URI& b)const {
		if (chapter != b.chapter) return chapter < b.chapter;
		if (section != b.section) return section < b.section;
		return index < b.index;
	}
};

class ProblemData {
public:
	URI uri;
	ACL_Image images[6];
	enum Answer { A = 1, B, C, D } answer;

	ProblemData() :uri(0, 0, 0) {} // Build an empty data unit for init
	ProblemData(int chapter, int section, int index):uri(chapter,section,index) {
		_loadImage(uri.chapter, uri.section, uri.index);
		answer = Answer(RecordProvider::getAnswer(uri.index));
	}
	ProblemData(const URI& uri):uri(uri){
		_loadImage(uri.chapter, uri.section, uri.index);
		answer = Answer(RecordProvider::getAnswer(uri.index));
	}
	Answer getAnswer() const {
		return answer;
	}
	void _loadImage(int chapter, int section, int index) {
		ostringstream oss;
		for (int i = 0; i <= 4; i++) {
			oss.str("");
			oss << BasePath << chapter << "\\" << section << "\\" << index << '_' << i << ".jpg";
			loadImage(oss.str().c_str(), &images[i]);
		}
		oss.str("");
		oss << BasePath << chapter << "\\" << section << "\\" << index << '_' << "ans.jpg";
		loadImage(oss.str().c_str(), &images[5]);
	}
	~ProblemData() {
		for (int i = 0; i < 6; i++) {
			freeImage(&images[i]);
		}
	}
};

class IocService {
private:
	static const unsigned int maxCapacity;
	static list<ProblemData> cachedList;
	static map<string,ACL_Image> staticList;
public:
	static ProblemData& getProblemData (int chapter, int section, int index) {
		URI uri(chapter, section, index);
		return getProblemData(uri);
	}
	static ProblemData& getProblemData(URI destUri) {
		for (auto& i : cachedList) {
			if (i.uri == destUri) {
				return i;
			}
		}

		// ERROR HERE
		if (cachedList.Size() > maxCapacity-1) {
			//cachedList.PopBack();
		}
		cachedList.PushFront(ProblemData(destUri));
		/*  这里应该有一个把已存在的数据提到链表最前的feature
			在链表里实现一下 */
		return *cachedList.begin();
	}
	static ACL_Image* getStaticImage(string name) {
		auto temp = staticList.find(name);
		if (temp != staticList.end()) {
			return &temp->second;
		}
		else {
			staticList.insert(pair<string,ACL_Image>(name,ACL_Image()));
			loadImage((BasePath + name).c_str(), &staticList[name]);
			return &staticList[name];
		}
	}
};
