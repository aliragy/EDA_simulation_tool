#pragma once
#include "Common.h"
#include "Parser.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Gate;

class Wire {
public:
    std::string name;
    LogicState current_state = LogicState::X;
    std::vector<Gate*> fanout_gates; // Gates whose inputs connect to this wire
};

class Gate {
public:
    GateType type;
    int delay = 1;
    std::vector<Wire*> inputs;
    Wire* output = nullptr;

    LogicState evaluate() const;
};

class Netlist {
public:
    std::vector<std::unique_ptr<Wire>> wires;
    std::vector<std::unique_ptr<Gate>> gates;
    std::unordered_map<std::string, Wire*> wire_map;

    Wire* getOrCreateWire(const std::string& name);
    void buildGraph(const ParsedModule& parsed_data);
    Wire* findWire(const std::string& name) const;
};
