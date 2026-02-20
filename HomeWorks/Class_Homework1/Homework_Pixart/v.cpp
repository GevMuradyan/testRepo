#include <iostream>
#include <algoritm>

class My_vector{
    private:
    size_t size;
    size_t capacity;
    int* ptr;
    public:
    My_vector() : size{0}, capacity{0}, ptr{nullptr} {};
    My_vector(size_t size_m) : My_vector(size_m, 0) {}
    My_vector(size_t size_m, int val){
        size = size_m;
        capacity = size_m;
        ptr = new int[size_m];
        for(int i = 0;i < size_m;++i){
            ptr[i] = val;
        }
    }
    My_vector(const My_vector& other){
        this->size = other.size;
        this->capacity = other.capacity;
        this->ptr = new int[other.size];
        for(int i = 0; i < this->size;++i){
            this->ptr[i] = other.ptr[i];
        }
    }
    My_vector(std::initializer_list<int> il) : size{il.size()}, capacity{size} {
        ptr = new int[size];
        int j = 0;
        for(auto i : il){
            this->ptr[j] = i;
            ++j;
        }
    }

    My_vector& operator=(const My_vector& other){
        if(this->ptr != other.ptr){
            this->size = other.size;
            this->capacity = other.capacity;
            if (ptr) delete[] ptr;
            this->ptr = new int[other.size];
            for(int i = 0; i < this->size;++i){
                this->ptr[i] = other.ptr[i];
            }
        }
    return *this;
    }
    size_t getSize() const {
        return size;
    }
    int &operator[](size_t index){
        if(index >= size){
            std::cout << "Out of size:";
            return 0;
        }
        return ptr[index];
    }
    const int &operator[](size_t index) const{
        if(index >= size){
            std::cout << "Out of size:";
            return 0;
        }
        return ptr[index];
    }
    
    int& front(){
        return ptr[0];
    }
    const int &front()const{
        return ptr[0];
    }
    int& end(){
        return ptr[size-1];
    }
    const int &end()const{
        return ptr[size-1];
    }
    bool empty()const {
        return size == 0;
    }
    void reserve(size_t new_capacity){
        if(new_capacity <= capacity)return;
        int* ptr1 = new int[new_capacity];
        for(int i = 0;i < size;++i){
            ptr1[i] = ptr[i];
        }
        capacity = new_capacity;
        delete[] ptr;
        ptr = ptr1;
    }
    size_t getCapacity()const{
        return capacity;
    }
    void shrinctofit(){
        if(size == 0)delete[] ptr;
        if(size == capacity)return;
        int* ptr1 = new int[size];
        for(int i = 0;i < size;++i){
            ptr1[i] = ptr[i];
        }
        capacity = size;
        delete[] ptr;
        ptr = ptr1;
    }
    void clear(){
        int* ptr1 = new int[0];
        size = capacity = 0;
        delete[] ptr;
        ptr = ptr1;
    }
    
    bool operator==(const My_vector& rhs)const{
        if(this->size != rhs->size){
            return false;
        }

        for(int i = 0; i < this->size; ++i){
            if(this->ptr[i] != rhs.ptr[i]){
                return false;
            }
            return true;
        }
    }
    bool operator <(const My_vector &rhs)const{
        int min = std::min(this->size, rhs.size);

        for(int i = 0; i < min; ++i){
            if(this->ptr[i] < rhs.ptr[i]){
                return true;
            }
            if(this->ptr[i] > rhs.ptr[i]){
                return false;
            }
        }
        return rhs.size > this->size;
    }
    ~My_vector() {
        delete[] ptr;
    }
};


int main(){
    My_vector v1{1,2,3,4,5};
    My_vector v2(v1);
    for(int i = 0; i < v2.getSize();++i){
        std::cout << v2[i]<< " ";
    }
    v1.reserve(7);
    v1.shrinctofit();
    std::cout <<"Test    "<< v1.getCapacity() << std::endl;
return 0;
}