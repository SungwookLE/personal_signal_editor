
#include "signal_editor_class.h"

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
  
    file.extend_signal(2,2, _argu.at(0));
    file.read_signal(_argu.at(0));
    std::cout << "TEST" << std::endl;
    file.liked_signal((argc - 1), 5, _argu);

    return 0;
}