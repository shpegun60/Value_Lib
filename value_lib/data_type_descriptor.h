#ifndef DATA_TYPE_DESCRIPTOR_H
#define DATA_TYPE_DESCRIPTOR_H

#include <cstdint>
#include <type_traits>

class DataTypeDescriptor {
public:
    enum class DataType : uint8_t {
        VOID_TYPE,
        UINT8_TYPE,
        UINT16_TYPE,
        UINT32_TYPE,
        UINT64_TYPE,
        CHAR_TYPE,
        INT8_TYPE,
        INT16_TYPE,
        INT32_TYPE,
        INT64_TYPE,
        FLOAT_TYPE,
        DOUBLE_TYPE,
        LONG_DOUBLE_TYPE,
        BOOL_TYPE,
        UINT24_TYPE,
        INT24_TYPE,
        REG_TYPE,
        SREG_TYPE,
        TYPE_ARRAY_LENGTH
    };

    static const size_t TypeSizeArray[static_cast<size_t>(DataType::TYPE_ARRAY_LENGTH)];
private:
    DataType type = DataType::VOID_TYPE;
    size_t size = 0;
    size_t count = 0;
    uint8_t* data = nullptr;

public:

    DataTypeDescriptor(const DataType _type) : type(_type), count(1), data(nullptr) {
        if (_type < DataType::TYPE_ARRAY_LENGTH) {
            size = TypeSizeArray[static_cast<size_t>(_type)];
        }
    }

    DataTypeDescriptor(const DataType _type, const size_t _count) : type(_type), count(_count), data(nullptr) {
        if (_type < DataType::TYPE_ARRAY_LENGTH) {
            size = TypeSizeArray[static_cast<size_t>(_type)] * _count;
        }
    }

    DataTypeDescriptor(const DataType _type, const size_t _size, const size_t _count, uint8_t* const _data)
        : type(_type), size(_size), count(_count), data(_data) {}

    // ~DataTypeDescription() {
    //     //delete[] data;
    // }

    DataType getType() const {
        return type;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCount() const {
        return count;
    }

    uint8_t* getData() const {
        return data;
    }

protected: //---------------------------------------------------------------------------------------------
    void setData(uint8_t* const _data) {
        data = _data;
    }

    // templte function for getting DataType on compile-time
    template<class T>
    static DataType getDataType() {
        if constexpr (std::is_same<T, void>::value) {
            return DataType::VOID_TYPE;
        } else if constexpr (std::is_same<T, uint8_t>::value) {
            return DataType::UINT8_TYPE;
        } else if constexpr (std::is_same<T, uint16_t>::value) {
            return DataType::UINT16_TYPE;
        } else if constexpr (std::is_same<T, uint32_t>::value) {
            return DataType::UINT32_TYPE;
        } else if constexpr (std::is_same<T, uint64_t>::value) {
            return DataType::UINT64_TYPE;
        } else if constexpr (std::is_same<T, char>::value) {
            return DataType::CHAR_TYPE;
        } else if constexpr (std::is_same<T, int8_t>::value) {
            return DataType::INT8_TYPE;
        } else if constexpr (std::is_same<T, int16_t>::value) {
            return DataType::INT16_TYPE;
        } else if constexpr (std::is_same<T, int32_t>::value) {
            return DataType::INT32_TYPE;
        } else if constexpr (std::is_same<T, int64_t>::value) {
            return DataType::INT64_TYPE;
        } else if constexpr (std::is_same<T, float>::value) {
            return DataType::FLOAT_TYPE;
        } else if constexpr (std::is_same<T, double>::value) {
            return DataType::DOUBLE_TYPE;
        } else if constexpr (std::is_same<T, long double>::value) {
            return DataType::LONG_DOUBLE_TYPE;
        } else if constexpr (std::is_same<T, bool>::value) {
            return DataType::BOOL_TYPE;
        } else {
            return DataType::VOID_TYPE;
        }
    }
};

#endif // DATA_TYPE_DESCRIPTOR_H
