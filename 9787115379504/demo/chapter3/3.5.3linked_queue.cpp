#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    Node * next; //后继结点
};
struct LinkedQueue {
    Node * front; //队首结点
    Node * rear; //队尾结点
};
//初始化
LinkedQueue Init(LinkedQueue & que) {
    que.front = new Node;
    que.front->elem = NULL;
    que.front->next = nullptr;
    que.rear->elem = NULL;
    que.rear->next = nullptr;
    que.rear = que.front;
    return que;
}
//遍历
void Traverse(LinkedQueue que) {
    for (Node * i = que.front->next; i != que.rear; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//元素数量
int GetSize(LinkedQueue que) {
    int size = 0;
    for (Node * i = que.front; i != que.rear; i = i->next) {
        size++;
    }
    return size;
}
//是否为空
bool IsEmpty(LinkedQueue que) {
    if (que.front == que.rear) {
        return true;
    }
    return false;
}
//入队
void Enqueue(LinkedQueue & que, int enqueue_elem) {
    Node * enqueue_node = new Node;
    enqueue_node->elem = enqueue_elem;
    enqueue_node->next = nullptr;
    que.rear->next = enqueue_node;
    que.rear = enqueue_node;
}
//出队
void Dequeue(LinkedQueue & que) {
    if (que.front == que.rear) {
        return;
    }
    Node * dequeue_node = que.front->next;
    que.front->next = dequeue_node->next;
    if (que.rear == dequeue_node) {
        que.rear = que.front;
    }
    delete dequeue_node;
    dequeue_node = nullptr;
}
//队首元素
int Front(LinkedQueue que) {
    return que.front->next->elem;
}
//清空
void Clr(LinkedQueue & que) {
    Node * clr_node = nullptr;
    Node * next_clr_node = que.front->next;
    que.rear = que.front;
    que.front->next = nullptr;
    while (next_clr_node != nullptr) {
        clr_node = next_clr_node;
        next_clr_node = next_clr_node->next;
        delete clr_node;
        clr_node = nullptr;
    }
}
//销毁
void Des(LinkedQueue & que) {
    while (que.front != nullptr) {
        que.rear = que.front->next;
        delete que.front;
        que.front = nullptr;
        que.front = que.rear;
    }
}
int main() {
    srand((unsigned)time(NULL));
    LinkedQueue que = Init(que);
    for (int i = 0; i < 100; i++) {
        Enqueue(que, rand() % UCHAR_MAX);
    }
    Traverse(que);
    return 0;
}