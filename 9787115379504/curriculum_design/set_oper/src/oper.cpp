#include "oper.h"

ListSet UnionListSet(ListSet list_set1, ListSet list_set2) {
    ListSet ret = InitListSet(ret);
    int list_set1_index = 0;
    int list_set2_index = 0;
    while (list_set1_index < list_set1.size && list_set2_index < list_set2.size) {
        int list_set1_elem = SrchElem(list_set1, list_set1_index);
        int list_set2_elem = SrchElem(list_set2, list_set2_index);
        if (list_set1_elem <= list_set2_elem) {
            if (SrchIndex(ret, list_set1_elem) == -1) {
                Ins(ret, ret.size++, list_set1_elem);
            }
            list_set1_index++;
        }
        else {
            if (SrchIndex(ret, list_set2_elem) == -1) {
                Ins(ret, ret.size++, list_set2_elem);
            }
            list_set2_index++;
        }
    }
    while (list_set1_index < list_set1.size) {
        int list_set1_elem = SrchElem(list_set1, list_set1_index);
        if (SrchIndex(ret, list_set1_elem) == -1) {
            Ins(ret, ret.size++, list_set1_elem);
        }
        list_set1_index++;
    }
    while (list_set2_index < list_set2.size) {
        int list_set2_elem = SrchElem(list_set2, list_set2_index);
        if (SrchIndex(ret, list_set2_elem) == -1) {
            Ins(ret, ret.size++, list_set2_elem);
        }
        list_set2_index++;
    }
    return ret;
}

ListSet IntersectionListSet(ListSet list_set1, ListSet list_set2) {
    ListSet ret = InitListSet(ret);
    int list_set1_index = 0;
    int list_set2_index = 0;
    while (list_set1_index < list_set1.size && list_set2_index < list_set2.size) {
        int list_set1_elem = SrchElem(list_set1, list_set1_index);
        int list_set2_elem = SrchElem(list_set2, list_set2_index);
        if (list_set1_elem <= list_set2_elem) {
            if (SrchIndex(list_set2, list_set1_elem) > -1) {
                Ins(ret, ret.size++, list_set1_elem);
            }
            list_set1_index++;
            list_set2_index++;
        }
        else {
            if (SrchIndex(list_set2, list_set2_elem) > -1) {
                Ins(ret, ret.size++, list_set2_elem);
            }
            list_set2_index++;
            list_set1_index++;
        }
    }
    return ret;
}

ListSet DifferenceListSet(ListSet list_set1, ListSet list_set2) {
    ListSet ret = InitListSet(ret);
    int list_set1_index = 0;
    int list_set2_index = 0;
    while (list_set1_index < list_set1.size && list_set2_index < list_set2.size) {
        int list_set1_elem = SrchElem(list_set1, list_set1_index);
        int list_set2_elem = SrchElem(list_set2, list_set2_index);
        if (SrchIndex(list_set2, list_set1_elem) == -1) {
            Ins(ret, ret.size++, list_set1_elem);
        }
        list_set1_index++;
    }
    return ret;
}

ListSet SymmetricDifferenceListSet(ListSet list_set1, ListSet list_set2) {
    ListSet ret = InitListSet(ret);
    ListSet difference1 = DifferenceListSet(list_set1, list_set2);
    ListSet difference2 = DifferenceListSet(list_set2, list_set1);
    ret = UnionListSet(difference1, difference2);
    return ret;
}