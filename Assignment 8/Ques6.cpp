#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> h;

    int parent(int i) { 
        return (i - 1) / 2; 
    }
    int left(int i) { 
        return 2*i + 1; 
    }
    int right(int i) { 
        return 2*i + 2; 
    }

    public:
        void insertKey(int k) {
            h.push_back(k);
            int i = h.size() - 1;
            while (i > 0 && h[parent(i)] < h[i]) {
                swap(h[i], h[parent(i)]);
                i = parent(i);
            }
        }
        int getMax() {
            if (h.empty()) 
                return -1;
            
            return h[0];
        }
        void heapify(int i) {
            int n = h.size();
            
            int largest = i;
            
            int l = left(i);
            int r = right(i);
            
            if (l < n && h[l] > h[largest]) 
                largest = l;
            
            if (r < n && h[r] > h[largest]) 
                largest = r;
            
            if (largest != i) {
                swap(h[i], h[largest]);
                heapify(largest);
            }
        }
        int extractMax() {
            if (h.empty()) 
                return -1;
            
            int root = h[0];
            
            h[0] = h.back();
            h.pop_back();
            
            heapify(0);
            
            return root;
        }
};

int main() {
    MaxHeap pq;
    
    pq.insertKey(30);
    pq.insertKey(10);
    pq.insertKey(50);
    pq.insertKey(40);

    return 0;
}

