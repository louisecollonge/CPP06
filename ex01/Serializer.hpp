#pragma once

#include <iostream>
#include <string>
#include <stdint.h> // pour uintptr_t
#include "data.h"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &other);

	public:
		~Serializer();
		Serializer &operator=(const Serializer &other);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
