#include "Serializer.hpp"

#define PINK	 	"\033[0;35m"
#define ORANGE		"\033[38;5;214m"
#define RESET		"\033[0m"

int main(void) {
	Data		original;
	uintptr_t	raw;
	
	original._name = "Bimo";
	original._species = "rabbit";
	original._age = 5;
	original._cute = true;

	std::cout << ORANGE << "Original data:\n"
			  << "\tname:\t\t" << original._name
			  << "\n\tspecies:\t" << original._species
			  << "\n\tage:\t\t" << original._age << " years"
			  << "\n\tis it cute?\t" << (original._cute? "yes" : "no")
			  << RESET << std::endl << std::endl;
	
	raw = Serializer::serialize(&original);
	
	Data	*result;
	result = Serializer::deserialize(raw);
	
	std::cout << PINK << "Deserialized data:\n"
			  << "\tname:\t\t" << result->_name
			  << "\n\tspecies:\t" << result->_species
			  << "\n\tage:\t\t" << result->_age << " years"
			  << "\n\tis it cute?\t" << (result->_cute? "yes" : "no")
			  << RESET << std::endl;

	return 0;
}
