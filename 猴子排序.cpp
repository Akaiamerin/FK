#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;
void random_arr(int arr[], int n, int min, int max) //随机数组
{
    srand((unsigned)time(NULL)); //随机数种子
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min; //随机生成元素的范围[min, max]
    }
}
void swap(int &num1, int &num2) //交换
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
void output_arr(int arr[], int n) //输出数组
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool is_sort(int arr[], int n) //判断是否有序
{
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}
void bogo_sort(int arr[], int n) //猴子排序
{
    int count = 1; //记录排序次数
    srand((unsigned)time(NULL)); //随机数种子
    for(; is_sort(arr, n) != true;)
    {
        for(int i = 0; i < n; i++)
        {
            int random_index = rand() % n; //随机生成[0, n - 1]的整数（即不超过最大下标n）
            swap(arr[i], arr[random_index]);
        }
        printf("第%d次排序：", count);
        count++;
        output_arr(arr, n);
        //Sleep(1000); //间隔时间
    }
}
int main()
{
    int n;
    cout << "请输入数组长度：";
    cin >> n;
    int * arr;
    arr = new int[n];
    int min, max;
    cout << "请输入元素的取值范围：";
    cin >> min >> max;
    random_arr(arr, n, min, max);
    cout << "数组初始值为：";
    output_arr(arr, n);
    bogo_sort(arr, n);
    delete arr;
    return 0;
}