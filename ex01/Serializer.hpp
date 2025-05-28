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

/* 
Uintptr_t :
Entier non signe (que positif) concu pour contenir n'importe quelle adresse memoire
sans perte d'information (void*, data*, etc).

Reinterpret_cast : 
Convertir des pointeurs donc des blocs memoire (= "bas niveau")
Dangereux a manipuler
*/
