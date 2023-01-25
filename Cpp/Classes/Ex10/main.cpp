#include <iostream>

using std::string, std::cout;

/*
We want to store the information of different vehicles. Create a class named
Vehicle with two data member named mileage and price. Create its two subclasses

-> Car with data members to store ownership cost, warranty (by years), seating capacity and fuel type (diesel or petrol).

-> Bike with data members to store the number of cylinders, number of gears, cooling type(air, liquid or oil),
wheel type(alloys or spokes) and fuel tank size(in inches)

Make another two subclasses Audi and Ford of Car, each having a data member to store the model type.

Next, make two subclasses Yamaha and Honda, each having a data member to store the make-type.

Now, store and print the information of an Audi and a Ford car (i.e. model type, ownership cost,
warranty, seating capacity, fuel type, mileage and price.) Do the same for a Bajaj and a TVS bike.
*/

class Vehicle {
private:
    float mileage, price;
public:
    Vehicle(float mile, float price) : mileage(mile), price(price) {}

    virtual void info() {
        cout << "Mileage: " << this->mileage << "\n";
        cout << "Price: " << this->price << "\n";
    }
};

class Car : public Vehicle {
public:
    enum Fuel {
        Petrol, Diesel
    };
private:
    float ownership_cost;
    int warranty, seating_capacity;
    Fuel fuel_type;
public:
    Car(float mileage, float price, float ownership_cost, int warranty, int seating_capacity, Fuel fuel_type)
            : Vehicle(mileage, price),
              ownership_cost(ownership_cost),
              warranty(warranty),
              seating_capacity(seating_capacity),
              fuel_type(fuel_type) {}

    virtual void info() override {
        cout << "Car info: " << "\n";
        Vehicle::info();
        cout << "Ownership cost: " << this->ownership_cost << "\n";
        cout << "Warranty: " << this->warranty << " years " << "\n";
        cout << "Seating capacity: " << this->seating_capacity << "\n";
        cout << "Fuel Type: " << this->fuel_type << "\n";
    };
};

class Bike : public Vehicle {
public:
    enum Cooling {
        Air, Liquid, Oil
    };
    enum Wheel {
        Alloy, Spoke
    };
private:
    int num_cylinders, num_gears;
    Cooling cooling_type;
    Wheel wheel_type;
    float fuel_tank_size;
public:
    Bike(float mileage,
         float price,
         int num_cylinders,
         int num_gears,
         Cooling cooling_type,
         Wheel wheel_type,
         float fuel_tank_size
    ) : Vehicle(mileage, price),
        num_cylinders(num_cylinders),
        num_gears(num_gears),
        cooling_type(cooling_type),
        wheel_type(wheel_type),
        fuel_tank_size(fuel_tank_size) {}

    virtual void info() override {
        cout << "Bike info: " << "\n";
        Vehicle::info();
        cout << "Number of cylinders: " << this->num_cylinders << "\n";
        cout << "Number of gears: " << this->num_gears << " years " << "\n";
        cout << "Cooling type: " << this->cooling_type << " years " << "\n";
        cout << "Wheel Type: " << this->wheel_type << "\n";
        cout << "Fuel tank size: " << this->fuel_tank_size << "\n";
    };
};

class Ford : public Car {
private:
    string model_type;
public:
    Ford(string model_type,
         float mileage,
         float price,
         float ownership_cost,
         int warranty,
         int seating_capacity,
         Fuel fuel_type
    ) :
            Car(mileage,
                price,
                ownership_cost,
                warranty,
                seating_capacity,
                fuel_type
            ),
            model_type(model_type) {}

    void info() final {
        Car::info();
        cout << "Model type: " << this->model_type << "\n";
    }
};

class Audi : public Car {
private:
    string model_type;
public:
    Audi(string model_type,
         float mileage,
         float price,
         float ownership_cost,
         int warranty,
         int seating_capacity,
         Fuel fuel_type
    ) :
            Car(mileage,
                price,
                ownership_cost,
                warranty,
                seating_capacity,
                fuel_type
            ),
            model_type(model_type) {}

    void info() final {
        Car::info();
        cout << "Model type: " << this->model_type << "\n";
    }
};

class Yamaha : public Bike {
private:
    string make_type;
public:
    Yamaha(string make_type,
           float mileage,
           float price,
           int num_cylinders,
           int num_gears,
           Cooling cooling_type,
           Wheel wheel_type,
           float fuel_tank_size
    ) :
            Bike(mileage,
                 price,
                 num_cylinders,
                 num_gears,
                 cooling_type,
                 wheel_type,
                 fuel_tank_size
            ),
            make_type(make_type) {}

    void info() final {
        Bike::info();
        cout << "Model type: " << this->make_type << "\n";
    }

};

class Honda : public Bike {
private:
    string make_type;
public:
    Honda(string make_type,
          float mileage,
          float price,
          int num_cylinders,
          int num_gears,
          Cooling cooling_type,
          Wheel wheel_type,
          float fuel_tank_size
    ) :
            Bike(mileage,
                 price,
                 num_cylinders,
                 num_gears,
                 cooling_type,
                 wheel_type,
                 fuel_tank_size
            ),
            make_type(make_type) {}

    void info() final {
        Bike::info();
        cout << "Model type: " << this->make_type << "\n";
    }
};

int main() {

    Ford *f = new Ford("Caminhonete",
                       1525.66,
                       250000,
                       2000,
                       3,
                       5,
                       Ford::Fuel::Diesel);

    Audi *a = new Audi("Esportivo",
                       4525.66,
                       3000000,
                       10000,
                       5,
                       2,
                       Audi::Fuel::Petrol);

    cout << "========================" << "\n";
    f->info();
    cout << "========================" << "\n";
    a->info();
    cout << "========================" << "\n";

    Yamaha *y = new Yamaha("Scooter",
                           45062.41,
                           6500.99,
                           2,
                           5,
                           Yamaha::Cooling::Liquid,
                           Yamaha::Wheel::Spoke,
                           15.0);

    Honda *h = new Honda("Chopper",
                         150301.10,
                         9000,
                         4,
                         5,
                         Honda::Cooling::Oil,
                         Honda::Wheel::Alloy,
                         25.1);

    cout << "========================" << "\n";
    y->info();
    cout << "========================" << "\n";
    h->info();
    cout << "========================" << "\n";

    return 0;
}
