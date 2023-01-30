#include "Record.h"
#include "defs.h"

/*
    Class       : Map
    Description : Stores a collection of keys and a collection of values where each
                  value corresponds to one key, and each value is itself a collection of data record pointers.
*/
template <class T>
class Map {
   public:
    void add(T, Record*);
    int getSize() const;
    vector<T>& getKeys();

    /*
        Function: operator[]
        Purpose : An overloaded subscript operator, that takes a type <T> as parameter, 
                  searches the keys collection to find the key matching the parameter, 
                  and returns a reference to the element of the values collection corresponding to that key
    */
    vector<Record*>& operator[](T);

   private:
    int retrieveKeyIndex(T) const;
    vector<T> keys;
    vector<vector<Record*>> values;
};

template <class T>
void Map<T>::add(T key, Record* rec) {
    for (int i = 0; i < keys.size(); ++i) {
        if (key == keys.at(i)) {
            values[i].push_back(rec);
            return;
        }
    }
    keys.push_back(key);
    vector<Record*> newCol;
    newCol.push_back(rec);
    values.push_back(newCol);
}

template <class T>
int Map<T>::getSize() const { return keys.size(); }

template <class T>
vector<T>& Map<T>::getKeys() { return keys; }

template <class T>
vector<Record*>& Map<T>::operator[](T key) {
    int index;

    try {
        index = retrieveKeyIndex(key);
    } catch (string err) {
        throw err;
    }

    return values[index];
}

template <class T>
int Map<T>::retrieveKeyIndex(T key) const {
    bool foundKey = false;
    int foundIndex = -1;
    for (int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            foundKey = true;
            foundIndex = i;
            break;
        }
    }

    if (!foundKey) {
        throw((string) "KEY NOT FOUND");
    }
    return foundIndex;
}