#include <iostream>
using namespace std;
struct Queue {
    int * elem; //元素
    int front; //队首
    int rear; //队尾
    int tag; //标志
    int cap; //容量
};
//初始化
Queue Init(Queue & que, int cap = 100) {
    que.elem = new int[cap];
    que.front = 0;
    que.rear = 0;
    que.tag = 0;
    que.cap = cap;
    return que;
}
//入队
void Enqueue(Queue & que, int enqueue_elem) {
    if ((que.tag == 1) && ((que.rear + 1) % que.cap == que.front)) {
        return;
    }
    que.elem[que.rear] = enqueue_elem;
    que.rear = (que.rear + 1) % que.cap;
    if (que.tag == 0) {
        que.tag = 1;
    }
}
//出队
void Dequeue(Queue & que) {
    if (que.tag == 0) {
        return;
    }
    que.front = (que.front + 1) % que.cap;
    if (que.front == que.rear) {
        que.tag = 0;
    }
}
int main() {

    return 0;
}