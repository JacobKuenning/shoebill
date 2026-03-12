#pragma once
#include <mutex>

extern std::mutex outputMx; // outputting to the terminal
extern std::mutex midiMx; // sending midi messages
extern std::mutex vectorMx; // changing vectors in master
extern std::mutex variableMx; // changing variables