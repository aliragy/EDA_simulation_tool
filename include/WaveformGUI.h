#pragma once
#include "SimEngine.h"
#include "IOController.h"

class WaveformGUI {
public:
    // Application entry point for running GUI render loop & handling CLI box input
    static void runApplication(SimEngine* engine);
};
