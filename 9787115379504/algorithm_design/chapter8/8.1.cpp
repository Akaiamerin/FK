#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    Node * next; //后继结点
};
//初始化
Node * Init(Node *& list) {
    list = new Node;
    list->elem = NULL;
    list->next = nullptr;
    return list;
}
//创建（头插法）
void HeadCrt(Node *& list, int size) {
    for (int i = 0; i < size; i++) {
        Node * crt_node = new Node;
        // cin >> crt_node->elem;
        crt_node->elem = rand() % UCHAR_MAX;
        crt_node->next = list->next;
        list->next = crt_node;
    }
}
//遍历
void Traverse(Node * list) {
    for (Node * i = list->next; i != nullptr; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//单链表的选择排序
void SelectionSort(Node *& list) {
    for (Node * i = list->next; i != nullptr; i = i->next) {
        Node * min_node = i;
        for (Node * j = i; j->next != nullptr; j = j->next) {
            if (j->next->elem < min_node->elem) {
                min_node = j->next;
            }
        }
        if (i->elem != min_node->elem) {
            int temp = i->elem;
            i->elem = min_node->elem;
            min_node->elem = temp;
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    Node * list = Init(list);
    HeadCrt(list, 100);
    Traverse(list);
    SelectionSort(list);
    Traverse(list);
    return 0;
}