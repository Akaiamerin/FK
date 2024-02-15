#include <iostream>
#include "menu.h"
#include "list_set.h"
#include "oper.h"

void Menu() {
    std::cout << "请输入集合的元素个数：";
    int list_set1_size = 0;
    std::cin >> list_set1_size;
    ListSet list_set1 = InitListSet(list_set1, list_set1_size);
    TailCrtListSet(list_set1);
    std::cout << "请输入集合的元素个数：";
    int list_set2_size = 0;
    std::cin >> list_set2_size;
    ListSet list_set2 = InitListSet(list_set1, list_set2_size);
    TailCrtListSet(list_set2);
    while (true) {
        std::cout << "+—————————————+" << std::endl;
        std::cout << "|1. 并集      |" << std::endl;
        std::cout << "|2. 交集      |" << std::endl;
        std::cout << "|3. 差集      |" << std::endl;
        std::cout << "|4. 对称差集  |" << std::endl;
        std::cout << "|5. 退出      |" << std::endl;
        std::cout << "+—————————————+" << std::endl;
        int opt = 0;
        std::cin >> opt;
        if (opt == 1) {
            system("cls");
            OutputListSet(list_set1);
            OutputListSet(list_set2);
            ListSet ret = UnionListSet(list_set1, list_set2);
            OutputListSet(ret);
            system("pause");
            system("cls");
        }
        else if (opt == 2) {
            system("cls");
            OutputListSet(list_set1);
            OutputListSet(list_set2);
            ListSet ret = IntersectionListSet(list_set1, list_set2);
            OutputListSet(ret);
            system("pause");
            system("cls");
        }
        else if (opt == 3) {
            system("cls");
            OutputListSet(list_set1);
            OutputListSet(list_set2);
            ListSet ret = DifferenceListSet(list_set1, list_set2);
            OutputListSet(ret);
            system("pause");
            system("cls");
        }
        else if (opt == 4) {
            system("cls");
            OutputListSet(list_set1);
            OutputListSet(list_set2);
            ListSet ret = SymmetricDifferenceListSet(list_set1, list_set2);
            OutputListSet(ret);
            system("pause");
            system("cls");
        }
        else if (opt == 5) {
            system("cls");
            break;
        }
        else {
            system("cls");
            std::cin.clear();
            std::cin.sync();
        }
    }
}