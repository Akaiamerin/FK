#include <iostream>
using namespace std;
struct Node {
    int elem; //元素
    Node * next; //后继结点
};
struct Queue {
    Node * rear; //队尾结点
};
//初始化
Queue Init(Queue & que) {
    que.rear = new Node;
    que.rear->elem = NULL;
    que.rear->next = que.rear;
    return que;
}
//清空
void Clr(Queue & que) {
    que.rear = que.rear->next;
    while (que.rear != que.rear->next) {
        Node * clr_node = que.rear->next;
        que.rear->next = clr_node->next;
        delete clr_node;
        clr_node = nullptr;
    }
}
//是否为空
bool IsEmpty(Queue que) {
    if (que.rear->next->next == que.rear->next) {
        return true;
    }
    return false;
}
//入队
void Enqueue(Queue & que, int enqueue_elem) {
    Node * enqueue_node = new Node;
    enqueue_node->elem = enqueue_elem;
    enqueue_node->next = que.rear->next;
    que.rear->next = enqueue_node;
    que.rear = enqueue_node;
}
//出队
void Dequeue(Queue & que) {
    if (que.rear->next->next == que.rear->next) {
        return;
    }
    Node * dequeue_node = que.rear->next->next;
    if (que.rear == dequeue_node) {
        que.rear = que.rear->next;
        que.rear->next = dequeue_node->next;
    }
    else {
        que.rear->next->next = dequeue_node->next;
    }
    delete dequeue_node;
    dequeue_node = nullptr;
}
int main() {

    return 0;
}