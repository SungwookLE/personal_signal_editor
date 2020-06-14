#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

// 요구사항 1) 신호 Extend 기능 : "유효기간 > 5sec 이상" 만들기 위함 signal_editor::extend_signal(int immune, int exten)
// 요구사항 2-1) 신호 붙이기 기능 : 복수개의 신호 펄스를 붙일 수 잇어야하고 이 때 신호 중간에 PAUSE 시간도 설정 가능해야 함
// 요구사항 2-2) 신호붙이기 기능: 복수개의 신호를 붙일 때, 전체 FULL SET을 입력하면 Combination 고려해서 자동으로 붙여진 신호가 출력된다.


class signal_editor{
    private:
    std::string buffer;
    std::ifstream file;
    std::string file_name;
    int im_cnt;

    void validation(std::string &ik){
        try{
            file.open(ik);
            
            if (!file.good()){
            file.close();
            throw std::invalid_argument("File(" + ik + ") is NOT GOOD");
            }
        }
        catch(std::invalid_argument& ia){
        std::cout<< ia.what() << std::endl;
        }
        file.close();
    }
    public:
    signal_editor(): buffer(""){} //initialization list (constructor)
    ~signal_editor(){ std::cout << "FILE: " <<signal_editor::file_name<<
     " CLOSED OVER!!" << std::endl; } // distructor

    //getter, assessor
    std::string show_editor() const {return buffer;}
    //setter, mutator
    void insert_line(std::string n){
        buffer = n;
    }
    //member function
    void open_signal(std::string &fil){
        validation(fil);
        file.open(fil);
        file_name = fil;
        
    }
    void close_signal(){
        file.close();
    }
    void read_signal(){
        while(!file.eof()){
            std::getline(file,buffer);
            if (buffer !=""){
                std::cout << buffer << std::endl;
            }
        }
        std::cout << "↑↑ (Original) File ↑↑"<<std::endl;
    }
    void extend_signal(int immune, int exten){
        file.clear();
        file.seekg( 0, std::ios_base::beg);
        im_cnt=0;
        while(!file.eof()){
            std::getline(file,buffer);
            if (buffer !=""){
                
                
                if (im_cnt >= immune){
                    for (int i=0 ; i < exten ; i++ )
                        std::cout <<buffer <<std::endl;
                }
                else
                    std::cout <<buffer<<std::endl;

                im_cnt++;
            }
        }
        std::cout << "↑↑ EXTEND FINISH ↑↑"<<std::endl;
    }

    // 음 이게 파일 여러개를 열어가지고 작업해야 하는 거라서, private 변수로 몇개를 더 선언해 놓을까? 그게 효율적인가?
    // 아님 다른 클래스로 작업을 할까?
    void liked_signal(int file_num, int pause_cnt );
    void combination_signal(int file_num);

};

int main(int argc, char *argv[]){

    std::vector<std::string> _argu;

    try{
        if (argc < 2 )
            throw std::invalid_argument("HELP MESSAGE:: this class is file(signal) manipulator");
        
        if ( std::string(argv[1]).compare("--option")==0)
            throw std::invalid_argument("OPTION LIST");


    }
    catch(std::invalid_argument& ia){
        std::cout<< ia.what() << std::endl;
        return 0;
    }
    
    
    
    for (int i=1; i < (argc); i++ ){
        _argu.push_back(argv[i]);
        std::cout << i << "번째 읽을 파일: ";
        std::cout << _argu.back() << std::endl;
        }
    
    signal_editor file;
    file.open_signal(_argu.at(0));
    file.read_signal();
    file.extend_signal(2,2);
    file.close_signal();

   
    


    return 0;
}