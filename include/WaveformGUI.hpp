#pragma once
#include "SimEngine.hpp"
#include "IOController.hpp"

class WaveformGUI {
public:
    // Application entry point for running GUI render loop & handling CLI box input
    static void runApplication(SimEngine* engine);
};
