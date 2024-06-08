#pragma once

#include "list_set.h"

//并集
ListSet UnionListSet(ListSet list_set1, ListSet list_set2);

//交集
ListSet IntersectionListSet(ListSet list_set1, ListSet list_set2);

//差集
ListSet DifferenceListSet(ListSet list_set1, ListSet list_set2);

//对称差集
ListSet SymmetricDifferenceListSet(ListSet list_set1, ListSet list_set2);