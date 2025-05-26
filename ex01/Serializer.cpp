#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {}

Serializer::~Serializer() {}

Serializer	&Serializer::operator=(const Serializer &other) {}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t	res;

	return res;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data	*data = NULL;

	return data;
}
