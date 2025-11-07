#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H

#include <string>

class KeyValuePair {
private:
    std::string key;
    std::string value;

public:
    KeyValuePair(const std::string& k = "", const std::string& v = "") 
        : key(k), value(v) {}

    const std::string& getKey() const { return key; }
    const std::string& getValue() const { return value; }
    void setValue(const std::string& v) { value = v; }

    
    bool operator<(const KeyValuePair& other) const { return key < other.key; }
    bool operator>(const KeyValuePair& other) const { return key > other.key; }
    bool operator==(const KeyValuePair& other) const { return key == other.key; }
    bool operator!=(const KeyValuePair& other) const { return !(*this == other); }

};

#endif