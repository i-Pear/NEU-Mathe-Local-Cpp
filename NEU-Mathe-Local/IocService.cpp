#include "IocService.h"

const unsigned int IocService::maxCapacity = 20;
list<ProblemData> IocService::cachedList;
map<string,ACL_Image> IocService::staticList;