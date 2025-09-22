#include "../../include/utils/config.h"
#include <fstream>
#include <sstream>
#include <iostream>

Config::Config() {}

void Config::load_from_file(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open config file: " << filepath << std::endl;
        return;
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    
    parse_json(content);
    
    file.close();
}

void Config::load_from_args(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg.substr(0, 2) == "--") {
            size_t pos = arg.find('=');
            if (pos != std::string::npos) {
                std::string key = arg.substr(2, pos - 2);
                std::string value = arg.substr(pos + 1);
                config_map[key] = value;
            }
        }
    }
}

std::string Config::get_string(const std::string& key, const std::string& default_value) const {
    auto it = config_map.find(key);
    if (it != config_map.end()) {
        return it->second;
    }
    return default_value;
}

int Config::get_int(const std::string& key, int default_value) const {
    auto it = config_map.find(key);
    if (it != config_map.end()) {
        return std::stoi(it->second);
    }
    return default_value;
}

bool Config::get_bool(const std::string& key, bool default_value) const {
    auto it = config_map.find(key);
    if (it != config_map.end()) {
        return it->second == "true" || it->second == "1";
    }
    return default_value;
}

void Config::parse_json(const std::string& json_content) {
    // Simple JSON parser (in a real implementation, you would use a proper JSON library)
    // This is a very basic implementation for demonstration purposes
    size_t pos = 0;
    while ((pos = json_content.find('"', pos)) != std::string::npos) {
        // Find key
        size_t key_start = pos + 1;
        size_t key_end = json_content.find('"', key_start);
        if (key_end == std::string::npos) break;
        
        std::string key = json_content.substr(key_start, key_end - key_start);
        
        // Find value
        size_t value_pos = json_content.find(':', key_end);
        if (value_pos == std::string::npos) break;
        
        size_t value_start = json_content.find('"', value_pos);
        if (value_start == std::string::npos) {
            // Try to find numeric value
            value_start = json_content.find_first_not_of(" \t\n", value_pos + 1);
            if (value_start != std::string::npos && 
                (std::isdigit(json_content[value_start]) || json_content[value_start] == '-')) {
                size_t value_end = json_content.find_first_not_of("0123456789.", value_start);
                if (value_end == std::string::npos) value_end = json_content.length();
                std::string value = json_content.substr(value_start, value_end - value_start);
                config_map[key] = value;
            }
            pos = value_start;
            continue;
        }
        
        size_t value_end = json_content.find('"', value_start + 1);
        if (value_end == std::string::npos) break;
        
        std::string value = json_content.substr(value_start + 1, value_end - value_start - 1);
        config_map[key] = value;
        
        pos = value_end + 1;
    }
}