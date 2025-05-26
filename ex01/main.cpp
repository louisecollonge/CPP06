#include "Serializer.hpp"

int main(void) {
	Data*		data = NULL;
	uintptr_t	raw;
	
	raw = Serializer::serialize(data);
	// verifier que:
	data == Serializer::deserialize(raw);

	return 0;
}
