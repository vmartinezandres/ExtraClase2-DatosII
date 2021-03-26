#include <iostream>

using namespace std;

// PATRON FACTORY
class Animal {
public:
    string getTipoAnimal(){ return this -> tipoAnimal;}
protected:
    string tipoAnimal;
};

class Perro : public Animal {
public:
    Perro() : Animal(){
        tipoAnimal = "Animal perro";
        cout << "Se creo un perro" << endl;
    }
};

class Gato : public Animal {
public:
    Gato() : Animal(){
        tipoAnimal = "Animal gato";
        cout << "Se creo un gato" << endl;
    }
};

class Pajaro : public Animal {
public:
    Pajaro() : Animal(){
        tipoAnimal = "Animal pajaro";
        cout << "Se creo un pajaro" << endl;
    }
};

class AnimalFactory {
public:
    Animal* getAnimal(){
        int opcion = 0;
        cout << "1) Perro" << endl;
        cout << "2) Gato" << endl;
        cout << "3) Pajaro" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                animal = new Perro;
                break;

            case 2:
                animal = new Gato;
                break;

            case 3:
                animal = new Pajaro;
                break;

            default:
                animal = nullptr;
                break;
        }

        return animal;
    }

private:
    Animal* animal;
};

// PATRON ABSTRACT FACTORY

class AnimalTerrestre {
 public:
  virtual ~AnimalTerrestre(){};
  virtual string CreacionATerrestre() const = 0;
};

class Zorro : public AnimalTerrestre {
 public:
  string CreacionATerrestre() const override {
    return "Se creo un Zorro";
  }
};

class Cerdo : public AnimalTerrestre {
  string CreacionATerrestre() const override {
    return "Se creo un cerdo";
  }
};

class AnimalAcuatico {
 public:
  virtual ~AnimalAcuatico(){};
  virtual string CreacionAAcuatico() const = 0;
};

class Delfin : public AnimalAcuatico {
 public:
  string CreacionAAcuatico() const override {
    return "Se creo un delfin";
  }
};

class Pez : public AnimalAcuatico {
 public:
  string CreacionAAcuatico() const override {
    return "Se creo un pez";
  }
};


class AbstractFactory {
 public:
  virtual AnimalTerrestre *CrearAnimalTerrestre() const = 0;
  virtual AnimalAcuatico *CrearAnimalAcuatico() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
 public:
    AnimalTerrestre *CrearAnimalTerrestre() const override {
    return new Zorro();
  }
    AnimalAcuatico *CrearAnimalAcuatico() const override {
    return new Delfin();
  }
};

class ConcreteFactory2 : public AbstractFactory {
 public:
    AnimalTerrestre *CrearAnimalTerrestre() const override {
    return new Cerdo();
  }
    AnimalAcuatico *CrearAnimalAcuatico() const override {
    return new Pez();
  }
};

void ClientCode(const AbstractFactory &factory) {
    const AnimalTerrestre *zorrito = factory.CrearAnimalTerrestre();
    const AnimalAcuatico *delfinito = factory.CrearAnimalAcuatico();
    cout << delfinito->CreacionAAcuatico() << endl;
    delete zorrito;
    delete delfinito;
}

// MAIN

int main() {
    
    cout << "El patron a continucacion es: factory" << endl;
    AnimalFactory fabricaAnimal; // Stack
    Animal* animalSeleccionado; // Heap
    
    animalSeleccionado = fabricaAnimal.getAnimal();
    
    if(animalSeleccionado != nullptr) {
        cout << animalSeleccionado ->getTipoAnimal() << endl;
    }
    else {
        cout << "Ese Animal no existe" <<  endl;
    }
    
    cout << "------------------------------------" << endl;
    
    cout << "El patron a continucacion es: abstract factory" << endl;

    cout << "Se creara un delfin:" << endl;
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    cout << endl;
    cout << "Se creara un pez:" << endl;
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
}
