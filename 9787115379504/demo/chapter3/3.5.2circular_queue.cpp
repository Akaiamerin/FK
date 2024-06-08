#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct CircularQueue {
    int * elem; //元素
    int front; //队首
    int rear; //队尾
    int cap; //容量
};
//初始化
CircularQueue Init(CircularQueue & que, int cap = 100) {
    que.elem = new int[cap];
    que.front = 0;
    que.rear = 0;
    que.cap = cap;
    return que;
}
//遍历
void Traverse(CircularQueue que) {
    for (int i = que.front; i != que.rear; i = (i + 1) % que.cap) {
        cout << que.elem[i] << " ";
    }
    cout << endl;
}
//元素数量
int GetSize(CircularQueue que) {
    return ((que.rear - que.front + que.cap) % que.cap);
}
//是否为空
bool IsEmpty(CircularQueue que) {
    if (que.front == que.rear) {
        return true;
    }
    return false;
}
//入队
void Enqueue(CircularQueue & que, int enqueue_elem) {
    if ((que.rear + 1) % que.cap == que.front) {
        return;
    }
    que.elem[que.rear] = enqueue_elem;
    que.rear = (que.rear + 1) % que.cap;
}
//出队
void Dequeue(CircularQueue & que) {
    if (que.front == que.rear) {
        return;
    }
    que.front = (que.front + 1) % que.cap;
}
//队首元素
int Front(CircularQueue que) {
    return que.elem[que.front];
}
//清空
void Clr(CircularQueue & que) {
    que.front = 0;
    que.rear = 0;
}
//销毁
void Des(CircularQueue & que) {
    if (que.elem != nullptr) {
        delete[] que.elem;
        que.elem = nullptr;
    }
    que.front = 0;
    que.rear = 0;
    que.cap = 0;
}
int main() {
    srand((unsigned)time(NULL));
    CircularQueue que = Init(que, 100);
    for (int i = 0; i < 100; i++) {
        Enqueue(que, rand() % UCHAR_MAX);
    }
    Traverse(que);
    return 0;
}