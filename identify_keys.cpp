/*
Written in August of 2026 by Noga Levy.

Using keylogger.cpp's keylog() function, identify_keys.cpp monitors the keylog for keywords and send a notification to the user when one is found.
*/


#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <unordered_map>
#include "functions.h"

// Variable set up
std::string keylog = " ";
std::unordered_map<int, int> key_press_map;

bool gmail_triggered = false;

int send_notification(std::string trigger_word, bool &already_triggered, std::string log, std::string msg){
    if (log.find(trigger_word) != std::string::npos){
        if (already_triggered == false){

            // Finally, we create a Windows pop-up titled "TattleType," with the response_intro + data_buyer
            already_triggered = true;

            MessageBoxA(
                NULL, 
                (msg).c_str(),  // Body text
                "TattleType",   // Title bar
                MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL
            );
        }
    } else {
        already_triggered = false;
    }

    return 0;
}

int main(){
    // Initizializing unordered map
    for (int key = 0x08; key <= 0xFF; key++){
        key_press_map[key] = false;
    }
    
    // Key-logging loop
    while (true){
        keylogger(keylog, key_press_map);

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000){
            std::cout << "Ending Program" << std::endl;
            return 0;
        }

        send_notification("gmail.com", gmail_triggered, keylog, "Achievement: Business Man.\nMaiiiilll, the mail is overwhelming--");
    }
}
