#include <iostream>
#include <cstring>

class String{
private:
    int m_size;
    char *m_ptr;
public:
    String():m_size(0), m_ptr(nullptr){}
    String(const char *ptr): m_size(strlen(ptr)), m_ptr(new char[m_size + 1]){
        for(int i = 0; i< m_size; ++i){
            m_ptr[i] = ptr[i];
        }
        m_ptr[m_size] = '\0';
    }
     String(char *ptr): m_size(strlen(ptr)), m_ptr(new char[m_size + 1]){
        for(int i = 0; i< m_size; ++i){
            m_ptr[i] = ptr[i];
        }
        m_ptr[m_size] = '\0';
    }
    ~String(){ delete[] m_ptr; }
    String(const String& other): m_size(other.m_size), m_ptr(new char[other.m_size + 1]){
        for(int i = 0; i < m_size; ++i){
            m_ptr[i] = other.m_ptr[i];
        }
        m_ptr[m_size] = '\0';
    }
    String(String && other):m_size(other.m_size), m_ptr(other.m_ptr){
        other.m_size = 0;
        other.m_ptr = nullptr;
    }

    String &operator=(const String& other){
        if(this == &other)return *this;
        delete[] m_ptr;
        m_size = other.m_size;
        m_ptr = new char[m_size + 1];
        for(int i = 0; i < m_size; ++i){
            m_ptr[i] = other.m_ptr[i];
        }
        m_ptr[m_size] = '\0';
        return *this;
    }
    String &operator=(String&& other){
        if(this == &other){return *this;}
        delete[]m_ptr;
        m_size = other.m_size;
        m_ptr = other.m_ptr;
        other.m_size = 0;
        other.m_ptr = nullptr;
        return *this; 
    }  
     const char* c_str() const { return m_ptr; }
    
};
    int main(){
    String s("Hello");
    String s1(s);
    std::cout << s1.c_str() << std::endl;

    String s2(s1);
    std::cout << s2.c_str() << std::endl;

    String s3 = s1;
    std::cout << s3.c_str() << std::endl;

    String s4(std::move(s1));
    std::cout << s4.c_str() << std::endl;

    String s5;
    std::cout << (s5.c_str() ? s5.c_str() : "nullptr") << std::endl;

    s5 = s2;
    std::cout << s5.c_str() << std::endl;

    String s6;
    std::cout << (s6.c_str() ? s6.c_str() : "nullptr") << std::endl;

    s6 = std::move(s3);
    std::cout << s6.c_str() << std::endl;
        return 0;
    }



