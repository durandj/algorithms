#ifndef ALGORITHMS_DATA_STRUCTURES_CHAINED_HASH_TABLE_HPP_
#define ALGORITHMS_DATA_STRUCTURES_CHAINED_HASH_TABLE_HPP_

#include <cassert>
#include <cstddef>
#include <cstdint>

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>

namespace algorithms {
namespace data_structures {

template <std::size_t modulo, typename KeyType>
std::size_t division_hash(const KeyType &key) {
    return key % modulo;
}

class HashTableException : public std::exception {
};

template <typename KeyType, typename ValueType>
class ChainedHashTable {
private:
    static const std::size_t kTableSize = 701;

    struct HashTableRecord {
        HashTableRecord *head;
        HashTableRecord *tail;
        const KeyType key;
        ValueType value;
    };

    HashTableRecord *hashTable_[kTableSize];
    std::size_t size_;

    const std::size_t get_hash_index(const KeyType &key) const {
        return division_hash<kTableSize>(key);
    }

    HashTableRecord *get_record(const KeyType &key) const {
        auto index = get_hash_index(key);

        auto record = hashTable_[index];
        while (record != nullptr && record->key != key) {
            record = record->tail;
        }

        return record;
    }

public:
    ChainedHashTable(void) noexcept : size_(0) {
        std::fill_n(hashTable_, kTableSize, nullptr);
    }

    ~ChainedHashTable(void) {
        if (size_ == 0) {
            return;
        }

        for (auto i = 0ul; i < kTableSize; i++) {
            auto record = hashTable_[i];

            while (record != nullptr) {
                auto next = record->tail;

                delete record;

                record = next;
            }
        }
    }

    void set(const KeyType &key, const ValueType &value) {
        auto index = get_hash_index(key);

        if (hashTable_[index] == nullptr) {
            auto record = new HashTableRecord{nullptr, nullptr, key, value};

            hashTable_[index] = record;

            size_++;
        }
        else {
            HashTableRecord *record = hashTable_[index];
            while (record->tail != nullptr && record->key != key) {
                record = record->tail;
            }

            if (record->key == key) {
                record->value = value;
            }
            else {
                auto new_record = new HashTableRecord{record, nullptr, key, value};
                record->tail = new_record;
                size_++;
            }
        }
    }

    bool containsKey(const KeyType &key) const {
        return get_record(key) != nullptr;
    }

    const ValueType &get(const KeyType &key) const {
        auto record = get_record(key);

        if (record == nullptr) {
            throw HashTableException();
        }

        return record->value;
    }

    const ValueType &remove(const KeyType &key) {
        auto record = get_record(key);

        if (record == nullptr) {
            throw HashTableException();
        }

        if (record->head == nullptr) {
            hashTable_[get_hash_index(key)] = record->tail;
        }
        else if (record->tail == nullptr) {
            record->head->tail = nullptr;
        }
        else {
            record->head->tail = record->tail;
            record->tail->head = record->head;
        }

        size_--;

        const ValueType &value = record->value;
        delete record;

        return value;
    }

    const std::size_t size(void) const {
        return size_;
    }
};

} // namespace data_structures
} // namespace algorithms

int main(void) {
    using namespace algorithms::data_structures;

    ChainedHashTable<std::uint64_t, std::string> hash_table;

    std::cout << "Checking default hash table size" << std::endl;
    assert(hash_table.size() == 0);

    std::cout << "Adding values to hash table" << std::endl;
    hash_table.set(1716, "The best team ever");
    hash_table.set(9001, "Over 9000!");
    hash_table.set(1, "The loneliest number");
    hash_table.set(100000, "A really, really big number");

    std::cout << "Check that the size matches" << std::endl;
    assert(hash_table.size() == 4);

    std::cout << "Check that we can retrieve all the values" << std::endl;
    assert(hash_table.get(1716) == "The best team ever");
    assert(hash_table.get(9001) == "Over 9000!");
    assert(hash_table.get(1) == "The loneliest number");
    assert(hash_table.get(100000) == "A really, really big number");

    std::cout << "Check that we can't retrieve non-existant keys" << std::endl;
    try {
        hash_table.get(1717);
        std::cout << "NOOOOO!" << std::endl;

        assert(false);
    }
    catch (HashTableException ex) {
    }

    std::cout << "Check that we can replace an existing value" << std::endl;
    hash_table.set(100000, "A pretty big number");

    std::cout << "Check that the size did not increase" << std::endl;
    assert(hash_table.size());

    std::cout << "Check that the value was updated" << std::endl;
    assert(hash_table.get(100000) == "A pretty big number");

    std::cout << "Check that we handle collisions" << std::endl;
    constexpr std::uint64_t collision_key = 1716 + 701;
    hash_table.set(collision_key, "Another team");

    assert(hash_table.size() == 5);
    assert(hash_table.get(collision_key) == "Another team");

    std::cout << "Check that we can find if a key exists" << std::endl;
    assert(hash_table.containsKey(1716));
    assert(!hash_table.containsKey(1717));

    assert(hash_table.containsKey(collision_key));

    std::cout << "Check that we can remove a key/value pairs" << std::endl;
    hash_table.remove(100000);
    assert(hash_table.size() == 4);

    hash_table.remove(collision_key);
    assert(hash_table.size() == 3);

    std::cout << "Check that we can't remove a non-existant key/value pair"
        << std::endl;

    try {
        hash_table.remove(1717);
        assert(false);
    }
    catch (HashTableException ex) {
    }

    std::cout << "Much success!" << std::endl;
}

#endif
