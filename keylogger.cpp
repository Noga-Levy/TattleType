#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

std::string key_history = " ";


int main(){
    while (true){
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000){
            std::cout << "Ending Program" << std::endl;
            std::cout << key_history << std::endl;
            return 0;
        } else {
            for (int key = 0x20; key < 0x5A; key++){

                if (GetAsyncKeyState(key) & 0x8000){
                    Sleep(100);
                    char helper_c = static_cast<char>(key);
                    std::string c = std::string(1, helper_c);
                    int str_length = key_history.length();

                    if (str_length == 10){
                        key_history = key_history.substr(1, str_length - 1);
                        key_history = key_history + c;
                    } else {
                        key_history = key_history + c;
                    }
                    std::cout << key_history << std::endl;
                }
            }
        }
    }

    return 0;

}