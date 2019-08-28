#include "IocService.h"

URI::URI(int chapter, int section, int index) :chapter(chapter), section(section), index(index) {}

bool operator == (const URI& a, const URI& b) {
	return (a.chapter == b.chapter && a.section == b.section && a.index == b.index);
}

bool operator < (const URI& a, const URI& b) {
	if (a.chapter != b.chapter) return a.chapter < b.chapter;
	if (a.section != b.section) return a.section < b.section;
	return a.index < b.index;
}

ostringstream ProblemData::oss;

ProblemData::ProblemData() :uri(0, 0, 0) {} // Build an empty data unit for init

ProblemData::ProblemData(int chapter, int section, int index) :uri(chapter, section, index) {
	_loadImage(uri.chapter, uri.section, uri.index);
	answer = Answer(RecordProvider::getAnswer(uri.index));
}

ProblemData::ProblemData(const URI& uri) :uri(uri) {
	_loadImage(uri.chapter, uri.section, uri.index);
	answer = Answer(RecordProvider::getAnswer(uri.index));
}

ProblemData::Answer ProblemData::getAnswer() const {
	return answer;
}

void ProblemData::_loadImage(int chapter, int section, int index) {
	
	for (int i = 0; i <= 4; i++) {
		oss.str("");
		oss << BasePath << chapter << "\\" << section << "\\" << index << '_' << i << ".jpg";
		loadImage(oss.str().c_str(), &images[i]);
	}
	oss.str("");
	oss << BasePath << chapter << "\\" << section << "\\" << index << '_' << "ans.jpg";
	loadImage(oss.str().c_str(), &images[5]);
}

ProblemData::~ProblemData() {
	for (int i = 0; i < 6; i++) {
		freeImage(&images[i]);
	}
}


const unsigned int IocService::maxCapacity = 20;
list<ProblemData> IocService::cachedList;
map<string, ACL_Image> IocService::staticList;

ProblemData& IocService::getProblemData(int chapter, int section, int index) {
	URI uri(chapter, section, index);
	return getProblemData(uri);
}

ProblemData& IocService::getProblemData(URI destUri) {
	for (auto& i : cachedList) {
		if (i.uri == destUri) {
			return i;
		}
	}

	// ERROR HERE
	if (cachedList.Size() > maxCapacity - 1) {
		//cachedList.PopBack();
	}
	cachedList.PushFront(ProblemData(destUri));
	/*  这里应该有一个把已存在的数据提到链表最前的feature
		在链表里实现一下 */
	return *cachedList.begin();
}

ACL_Image* IocService::getStaticImage(string name) {
	auto temp = staticList.find(name);
	if (temp != staticList.end()) {
		return &temp->second;
	}
	else {
		staticList.insert(pair<string, ACL_Image>(name, ACL_Image()));
		loadImage((BasePath + name).c_str(), &staticList[name]);
		return &staticList[name];
	}
}