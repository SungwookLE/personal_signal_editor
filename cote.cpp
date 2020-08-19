#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>

//time over : FAIL THE CODING TEST LV2.



using namespace std;

vector<string> solution(vector<string>& record) {
    vector<string> answer(record.size());


    std::string token1, token2, token3, temp;
    istringstream line;
    unordered_map<string, string> INFO;
    for (int i = 0; i < record.size(); ++i)
    {
        line.str(record.at(i));
        (line >> token1 >> token2 >> token3);
        {

            if (token1.substr(0,3) !="uid"){
                temp = token1;
                if (token2.substr(0,3) == "uid")
                {
                    token1 = token2;
                    token2 = temp;
                }
                else
                {
                    token1 = token3;
                    token3 = temp;
                }
            }
            if ( (token2 == "Enter") || (token2 == "Leave") || (token2 == "Change") ){
            }
            else
            {
                 temp = token2;
                 token2 = token3;
                 token3 = temp;
            }
            INFO[token1] = token3;

            if (token2 == "Enter"){
                answer.at(i)= INFO[token1] + "님이 들어왔습니다.";
            }
            else if (token2 == "Leave"){
                answer.at(i) = INFO[token1] + "님이 나갔습니다.";
            }
            else if (token2 =="Change"){
                
                for (int j = 0; j < record.size(); ++j)
                {
                    line.clear();
                    line.str(record.at(j));
                    while(line >> token1 >> token2>> token3){
            
                        if (token1.substr(0,3) !="uid"){
                        temp = token1;
                        if (token2.substr(0,3) == "uid")
                        {
                            token1 = token2;
                            token2 = temp;
                        }
                        else
                        {
                            token1 = token3;
                            token3 = temp;
                        }
                        }
                        if ( (token2 == "Enter") || (token2 == "Leave") || (token2 == "Change") ){
                        }
                        else
                        {
                        temp = token2;
                        token2 = token3;
                        token3 = temp;
                        }

                        

                        if (token2 == "Enter"){
                        answer.at(j)= INFO[token1] + "님이 들어왔습니다.";
                        }
                        else if (token2 == "Leave"){
                        answer.at(j) = INFO[token1] + "님이 나갔습니다.";
                        }
                    }
                }
            }
        line.clear();
        }
    }
        return answer;
    
}


int main(){

    int n = 1;
    vector<string> record = {"Enter uid3 bvv", "uid9 Svv Enter",  "uid9 Grooot_Mom Change","uid11 88 Leave", "uid11 88 Enter", "uid11 88 Leave", "uid11 groot Change", "Change uid3 groot_bro"};
    for (auto it:solution(record)){
        cout << n <<": " <<it << endl;
        n++;
    }

    return 0;
}