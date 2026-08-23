/*
Written in August of 2026 by Noga Levy.

Using the functions in functions.h, main.cpp is the sum of all the other programs--it uses keylogger.cpp to log the keys, and 
send_notification.cpp to handle notifications.
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

        send_notification("@gmail.com", gmail_triggered, keylog, "Achievement: Business Man.\nMaiiiilll, the mail is overwhelming--");
    }
}
