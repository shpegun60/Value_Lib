#include "data_type_descriptor.h"

const size_t DataTypeDescriptor::TypeSizeArray[] = {
    0,
    sizeof(uint8_t),
    sizeof(uint16_t),
    sizeof(uint32_t),
    sizeof(uint64_t),
    sizeof(char),
    sizeof(int8_t),
    sizeof(int16_t),
    sizeof(int32_t),
    sizeof(int64_t),
    sizeof(float),
    sizeof(double),
    sizeof(long double),
    sizeof(bool),
    3,
    3,
    sizeof(uint32_t),
    sizeof(uint32_t),
};
