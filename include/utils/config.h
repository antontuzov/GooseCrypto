#ifndef GOOSECRYPTO_CONFIG_H
#define GOOSECRYPTO_CONFIG_H

#include <string>
#include <map>

class Config {
private:
    std::map<std::string, std::string> config_map;
    
public:
    Config();
    
    void load_from_file(const std::string& filepath);
    void load_from_args(int argc, char* argv[]);
    
    std::string get_string(const std::string& key, const std::string& default_value = "") const;
    int get_int(const std::string& key, int default_value = 0) const;
    bool get_bool(const std::string& key, bool default_value = false) const;
    
private:
    void parse_json(const std::string& json_content);
};

#endif // GOOSECRYPTO_CONFIG_H