#ifndef uuid_guard_749f57a6_a1336058_14a62898_c4731a4a
#define uuid_guard_749f57a6_a1336058_14a62898_c4731a4a

#include <string>

namespace tul{

struct Uuid{
	Uuid();
	Uuid(const Uuid& obj);
	Uuid(unsigned long first, unsigned long second);

	bool operator ==(const Uuid& rhs) const;
	bool operator !=(const Uuid& rhs) const;

	//TODO implement the rest of the operators
	bool operator <(const Uuid& rhs) const;

	std::string serialize() const;
	bool unserialize(const std::string& str);

	unsigned long first;
	unsigned long second;
};

}

#endif // uuid_guard_749f57a6_a1336058_14a62898_c4731a4a
