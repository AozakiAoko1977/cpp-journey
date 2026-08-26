#include <iostream>
using namespace std;

class MyVector {
public:
    // 构造与析构
    MyVector() : data_(nullptr),size_(0),capacity_(0){}                          // 默认构造：空数组
    explicit MyVector(size_t size) : size_(size),capacity_(size){
        data_ = new int [size];
        for(int i = 0; i < size; i++){
            data_[i] = 0;
        }
    }      // 指定大小构造：建一个 size 个 0 的数组
    ~MyVector(){
        delete[] data_;
    }                   // 析构：delete[] 掉分配的内存

    // 核心操作
    void push_back(int value);           // 末尾加元素，满了自动扩容（翻倍）
    void pop_back(){
        if(size_ > 0) size_ --;
    }                    // 删除末尾元素
    int& operator[](size_t index){
        return data_[index];
    }       // 用 v[3] 的方式访问
    size_t size() const{
        return size_;
    }                 // 有多少个元素
    size_t capacity() const{
        return capacity_;
    }             // 分配了多少空间（>= size）
    bool empty() const{
        return size_ == 0;
    }                  // 是不是空的
    void clear(){
        size_ = 0;
    }                        // 清空所有元素

private:
    int* data_;        // 指向存放元素的数组
    size_t size_;      // 现有元素个数
    size_t capacity_;  // 已分配的空间大小

    void reallocate(size_t new_cap);     // 扩容内部函数
};
void MyVector::reallocate(size_t new_cap){
    int* newData = new int [new_cap];
    for(int i = 0 ; i < size_; i++ ){
        newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = new_cap;
}
void MyVector::push_back(int value) {
    if (size_ == capacity_) {
        size_t newCap = (capacity_ == 0) ? 1 : capacity_ * 2;   // 0→1，其余翻倍
        reallocate(newCap);
    }
    data_[size_] = value;
    size_++;
}

int main() {
    MyVector v;

    // 连续 push 10 个元素，观察 size 和 capacity 怎么变
    for (int i = 1; i <= 10; i++) {
        v.push_back(i * 10);
        cout << "push " << i * 10
             << "  size=" << v.size()
             << "  capacity=" << v.capacity() << endl;
    }

    // 遍历
    cout << "内容: ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // pop_back / empty / clear
    v.pop_back();
    cout << "pop 后 size=" << v.size()
         << " back=" << v[v.size() - 1] << endl;

    v.clear();
    cout << "clear 后 size=" << v.size()
         << " empty=" << (v.empty() ? "是" : "否")
         << " capacity=" << v.capacity() << "（内存没释放）" << endl;

    // 指定大小构造
    MyVector v2(5);
    cout << "v2: size=" << v2.size()
         << " v2[3]=" << v2[3] << endl;

    return 0;
}