#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include "acllib.h"
#include "RecordWrapper.hpp"
#include "list.hpp"
using namespace std;

// Universal Resource Identifier
// 用途是包装题目的位置信息，作用类似于题目的身份证；减少在传递时的参数数量，同时便于查找
class URI {
public:
	int chapter; //题目章id
	int section; //题目小节id
	int index; //题目在小节中的序号

	URI(int chapter, int section, int index); //构造函数
};

bool operator == (const URI&, const URI&); //重载相等运算符，便于比较
bool operator < (const URI&, const URI& ); //重载相等运算符，使其可以被STL中的查找树使用


//用于封装题目信息的包装类
class ProblemData {
public:
	static ostringstream oss; //
	URI uri; //题目的位置信息
	ACL_Image images[6]; //题目的六张图片
	enum Answer { A = 1, B, C, D } answer;

	ProblemData();// Build an empty data unit for init
	ProblemData(int chapter, int section, int index); //构造函数，自动加载资源
	ProblemData(const URI& uri); //URI封装的上述函数
	Answer getAnswer() const; //返回答案值
	void _loadImage(int chapter, int section, int index); //加载图片，由于太复杂，独立为一个函数
	~ProblemData(); //析构函数，释放图片等资源
};

class IocService {
private:
	static const unsigned int maxCapacity; //最大缓存容量，超过时会释放不常用资源
	static list<ProblemData> cachedList; //缓存的题目列表
	static map<string,ACL_Image> staticList; //缓存的常用UI资源列表，不会被释放
public:
	static ProblemData& getProblemData(int chapter, int section, int index); //外部访问接口，返回需要的题目信息
	static ProblemData& getProblemData(URI destUri); //URI封装的上方函数
	static ACL_Image* getStaticImage(string name); //外部访问接口，返回静态资源信息
};
