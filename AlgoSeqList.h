#include"c.h"

// 定义一个顺序表(动态分配)
#define InitSize 10
typedef struct{
    int * data;
    int MaxSize,length;
}SeqList;

// 初始化顺序表
bool InitSeqList(SeqList &L){
    L.data = (int *)malloc(InitSize * (sizeof(int)));
    if(!L.data)
        return false;
    L.length = 0;
    L.MaxSize = InitSize;
    return true;
}

// 增加动态数组的长度
bool IncreaseSize(SeqList &L, int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * (sizeof(int)));
    if(!L.data)
        return false;
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
    return true;
}

// 在L的第i个位置(位序)插入元素e
bool InsertSeqList(SeqList &L, int i, int e){
    if(i < 1 || i > L.length + 1)
        return false;
    if(L.length >= L.MaxSize)
        // return false;
        IncreaseSize(L, 10);
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 在L的第i个位置(位序)删除元素赋值给e并返回
bool DeleteSeqList(SeqList &L, int i, int &e){
    if(i < 1 || i > L.length)
        return false;
    if(L.length == 0)
        return false;
    e = L.data[i - 1];
    for(int j = i; j < L.length; j++){
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

// 将L的第i位置(位序)的元素值改为e,并用e返回之前的值
bool ChangeSeqList(SeqList &L, int i, int &e){
    if(i < 1 || i > L.length)
        return false;
    if(L.length == 0)
        return false;
    int temp;
    temp = L.data[i - 1];
    L.data[i - 1] = e;
    e = temp;
    return true;
}

// 按位查找：找出L的第i位置(位序)的元素并用e返回
bool BitSearch(SeqList L, int i, int &e){
    if(i < 1 || i > L.length)
        return false;
    if(L.length == 0)
        return false;
    e = L.data[i - 1];
    return true;
}

// 按值查找：找出L中值和e相等的元素的位置，并返回给i(简单版：L中只有一个值与e相同)
bool ValueSearch(SeqList L, int &i, int e){
    if(L.length == 0)
        return false;
    for(i = 1; i < L.length + 1; i++){
        if(L.data[i - 1] == e)
            return true;
    }
    return true;
}

// 按值查找：找出L中值和e相等的元素的位置，并返回给顺序表L1(复杂版：L中有多个值与e相同)
bool VSearch(SeqList L, SeqList &L1, int e){
    if(L.length == 0)
        return false;    
    int i = 1;
    for(; i < L.length + 1; i++){
        if(L.data[i - 1] == e){
            L1.data[L1.length] = i;
            L1.length++;
        }
    }
    return true;
}
