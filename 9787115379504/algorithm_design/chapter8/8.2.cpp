#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    Node * prev; // 前驱结点
    Node * next; // 后继结点
};
//初始化
Node * Init(Node *& list) {
    list = new Node;
    list->elem = NULL;
    list->prev = nullptr;
    list->next = nullptr;
    return list;
}
//创建
void Crt(Node *& list, int n) {
    Node * tail = list;
    for (int i = 0; i < n; i++) {
        Node * crt_node = new Node;
        // cin >> crt_node->elem;
        crt_node->elem = rand() % UCHAR_MAX;
        crt_node->prev = tail;
        crt_node->next = tail->next;
        tail->next = crt_node;
        tail = crt_node;
    }
}
//遍历
void Traverse(Node * list) {
    for (Node * i = list->next; i != nullptr; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//双向冒泡排序
void DoubleBubbleSort(Node *& list) {
    bool swap_flag = true;
    Node * head = list; //双向链表表头，向下起泡的开始结点
    Node * tail = nullptr; //双向链表表尾，向上起泡的开始结点
    while (swap_flag == true) {
        Node * cur_node = head->next;
        swap_flag = false;
        //向下起泡
        while (cur_node->next != tail) {
            if (cur_node->elem > cur_node->next->elem) {
                swap_flag = true;
                Node * temp_node = cur_node->next;
                cur_node->next = temp_node->next;
                if (temp_node->next != nullptr) {
                    temp_node->next->prev = cur_node;
                }
                cur_node->prev->next = temp_node;
                temp_node->prev = cur_node->prev;
                cur_node->prev = temp_node;
                temp_node->next = cur_node;
            }
            else {
                cur_node = cur_node->next; //指向下一结点
            }
        }
        tail = cur_node; //准备向上起泡
        cur_node = tail->prev;
        //向上起泡
        while (swap_flag == true && cur_node->prev != head) {
            if (cur_node->elem < cur_node->prev->elem) {
                Node * temp_node = cur_node->prev;
                cur_node->prev = temp_node->prev;
                if (temp_node->prev != nullptr) {
                    temp_node->prev->next = cur_node;
                }
                cur_node->next->prev = temp_node;
                temp_node->next = cur_node->next;
                cur_node->next = temp_node;
                temp_node->prev = cur_node;
            }
            else {
                cur_node = cur_node->prev;
            }
        }
        head = cur_node; //为下一次向下起泡作准备
    }
}
int main() {
    srand((unsigned)time(NULL));
    Node * list = Init(list);
    Crt(list, 100);
    Traverse(list);
    DoubleBubbleSort(list);
    Traverse(list);
    return 0;
}