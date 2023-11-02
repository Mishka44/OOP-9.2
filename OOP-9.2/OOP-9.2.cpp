#include <iostream>

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



class Apple_tree :public Plants {
    virtual Harvest* Fruit_pic() {
        return new Apple(23, "green");
    }

};

class Strawberry_tree :public Plants {
    virtual Harvest* Fruit_pic() {

        return new Strawberry(100, "red");
    }



};




int main()
{
    std::cout << "Hello World!\n";
}

