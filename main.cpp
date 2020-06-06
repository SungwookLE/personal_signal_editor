#include <iostream>
#include <string>
using namespace std;

class People{
    private:
        int age;
        string name;
        double height;

    public:
        
        void set_people(int _age, string _name, double _heigh);
        void show_people();

        People(){
            
            cout << " 생성자 호출: 인자값 없음 " <<endl;
            age  = 31;
            name = "성우기";
            height = 181;
            
        }

        People(int _age, string _name, double _height){
            cout << " 생성자 호출: 인자값 3개 " << endl;
            age = _age;
            name = _name;
            height = _height;
        }
};

void People::set_people(int _age, string _name, double _height){
    cout << "함수를 통한 객체값 변경" << endl;
    age = _age;
    name = _name;
    height = _height;
}

void People::show_people(){

    cout << "나이: " << age << endl;
    cout << "이름: " << name << endl;
    cout << "키 : " << height << endl << endl;
}

int main(){
    // 기본 생성자 사용
    People P = People();
    P.show_people();

    // 오버로딩 된 생성자 사용
    People P2(31, "JIEUN", 165);
    P2.show_people();

    // P객체의 값을 변경
    P2.set_people(18, "SEXY", 170);
    P2.show_people();


    // // Private  테스트??
    // cout << "TEST SOMETHING" << endl;
    // cout << P2.age << endl;


    return 0;
}