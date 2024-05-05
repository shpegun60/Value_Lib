#ifndef VALUE_BASE_H
#define VALUE_BASE_H

#include "data_type_descriptor.h"

template<class T>
class ValueBase : public DataTypeDescriptor {
public:
    ValueBase() : DataTypeDescriptor(getDataType<T>(), sizeof(T), 1, reinterpret_cast<uint8_t*>(&value)) {
        value = T(0);
    }

    T getValue() const {
        return value;
    }

    void setValue(const T _value) {
        value = _value;
    }

    T value;
};
#endif // VALUE_BASE_H
