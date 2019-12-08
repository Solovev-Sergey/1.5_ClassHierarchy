#include <iostream>
#include <cmath>
#include <vector>

class capacitor {
protected:
    double C;
    double E;

public:
    virtual double get_capacitance()=0;
};

class flat_capacitor : public capacitor {
    double A;
    double d;
public:

    flat_capacitor (double A, double d){
        this->E=1;
        this->A=A;
        this->d=d;
        this->C=(this->A)/(this->d);
    }
    flat_capacitor (double a, double b, double d){
        this->E=1;
        this->A=a*b;
        this->d=d;
        this->C=(this->A)/(this->d);
    }
    virtual double get_capacitance(){
        return this->C;
    }
    virtual flat_capacitor add_dielectric (double E) {
        flat_capacitor newCap=flat_capacitor(this->A,this->d);
        newCap.E*=E;
        newCap.C*=E;
        return newCap;
    }
};

class cylindrical_capacitor : public capacitor {
    double l;
    double R1;
    double R2;
public:

    cylindrical_capacitor (double l, double R1, double R2){
        this->E=1;
        this->l=l;
        this->R1=R1;
        this->R2=R2;
        this->C=2*3.14*(this->l)/fabs(log(this->R1/this->R2));
    }
    virtual double get_capacitance(){
        return this->C;
    }
    virtual cylindrical_capacitor add_dielectric (double E) {
        cylindrical_capacitor newCap=cylindrical_capacitor(this->l,this->R1,this->R2);
        newCap.E*=E;
        newCap.C*=E;
        return newCap;
    }
};

class spherical_capacitor : public capacitor {
    double R1;
    double R2;
public:

    spherical_capacitor ( double R1, double R2){
        this->E=1;
        this->R1=R1;
        this->R2=R2;
        this->C=4*3.14/fabs(1/R1+1/R2);
    }
    virtual double get_capacitance(){
        return this->C;
    }
    virtual spherical_capacitor add_dielectric (double E) {
        spherical_capacitor newCap=spherical_capacitor(this->R1,this->R2);
        newCap.E*=E;
        newCap.C*=E;
        return newCap;
    }
};

int main(){
    std::cout << "cylindric capacitor:"<< std::endl;
    cylindrical_capacitor a1=cylindrical_capacitor(1,2,3); // make spherical_capacitor l=1 R1=2,R2=3
    std::cout << "capacitance:"<< a1.get_capacitance() << std::endl;
    a1=a1.add_dielectric(0.1); //put dielectric
    std::cout <<"new capacitance (Eps=0.1):"<< a1.get_capacitance() << std::endl << std::endl;

    std::cout << "spherical capacitor:"<< std::endl;
    spherical_capacitor a2=spherical_capacitor(1,2); // make spherical_capacitor R1=1,R2=2
    std::cout << "capacitance:"<< a2.get_capacitance() << std::endl;
    a2=a2.add_dielectric(0.1); //put dielectric
    std::cout <<"new capacitance (Eps=0.1):"<< a2.get_capacitance() << std::endl << std::endl;

    std::cout << "2 same flat capacitors (2 types of constructor):"<< std::endl;
    flat_capacitor a3=flat_capacitor(10,1); //make flat_capacitor S=10,d=1 (S--square of plate)
    std::cout << "capacitance:"<< a3.get_capacitance() << std::endl;
    a3=a3.add_dielectric(0.1); //put dielectric
    std::cout <<"new capacitance (Eps=0.1):"<< a3.get_capacitance() << std::endl << std::endl;

    a3=flat_capacitor(2,5,1); //make flat_capacitor S=10,d=1 (a--width b-length of plates)
    std::cout << "capacitance:"<< a3.get_capacitance() << std::endl;
    a3=a3.add_dielectric(0.1); //put dielectric
    std::cout <<"new capacitance (Eps=0.1):"<< a3.get_capacitance() << std::endl << std::endl;
    return 0;
}


