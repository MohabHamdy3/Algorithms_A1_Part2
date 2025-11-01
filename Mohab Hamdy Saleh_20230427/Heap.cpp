#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMaxHeap;
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    Heap(bool isMaxHeap = true) {
        this->isMaxHeap = isMaxHeap;
    }
    void insert(int val) {
        heap.push_back(val);
        int index = heap.size() - 1;
        while (index != 0) {
            int parent = (index - 1) / 2;
            if ((isMaxHeap && heap[parent] <= heap[index]) || (!isMaxHeap && heap[parent] >= heap[index])) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapify(int index) {
        int size = heap.size();
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int extreme = index;

        if (left < size && ((isMaxHeap && heap[left] >= heap[extreme]) || (!isMaxHeap && heap[left] <= heap[extreme]))) { 
            extreme = left;
        }
        if (right < size && ((isMaxHeap && heap[right] >= heap[extreme]) || (!isMaxHeap && heap[right] <= heap[extreme]))) {
            extreme = right;
        }
        if (extreme != index) {
            swap(heap[index], heap[extreme]);
            heapify(extreme);
        }
    }
    
    void buildHeap() {
        int startIdx = (heap.size() / 2) - 1;
        for (int i = startIdx; i >= 0; i--) {
            heapify(i);
        }
    }
    // extract extreme (max or min based on heap type)
    int extractExtreme() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int extreme = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapify(0);
        }
        return extreme;
    }
    int size() const {
        return heap.size();
    }
    bool isEmpty() const {
        return heap.empty();
    }
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }


};

// Priority Queue with Heap implementation
struct PriorityQueueNode {
    int value;
    int priority;
    PriorityQueueNode(int v, int p) : value(v), priority(p) {}
};
class PriorityQueue {
private:
    vector<PriorityQueueNode> nodes;
    bool isMaxHeap;
public:
    PriorityQueue(bool isMaxHeap = true) {
        this->isMaxHeap = isMaxHeap;
    }
    void enqueue(int value, int priority) {
        nodes.push_back(PriorityQueueNode(value, priority));
        int index = nodes.size() - 1;
        while (index != 0) {
            int parent = (index - 1) / 2;
            if ((isMaxHeap && nodes[parent].priority <= nodes[index].priority) || (!isMaxHeap && nodes[parent].priority >= nodes[index].priority)) {
                swap(nodes[parent], nodes[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapify(int index) {
        int size = nodes.size();
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int extreme = index;

        if (left < size && ((isMaxHeap && nodes[left].priority >= nodes[extreme].priority) || (!isMaxHeap && nodes[left].priority <= nodes[extreme].priority))) { 
            extreme = left;
        }
        if (right < size && ((isMaxHeap && nodes[right].priority >= nodes[extreme].priority) || (!isMaxHeap && nodes[right].priority <= nodes[extreme].priority))) {
            extreme = right;
        }
        if (extreme != index) {
            swap(nodes[index], nodes[extreme]);
            heapify(extreme);
        }
    }
    void buildHeap() {
        int startIdx = (nodes.size() / 2) - 1;
        for (int i = startIdx; i >= 0; i--) {
            heapify(i);
        }
    }
    // get extreme (highest or lowest priority based on queue type)
    int peekExtreme() {
        if (nodes.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return nodes[0].value;
    }
    void printQueue() {

        for (const auto& node : nodes) {
            cout << "(" << node.value << ", " << node.priority << ") ";
        }
        cout << endl;
    }
    // extract extreme (highest or lowest priority based on queue type)
    void dequeue() {
        if (nodes.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        nodes[0] = nodes.back();
        nodes.pop_back();
        heapify(0);
    }
  
};

void heapSort(vector<int>& arr) {
    Heap maxHeap(true);
    for (int val : arr) {
        maxHeap.insert(val);
    }
    arr.clear();
    while (!maxHeap.isEmpty()) {
        arr.push_back(maxHeap.extractExtreme());
    }
}

int main() {
    Heap maxHeap(true);
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    cout << "Max Heap: ";
    maxHeap.printHeap();

    cout << "Extracted Max: " << maxHeap.extractExtreme() << endl;
    cout << "Heap after extraction: ";
    maxHeap.printHeap();

    Heap minHeap(false);
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);
    cout << "Min Heap: ";
    minHeap.printHeap();

    cout << "Extracted Min: " << minHeap.extractExtreme() << endl;
    cout << "Heap after extraction: ";
    minHeap.printHeap();

    PriorityQueue pq(true); // Max Priority Queue
    pq.enqueue(1, 5);
    pq.enqueue(2, 3);
    pq.enqueue(0, 8);
    cout << "Priority Queue: ";
    pq.printQueue();
    cout << "Peek Extreme: " << pq.peekExtreme() << endl;
    pq.dequeue();
    cout << "Priority Queue after dequeue: ";
    pq.printQueue();



    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    heapSort(arr);
    cout << "Sorted array using Heap Sort: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}