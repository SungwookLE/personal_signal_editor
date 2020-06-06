#include <cassert>
#include <iostream>
#include <string>

class Student{

    private:
    std::string _Name;
    int _Grade;
    float _Average;

    void verify(){
        if ( Grade() < 0 || Grade() > 12 || Average() < 0.0 || Average() > 4.0){
            std::cout << "error1" << std::endl;
            std::cout << _Grade << std::endl;
            throw std::invalid_argument("NO NO");
        }
    }

    public:
    Student(std::string n, int g, float a ): _Name(n), _Grade(g), _Average(a){ verify(); }

    void Name(std::string n){
        _Name = n;
        verify();
    }
    void Grade(int g){
        _Grade = g;
        verify();
    }
    void Average(int a){
        _Average = a;
        verify();
    }
    std::string Name() const { return _Name;}
    int Grade() const { return _Grade;}
    float Average() const { return _Average;}
};



int main(){

    Student Real("WOOK", 7, 3.9);
    assert(Real.Name() == "WOOK");
    assert(Real.Grade()==7);

    bool caught{false};
    try{
        Student MAN("MIKE", -5, 4.0);

        std::cout << MAN.Name() << std::endl;
        std::cout << MAN.Grade() << std::endl;
        std::cout << MAN.Average() << std::endl;
    } 
    catch(...){
        caught=true;
    }
     assert(caught);



    
    return 0;
}

