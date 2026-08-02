#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdint>

// 4-state logic representation according to IEEE Verilog semantics
enum class LogicState : uint8_t {
    ZERO, // Logic 0 / Low
    ONE,  // Logic 1 / High
    X,    // Unknown / Uninitialized
    Z     // High Impedance
};

class Wire; // Forward declaration

struct Event {
    uint64_t timestamp;
    uint64_t sequence_id; // Maintains deterministic FIFO ordering for simultaneous events
    Wire* wire;
    LogicState new_state;

    bool operator>(const Event& other) const {
        if (timestamp != other.timestamp)
            return timestamp > other.timestamp;
        return sequence_id > other.sequence_id;
    }
};
