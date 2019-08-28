#pragma once
#include <iostream>
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

	URI(int chapter, int section, int index);
};

bool operator == (const URI&, const URI&);
bool operator < (const URI&, const URI& );

class ProblemData {
public:
	static ostringstream oss;
	URI uri;
	ACL_Image images[6];
	enum Answer { A = 1, B, C, D } answer;

	ProblemData();// Build an empty data unit for init
	ProblemData(int chapter, int section, int index);
	ProblemData(const URI& uri);
	Answer getAnswer() const;
	void _loadImage(int chapter, int section, int index);
	~ProblemData();
};

class IocService {
private:
	static const unsigned int maxCapacity;
	static list<ProblemData> cachedList;
	static map<string,ACL_Image> staticList;
public:
	static ProblemData& getProblemData(int chapter, int section, int index);
	static ProblemData& getProblemData(URI destUri);
	static ACL_Image* getStaticImage(string name);
};
