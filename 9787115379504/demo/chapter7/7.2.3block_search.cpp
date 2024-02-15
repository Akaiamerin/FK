#include <iostream>
using namespace std;
struct IndexTable {
    int block_max_elem; //子块最大值
    int block_max_elem_index; //子块最大值的下标
};
//数组例
void ExampleArr(int arr[], int size, IndexTable index_table[], int index_table_size) {
    int example_arr[] = {22, 12, 13, 8, 9, 20, 33, 42, 44, 38, 24, 48, 60, 58, 74, 49, 86, 53};
    for (int i = 0; i < size; i++) {
        arr[i] = example_arr[i];
    }
    IndexTable example_index_table[index_table_size];
    example_index_table[0].block_max_elem = 22;
    example_index_table[0].block_max_elem_index = 0;
    example_index_table[1].block_max_elem = 48;
    example_index_table[1].block_max_elem_index = 6;
    example_index_table[2].block_max_elem = 86;
    example_index_table[2].block_max_elem_index = 12;
    for (int i = 0; i < index_table_size; i++) {
        index_table[i] = example_index_table[i];
    }
}
//遍历
void Traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//分块查找
int BlockSearch(int arr[], int size, IndexTable index_table[], int index_table_size, int srch_elem) {
    int begin_srch_index = -1;
    //顺序查找索引表确定开始查找下标的范围
    for (int i = 0; i < index_table_size; i++) {
        if (index_table[i].block_max_elem >= srch_elem) {
            begin_srch_index = index_table[i].block_max_elem_index;
            break;
        }
    }
    if (begin_srch_index == -1) {
        return -1;
    }
    for (int i = begin_srch_index; i < size; i++) {
        if (arr[i] == srch_elem) {
            return i;
        }
    }
    return -1;
}
int main() {
    int size = 18;
    int arr[size];
    int index_table_size = 3;
    IndexTable index_table[index_table_size];
    ExampleArr(arr, size, index_table, index_table_size);
    Traverse(arr, size);
    int srch_elem = 0;
    cin >> srch_elem;
    cout << BlockSearch(arr, size, index_table, index_table_size, srch_elem) << endl;
    return 0;
}