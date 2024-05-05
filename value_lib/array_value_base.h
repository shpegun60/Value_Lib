#include "data_type_descriptor.h"


template<typename T, size_t N>
class ArrayValueBase : public DataTypeDescriptor {
public:
    ArrayValueBase() : DataTypeDescriptor(getDataType<T>(), sizeof(T), N, reinterpret_cast<uint8_t*>(&values[0])) {
        for (size_t i = 0; i < N; ++i) {
            values[i] = T(0);
        }
    }

    T getValue(const size_t index) const {
        if (index < N) {
            return values[index];
        } else {
            // ERROR: Index out of range
            return T();
        }
    }

    void setValue(const size_t index, const T value) {
        if (index < N) {
            values[index] = value;
        } else {
            // ERROR: Index out of range
        }
    }

    T values[N];
};
