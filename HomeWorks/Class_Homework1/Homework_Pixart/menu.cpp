#include <iostream>
#include <vector>
#include <string>

class Dish{
protected:
    std::string name;
    double price;

public:
    Dish(std::string n, double p){
        name = n;
        price = p;
    }
    virtual ~Dish(){}


    void seter_name(std::string n){
        name = n;
    }
    void seter_price(double p){
        price = p;
    }

    std::string get_name(){
        return name;
    }
    double get_price(){
        return price;
    }

    virtual void display(){
        std::cout<<name<<" - "<<price<<"$";
    }

};

class Appetizer: public Dish{
private:
    bool isSpicy;
public:
    Appetizer(std::string n, double p, bool spicy):Dish(n,p){
        isSpicy = spicy;
    }

    void display() override{
        Dish::display();
        std::cout<<(isSpicy ?  "(Spicy)" : "(Not Spicy)"); 
    }
};

class Entree :public Dish{
private:
int calories;
public:
    Entree(std::string n, double d, int cal):Dish(n,d){
        calories = cal;
    }
    void display()override{
        std::cout<<name<<" - "<<price<<"$"<<"("<<calories<<")";
    }
};

class Menu{
private:
    std::vector<Dish*> dishes;
 public:

    ~Menu(){
        for(auto x: dishes){
            delete x;
        }
        dishes.clear();
    }
    void addDishes(Dish* dish){
        dishes.push_back(dish);
    }   
    void displayManu()const{
        std::cout<<"============================="<<std::endl;
        for(auto i: dishes){
            i->display();
            std::cout<<std::endl;   
        }
        std::cout<<std::endl;
    }
    Dish* getDish(int index){
        if(index >=0 && index <= dishes.size()){
            return dishes[index];
        }
        return nullptr;
    }
};

class Order{
private:
    std::vector<Dish*> orderDishes;
    double totalorder = 0.0;
public:
    void addDish(Dish* dish){
        if(dish != nullptr){
            orderDishes.push_back(dish);
        }
    }
    void calculateTotatl(){
        totalorder = 0;
        for(auto x : orderDishes){
            totalorder+= x->get_price();
        }
    }
    void displayorder()const{
        std::cout<<"============================="<<std::endl;
        for(auto dish: orderDishes){
            dish->display();
            std::cout<<std::endl;
        }
        std::cout<<"_________________________"<<std::endl;
        std::cout<<"Total price : "<<totalorder<<std::endl;
        std::cout<<std::endl;
        
    }
};

class Costumer{
private:
    std::string name;
    std::string contactinfo;
    std::vector<Order> orderHistory;
public:
    Costumer(std::string n, std::string c):name(n),contactinfo(c){}

    void placeorder(Order order){
        orderHistory.push_back(order);
    }

    void viewOrderHitroy(){
        std::cout<<"Order history for Costumer"<<std::endl;
        if(orderHistory.empty()){
            std::cout<<"Dis Client dont have a History"<<std::endl;
            return;
        }
        for(int i = 0; i < orderHistory.size(); ++i){
            std::cout<<"#Order "<<i + 1<<std::endl;
            orderHistory[i].displayorder();
        }
    }
    std::string getName()const{return name;}
};

int main(){

    Menu menu;
    menu.addDishes(new Appetizer("chcken", 10, true));
    menu.addDishes(new Entree("Wings", 5, 400));
    menu.addDishes(new Appetizer("Stake", 25, false));
    menu.displayManu();

    Costumer person("Gev", "Muradyan");

    Order ord;
    ord.addDish(menu.getDish(0));
    ord.addDish(menu.getDish(1));

    ord.calculateTotatl();
    person.placeorder(ord);

    Order ord2;
    ord2.addDish(menu.getDish(2));

    ord2.calculateTotatl();
    person.placeorder(ord2);

    person.viewOrderHitroy();
    std::cout<<"Bon appetit: (*_*)"<<std::endl;
    return 0;
}