/*
Written in August of 2026 by Noga Levy.

For a given string, identify_keys.cpp monitors looks keywords and send a notification to the user when one is found.
*/

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <unordered_map>
#include "functions.h"


int send_notification(std::string trigger_word, bool &already_triggered, std::string log, std::string msg){
    if (log.find(trigger_word) != std::string::npos){
        if (already_triggered == false){
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