/*
Written in August of 2026 by Noga Levy.

functions.h is the blueprint for all functions used accross multiple functions
*/

#include <string>
#include <unordered_map>

#pragma once

std::string keylogger(std::string &key_history, std::unordered_map<int, int> &was_key_down);