#ifndef TREEMAP_H
#define TREEMAP_H

#include "KeyValuePair.h"
#include "SplayTree.h"
#include <string>

class TreeMap {
private:
    SplayTree<KeyValuePair> tree;

public:
    void insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    void remove(const std::string& key);
};

#endif