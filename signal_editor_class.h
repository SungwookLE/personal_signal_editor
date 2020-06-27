#ifndef __CLASS_SIG_EDIT_
#define __CLASS_SIG_EDIT_
// 요구사항 1) 신호 Extend 기능 : "유효기간 > 5sec 이상" 만들기 위함 signal_editor::extend_signal(int immune, int exten)
// 요구사항 2-1) 신호 붙이기 기능 : 복수개의 신호 펄스를 붙일 수 잇어야하고 이 때 신호 중간에 PAUSE 시간도 설정 가능해야 함
// 요구사항 2-2) 신호붙이기 기능: 복수개의 신호를 붙일 때, 전체 FULL SET을 입력하면 Combination 고려해서 자동으로 붙여진 신호가 출력된다.

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

class signal_editor{
    private:
        std::string buffer;
        std::ifstream file;
        std::string file_name;
        int im_cnt;
        void validation(std::string &ik);

    public:
        signal_editor(): buffer(""){} //initialization list (constructor)
        ~signal_editor(){ std::cout << "FILE: " <<signal_editor::file_name<<
        " CLOSED OVER!!" << std::endl; } // distructor

        //getter, assessor
        std::string show_editor() const {return buffer;}
        //setter, mutator
        void insert_line(std::string n){buffer = n;}
        
        //member function
        void open_signal(std::string &fil);
        void close_signal(){file.close();}
        void read_signal(std::string &fil);
        void extend_signal(int immune, int exten, std::string &fil);
        void liked_signal(int file_num, int pause_cnt, std::vector<std::string> _argu);
        void combination_signal(int file_num, int pause_cnt, std::vector<std::string> _argu);
};

#endif