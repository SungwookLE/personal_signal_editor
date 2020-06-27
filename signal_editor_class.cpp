#include "signal_editor_class.h"

 void signal_editor::validation(std::string &ik){
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

void signal_editor::open_signal(std::string &fil){
        validation(fil);
        file.open(fil);
        file_name = fil;
}

void signal_editor::read_signal(std::string &fil){
    open_signal(fil);
    while (!file.eof())
    {
        std::getline(file, buffer);
        if (buffer != "")
        {
            std::cout << buffer << std::endl;
        }
    }
    close_signal();
}

void signal_editor::extend_signal(int immune, int exten, std::string &fil){
        // file.clear();
        // file.seekg( 0, std::ios_base::beg);
        open_signal(fil);
        im_cnt = 0;
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
        close_signal();
        std::cout << "↑↑ EXTEND FINISH ↑↑" << std::endl;
}

void signal_editor::liked_signal(int file_num, int pause_cnt, std::vector<std::string> _argu){
    if (file_num < 2 ){
        std::cout << "LINKED FUNCTION CAN WORK ONLY IF THE FILE's NUMBER IS OVER THAN TWO!!" << std::endl;
        return;
    }
    else{
        for (int i = 0; i < file_num; ++i){
            read_signal(_argu.at(i));
            if (i < (file_num-1)){
                for (int j = 0; j < pause_cnt; j++){
                    std::cout << "0" << std::endl;
                }
            }
        }
    }
    std::cout << "↑↑ LINKED FINISH ↑↑" << std::endl;
}

void signal_editor::combination_signal(int file_num, int pause_cnt, std::vector<std::string> _argu){
    if (file_num < 2 ){
        std::cout << "COMBINATION FUNCTION CAN WORK ONLY IF THE FILE's NUMBER IS OVER THAN TWO!!" << std::endl;
        return;
    }
    else{



    }

}
        


 
