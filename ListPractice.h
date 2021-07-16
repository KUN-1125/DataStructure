#include"c.h"

#define InitSize 10
// 定义一个顺序表(静态)
typedef struct 
{
    int data[InitSize];
    int length = 0;
    int MaxSize = InitSize;
}SqList;

// 在L的第i个位置(位序)插入元素e
bool InsertSqList(SqList &L, int i, int e){
    if(i < 1 || i > L.length + 1)
        return false;
    if(L.length >= InitSize)
        return false;
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除表L中最小元素(假设唯一)并返回，空出的位置由最后一个元素填补，若L为空，显示出错信息并退出运行
int DeletMin(SqList &L, int &m){
    if(L.length == 0)
        return 0;
    int l, h;
    l = 0;
    h = L.length - 1;
    while (l != h)
    {
        if(L.data[l] < L.data[h]){
            h--;
        }
        l++;
    }
    m = L.data[l];
    L.data[l] = L.data[L.length-1];
    L.length -= 1;
    return 0;
}

// 将L中的元素逆置，空间复杂度O(1)
bool Reverse(SqList &L){
    if(L.length == 0)
        return false;
    int temp;
    int l,h;
    l = 0;
    h = L.length - 1;
    while (l < h)
    {
        if(L.data[l] != L.data[h]){
            temp = L.data[l];
            L.data[l] = L.data[h];
            L.data[h] = temp;
            l++;
            h--;
        }
    }
    return true;
}

// 删除L中所有值为x的数据元素，时间复杂度O(n)，空间复杂度O(1)
bool Del_x_L(SqList &L, int x){
    if(L.length == 0)
        return false;
    int i,k = 0; // k用来记录不等于x的元素的个数
    for(i = 0; i < L.length; i++){
        if(L.data[i] != x){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

// 删除L中在给定值s~t(s<t)之间的所有元素，若s或t不合理或顺序表为空，显示出错信息并停止运行
bool Del_st_L(SqList &L, int s, int t){
    if(s > t || L.length == 0)
        return false;
    int k = 0;
    for(int i = 0; i < L.length; i++){
        if(L.data[i] <= s || L.data[i] >= t){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

// 删除L中值重复的元素，使每个值只出现一次
bool Del_Same(SqList &L){
    if(L.length == 0)
        return false;
    int i=0;
    for(; i < L.length; i++){
        for(int j = i + 1; j < L.length; j++){
            if(L.data[i] == L.data[j]){
                for(int k = j; k < L.length; k++){
                    L.data[k] = L.data[k + 1];
                    L.length--;
                }
            }
        }
        
    }
    // 时间复杂度太大了T_T
    return true;
}

// 将两个有序的表L1，L2合并为一个新的有序表L并由函数返回
bool Merge(SqList L1, SqList L2, SqList &L){
    if(L1.length + L2.length > L.MaxSize)
        return false;
    int i1 = 0, i2 = 0, i = 0;
    while(i1 < L1.length && i2 < L2.length){
        if(L1.data[i1] <= L2.data[i2]){
            L.data[i] = L1.data[i1];
            i1++;
            i++;
        }
        L.data[i] = L2.data[i2];
        i2++;
        i++;
    }
    while(i1 < L1.length){
        L.data[i] = L1.data[i1];
        i1++;
        i++;
    }
    while(i2 < L2.length){
        L.data[i] = L2.data[i2];
        i2++;
        i++;
    }
    L.length = i;
    return true;
}