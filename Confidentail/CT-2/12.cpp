/**
 * @author ranaaditya aka Aditya Rana 
 */

#include<bits/stdc++.h>
using namespace std;

class Heap {

    int *heap;
    int count = 0;
    int capacity = 0;
    int heap_type = 0; // 0 for MinHeap and 1 for MaxHeap

    public:
    
    Heap(int, int);
    int getParent(int);
    int getLeftChild(int);
    int getRightChild(int);
    int getMaximum();
    int getMinimum();
    void perlocateDown(int);
    int deleteMax();
    int deleteMin();
    void insert(int);
    void resizeHeap(int);
    void deleteHeap();
    void buildHeap(int*); // builds heap from an array
    void printHeap();

};

Heap::Heap(int cap, int type) {

    this->count = 0;
    this->capacity = cap;
    this->heap_type = type;
    this->heap = new int[capacity];

}

int Heap::getParent(int i) {

    if(i <= 0 || i >= count)
    return -1;
    
    return (i-1)/2;

}

int Heap::getLeftChild(int i) {

    int left = 2*i + 1;
    if(left >= count)
    return -1;
    return left;

}

int Heap::getRightChild(int i) {

    int right = 2*i + 2;
    if(right >= count)
    return -1;
    return right;

}

int Heap::getMaximum() {

    if(heap_type == 0)
    return heap[count-1];
    return heap[0];

}

int Heap::getMinimum() {
    if(heap_type == 0)
    return heap[0];
    return heap[count-1];
}

void Heap::perlocateDown(int i) {

    int left, right, max, temp;
    left = getLeftChild(i);
    right = getRightChild(i);
    
    if(left != -1 && heap[left] > heap[i])
    max = left;
    else max = i;
    
    if(right != -1 && heap[right] > heap[i])
    max = right;

    if(max != i) {
        temp = heap[i];
        heap[i] = heap[max];
        heap[max] = temp;
    }

    perlocateDown(max);

}

int Heap::deleteMax() {
    
    int data;
    if(count == 0)
    return -1;

    if(heap_type == 1) {
       data =  heap[0];
       heap[0] = heap[count-1];
       count--;
       perlocateDown(0);
    }

    return data;
}

int Heap::deleteMin() {
    
    int data;
    if(count == 0)
    return -1;
    if(heap_type == 0) {
        data = heap[0];
        heap[0] = heap[count-1];
        count--;
        perlocateDown(0);
    }
    return data;
}


void Heap::resizeHeap(int newcapacity) {

    int old_capacity  =capacity;
    capacity = newcapacity;
    int *old_heap = heap;
    heap = new int[newcapacity];
    for(int i=0;i<old_capacity;i++)
    heap[i] = old_heap[i];

}

void Heap::buildHeap(int *a) {  

    int size = sizeof(a)/sizeof(a[0]);
    if(size >= capacity) {
        capacity = size*2;
    }

    count = size;

    for(int i=0;i<size;i++)
        heap[i] = a[i];
    
    for(int j=(size-1)/2; j >= 0; j--)
        perlocateDown(j);

}

void Heap::deleteHeap() {

    if(heap == NULL)
    return;
    
    delete(heap);
    delete(this);

}

void Heap::insert(int data) {

    int i;
    if(count == capacity) {
        resizeHeap(capacity*2);
    }
    count++;
    i = count-1;
    
    while (i>=0 && data > heap[(i-1)/2])
    {
        heap[i] = heap[(i-1)/2];
        i = (i-1)/2;
    }
    heap[i] = data;

}

void Heap::printHeap() {
        for(int i=0;i<count;i++)
        cout<<heap[i]<<" ";
        cout<<endl;
    }


int main() {

    int heap_list[] = {25,37,48,37,12,92,86,103};
    
    Heap heap = Heap(20,0);

    for(int key: heap_list)
    heap.insert(key);

    heap.printHeap();
    
    return 0;
}