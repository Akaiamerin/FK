#include <iostream>
using namespace std;
struct Queue {
    int * elem; //元素
    int front; //队首
    int rear; //队尾
    int cap; //容量
};
//初始化
Queue Init(Queue & que, int cap = 100) {
    que.elem = new int[cap];
    que.front = 0;
    que.rear = 0;
    que.cap = cap;
    return que;
}
//从队头入队
void Enqueue(Queue & que, int enqueue_elem) {
    if ((que.front - 1 + que.cap) % que.cap == que.rear) {
        return;
    }
    que.elem[que.front] = enqueue_elem;
    que.front = (que.front - 1 + que.cap) % que.cap;
}
//从队尾出队
void Dequeue(Queue & que) {
    if (que.rear == que.front) {
        return;
    }
    que.rear = (que.rear - 1 + que.cap) % que.cap;
}
int main() {

    return 0;
}