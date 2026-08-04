/*
Written in August of 2026 by Noga Levy.

notification.cpp uses Window's native MessageBox to send a notification to the user. Works on Windows devices.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
#include <windows.h>

std::string responses[7] = {" the [noun] dark council.",
                       " the official [noun] cult, located in Wisconsin.",
                       " the royal [noun] orchestra.",
                       " ... no one. It's not that interesting, honestly",
                       " the forests where the [noun] nymphs run free!",
                       " the secret [noun] division in the CIA.",
                       " the Tibetan monks on Mt. [noun]"};

int main(){
    // We set up the random array-index generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, std::size(responses) - 1);

    // Now, we define the general "introduction" to what a keylogger could find if it were lying on the user's device.
    std::string response_intro = "Now, I'm not spyware, but if I were, I'd sell your recent data to";
    
    // And, using the random number generator from before, we choose a parody "data buyer," replacing the noun with the user's input 
    std::string data_buyer_general = responses[distr(gen)];

    std::string data_buyer;
    int noun_pos = data_buyer_general.find("[noun]");

    // Retrieving the user input... [Placeholder for now, until the keylogger is complete]
    std::string user_response;
    std::cin >> user_response;

    if (noun_pos > 0){
        data_buyer = data_buyer_general.substr(0, noun_pos) + user_response + data_buyer_general.substr(noun_pos + 6);
    } else {
        data_buyer = data_buyer_general;
    }

    // Finally, we create a Windows pop-up titled "TattleType," with the response_intro + data_buyer
    MessageBoxA(
        NULL, 
        (response_intro + data_buyer).c_str(), // Body text
        "TattleType",                          // Title bar
        MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL
    );
    
    return 0;
}
