#include <iostream>
#include <string>
#include <vector>

class Book{
private:
    std::string title;
    std::string author;
    int id;
public:    

Book(std::string t, std::string a, int i){
    title = t;
    author = a;
    id = i;
}    

void set_title(std::string t){
    title = t;
}
void set_author(std::string a){
    author = a;
}
void set_id(int i){
    id = i;
}

std::string get_title()const{
    return title;
}

std::string get_author()const{
    return author;
}

int get_id()const{
    return id;
}

};

class Library{
private:
    std::vector<Book> books;

public:

    void addbook(const Book& book){
        books.push_back(book);
    }

    void listbooks()const{
        for(const auto b:books){
            std::cout<<"ID: "<<b.get_id()<<" "<<"Title: "<<b.get_title()<<std::endl;
        }
        std::cout<<std::endl;
    }

    Book* findBookByTitle(const std::string title){
        for(int i = 0; i < books.size(); ++i){
            if(books[i].get_title() == title){
                return &books[i];
            }
        }
                std::cout<<"Book not found"<<std::endl;
                return nullptr;
        }
};

int main(){

    Book b1("Girq1","Muradyan", 1);
    Book b2("Girq2", "Tumanyan", 2);

    Library lib;
    lib.addbook(b1);
    lib.addbook(b2);

    lib.listbooks();

    Book* found = lib.findBookByTitle("Girq1");
    if(found != nullptr){
       std::cout<<"Author: "<<found->get_author()<<std::endl; 
    }

    return 0;
}   

