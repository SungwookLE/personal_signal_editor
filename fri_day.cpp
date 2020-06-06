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

    void validation(std::string &ik){
        file.open(ik);
        
        if (!file.good()){
           std::cout << "FILE IS NOT GOOD" <<std::endl;
           file.close();
           throw std::invalid_argument("FILE IS NOT GOOD");
        }
        file.close();
        return;
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
        std::cout << "□□□READ FINISH□□□"<<std::endl;
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
        std::cout << "□□□EXTEND FINISH□□□"<<std::endl;
    }
};

int main(int argc, char *argv[]){

    std::vector<std::string> _argu;

    try{
        if (argc < 2)
            throw std::invalid_argument("HELP MESSAGE:: this class is file(signal) manipulator");
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