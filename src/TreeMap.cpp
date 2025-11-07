#include "TreeMap.h"

void TreeMap::insert(const std::string& key, const std::string& value) {
    tree.insert(KeyValuePair(key, value));
}

std::string TreeMap::get(const std::string& key) {
    KeyValuePair temp(key, "");
    KeyValuePair* found = tree.search(temp);
    if (found)
        return found->getValue();
    return "";  
}

void TreeMap::remove(const std::string& key) {
    tree.remove(KeyValuePair(key, ""));
}