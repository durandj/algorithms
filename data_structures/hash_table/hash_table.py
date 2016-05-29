"""
Hash table implementation in Python
"""

import collections

HashTableRecord = collections.namedtuple(
    'HashTableRecord',
    ['key', 'value', 'previous', 'next'],
)

class HashTable(object):
    """
    A Python implementation of Python
    """

    CAPACITY = 512
    DIVISOR = 701

    def __init__(self):
        self._table = [None for _ in range(HashTable.CAPACITY)]
        self._size = 0

    def has_key(self, key):
        """
        Check if a key is present in the table
        """

        return self._get_record(key, raise_error=False) is not None

    def get(self, key):
        """
        Retrieve a value from the table. Raises an IndexError
        if the key is not in the table.
        """

        return self._get_record(key).value

    def get_default(self, key, default=None):
        """
        Retrieve a value from the table. Returns the default
        value if the key is not in the table.
        """

        record = self._get_record(key)

        return record.value if record is not None else default

    def set(self, key, value):
        """
        Set a value in the table. If an existing value exists
        for this key it is overwritten
        """

        key_hash = hash(key)
        new_record = HashTableRecord(
            key=key,
            value=value,
            previous=None,
            next=None,
        )

        record = self._table[key_hash]
        if record is None:
            self._table[key_hash] = new_record
            self._size += 1

            return

        while record.key != key and record.next is not None:
            record = record.next

        if record.key != key:
            record.next = new_record
            new_record.previous = record

            self._size += 1
        else:
            record.value = value

    def remove(self, key):
        """
        Removes a key/value pair from the table
        """

        key_hash = hash(key)

        record = self._table[key_hash]
        while record != None and record.key != key:
            record = record.next

        if record is None:
            raise IndexError('{} is not in the table'.format(key))

        record.previous.next = record.next
        record.next.previous = record.previous

        del record
        self._size -= 1

    def clear(self):
        """
        Empty the hash table
        """

        self._table.clear()

        self._table = [None for _ in range(self.CAPACITY)]
        self._size = 0

    def keys(self):
        """
        Return a set with all of the keys from the table
        """

        keys = set()
        for record in self._table:
            while record is not None:
                keys.add(record.key)
                record = record.next

        return keys

    def values(self):
        """
        Return a collection with all the values from the table
        """

        values = []
        for record in self._table:
            while record is not None:
                values.append(record.value)
                record = record.next

        return values

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, value):
        self.set(key, value)

    def __len__(self):
        return self._size

    def _get_record(self, key, raise_error=True):
        key_hash = hash(key)

        record = self._table[key_hash]
        while record is not None and record.key != key:
            record = record.next

        if record is None and raise_error:
            raise IndexError('{} is not in the table'.format(key))

        return record

