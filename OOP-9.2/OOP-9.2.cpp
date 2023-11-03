#include <iostream>
#include <Windows.h>
#include <vector>

class Harvest {
public:
    Harvest(std::string new_name, std::string new_color, int new_weight) :name(new_name), fet_color(new_color), weight(new_weight) {}

    void Set_Name(std::string new_name) {
        this->name = new_name;
    }

    void Set_fet_color(std::string new_color) {
        this->fet_color = new_color;
    }
    std::string Get_name() {
        return this->name;

    }
    std::string Get_fet_color() {
        return this->fet_color;

    }



private:
    std::string name;
    std::string fet_color;
    int weight;

};

class Plants {
public:
    Plants(int number) : fetus_counter(number){}

    virtual Harvest* Fruit_pic() = 0;

    std::string Get_color() {
        return this->color;

    }

    std::string Get_size() {
        return this->size;

    }

    void Set_Color(std::string new_color) {
        this->color = new_color;
    }

    void Set_Size(std::string new_size) {
        this->size = new_size;
    }

    int Get_Fetus_counter() {
        return fetus_counter;
    }
    void Set_fetus_counter(int number) {
        this->fetus_counter = number;
    }

private:
    std::string color;
    int fetus_counter;
    std::string size;
};



class Apple : public Harvest {
public:
    Apple(int new_weight, std::string new_color) : Harvest("Apple", new_color, new_weight) {}


};

class Strawberry : public Harvest {
public:
    Strawberry(int new_weight, std::string new_color) : Harvest("strawberry", new_color, new_weight) {}


};

class Blackberry : public Harvest {
public:
    Blackberry(int new_weight, std::string new_color) : Harvest("Blackberry", new_color, new_weight) {}


};



class Apple_tree :public Plants {
public:
    Apple_tree(int number, std::string size) : Plants(number){
        this->Set_Size(size);
    }

    virtual Harvest* Fruit_pic() {
        if (this->Get_Fetus_counter() != 0) {
            this->Set_fetus_counter(this->Get_Fetus_counter() - 1);
            return new Apple(23, "green");
        }
    }
};

class Strawberry_tree :public Plants {
   public:
    Strawberry_tree(int number, std::string size) : Plants(number){
        this->Set_Size(size);
    }

    virtual Harvest* Fruit_pic() {
        if (this->Get_Fetus_counter() != 0) {
            this->Set_fetus_counter(this->Get_Fetus_counter() - 1);
            return new Strawberry(100, "red");

        }
            
       
    }

};



class Blackberry_tree :public Plants {
public:
    Blackberry_tree(int number, std::string size) : Plants(number) {
        this->Set_Size(size);
    }

    virtual Harvest* Fruit_pic() {
        if (this->Get_Fetus_counter() != 0) {
            this->Set_fetus_counter(this->Get_Fetus_counter() - 1);
            return new Blackberry(50, "black");

        }


    }

};




int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    std::vector<Plants*> collection;
    collection.push_back(new Blackberry_tree(13, "small"));
    collection.push_back(new Strawberry_tree(10, "medium"));
    collection.push_back(new Apple_tree(5, "Big"));
    
    for (auto& el : collection) {
        std::cout << el->Fruit_pic()->Get_name()   << "\t";
        std::cout << el->Get_size() << "\n";
        std::cout << "осталось плодов на дереве: " << el->Get_Fetus_counter() << "\n";
    }
}

