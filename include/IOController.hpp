#pragma once
#include "SimEngine.hpp"
#include <string>
#include <vector>

class IOController {
public:
    // Translates text commands (e.g. "set b 1 at 5", "run 100") into engine events
    static void executeCommand(const std::string& command, SimEngine* engine);

    // Exports full simulation history into IEEE 1364 standard VCD format
    static void exportVCD(const std::string& filename, const Netlist* netlist, const std::vector<Event>& history);
};
