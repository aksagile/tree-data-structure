#include <iostream>
#include <vector>
using namespace std;

void swap(int* a,int* b){
    int temp =*a;
    *a=*b;*b=temp;
}
class heap{
    vector<int> v;
    int sze;
    int parent(int i){
        return (i)/2;
    }
     int left(int i){
        return 2*i;
    }
     int right(int i){
        return 2*i+1;
    }
    void heapify(int idx){
        if (idx <= 0 || idx >= sze) return;
        int largest = idx;
        if(left(idx) <= sze&&v[left(idx)]>v[largest]){
            largest = left(idx);
        }
        if(right(idx) <= sze&&v[right(idx)]>v[largest]){
            largest = right(idx);
        }
        if(largest!=idx){
            swap(&v[idx],&v[largest]);
            heapify(largest);
        }
    }
    public:
    //constructor
    heap(){
       v.push_back(-1);
       
       sze  =0;
    }
    int size(){
        return sze;
    }
    bool empty(){
        return (sze==0);
    }
    void push(int x){
        v.push_back(x);
        sze++;
        
        //heapify
        int idx = sze;
        while(idx>1&&v[idx]>v[parent(idx)]){
            swap(&v[idx],&v[parent(idx)]);
            idx = parent(idx);
        }
    }
    int top(){
        if (!empty()) return v[1];
		return -1;
    }
    
    void pop(){
        if(empty()) return;
        swap(&v[1],&v[sze]);
        sze--;
        heapify(1);
    }
};
int main() {
    heap H;
	H.push(100);
	H.push(-2);
	H.push(200);
	H.push(10);
	H.push(17);

	while(H.empty() == false){
		cout << H.top() << " ";
		H.pop();
	}
	
	
}
