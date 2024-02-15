#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    Node * next; //后继结点
};
struct HashTable {
    Node * list;
    int cap;
};
//初始化
HashTable Init(HashTable & hash_table, int cap = 100) {
    hash_table.list = new Node[cap];
    for (int i = 0; i < cap; i++) {
        hash_table.list[i].elem = NULL;
        hash_table.list[i].next = nullptr;
    }
    hash_table.cap = cap;
    return hash_table;
}
//遍历
void Traverse(HashTable hash_table) {
    for (int i = 0; i < hash_table.cap; i++) {
        if (hash_table.list[i].next == nullptr) {
            continue;
        }
        for (Node * j = hash_table.list[i].next; j != nullptr; j = j->next) {
            cout << j->elem << " ";
        }
        cout << endl;
    }
}
//哈希函数
int HashFun(HashTable hash_table, int elem) {
    return elem % hash_table.cap;
}
//插入
void Ins(HashTable hash_table, int ins_elem) {
    int hash_table_index = HashFun(hash_table, ins_elem);
    Node * prev_node = &hash_table.list[hash_table_index];
    while (prev_node->next != nullptr) {
        prev_node = prev_node->next;
    }
    Node * ins_node = new Node;
    ins_node->elem = ins_elem;
    ins_node->next = prev_node->next;
    prev_node->next = ins_node;
}
//删除
void Del(HashTable hash_table, int del_elem) {
    int hash_table_index = HashFun(hash_table, del_elem);
    Node * cur_node = &hash_table.list[hash_table_index];
    while (cur_node->next != nullptr) {
        if (cur_node->next->elem == del_elem) {
            break;
        }
        cur_node = cur_node->next;
    }
    Node * del_node = cur_node->next;
    cur_node->next = del_node->next;
    delete del_node;
    del_node = nullptr;
}
int main() {
    srand((unsigned)time(NULL));
    HashTable hash_table = Init(hash_table, 100);
    for (int i = 0; i < 100; i++) {
        Ins(hash_table, rand() % UCHAR_MAX);
    }
    Traverse(hash_table);
    return 0;
}