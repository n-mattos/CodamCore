#include "Serializer.hpp"

// Changes pointer to uintptr_t
// Makes it possible to store the pointer in an integer type
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Changes uintptr_t back to pointer
Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
