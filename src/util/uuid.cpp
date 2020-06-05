#include "uuid.h"

#include <limits>
#include <random>

namespace tul{

Uuid::Uuid(){
	std::random_device rand;
	std::mt19937_64 gen(rand());
	std::uniform_int_distribution<unsigned long> distrib(
		0,
		std::numeric_limits<unsigned long>::max()
	);

	first = distrib(gen);
	second = distrib(gen);
}

Uuid::Uuid(const Uuid& obj)
		:first(obj.first), second(obj.second){
}

Uuid::Uuid(unsigned long first_, unsigned long second_)
		:first(first_), second(second_){
}

bool Uuid::operator ==(const Uuid& rhs) const{
	return first == rhs.first && second == rhs.second;
}

bool Uuid::operator !=(const Uuid& rhs) const{
	return !(*this == rhs);
}

bool Uuid::operator <(const Uuid& rhs) const{
	return first < rhs.first ? true : (first == rhs.first && second < rhs.second);
}

std::string Uuid::serialize() const{
	//val should be in [0, 16)
	auto to_hex = [](int val){
		return val < 10 ? '0' + val : 'a' + (val - 10);
	};

	//MAGIC 32 hex chars and 3 underscores
	std::string ret(32 + 3, '_');
	int mask = 0xf;

	//use the mask to extract each hex char
	//MAGIC store at i + i/8 because '_' occurs every 8 chars
	for (int i = 0; i < 16; ++i){
		ret[i + i/8] = to_hex((first >> 4*i) & mask);
	}
	for (int i = 16; i < 32; ++i){
		ret[i + i/8] = to_hex((second >> 4*i) & mask);
	}

	return ret;
}

bool Uuid::unserialize(const std::string& str){
	//val should match [0-9a-f]
	auto to_int = [](char val) -> unsigned char{
		return val < 'a' ? val - '0' : (val - 'a') + 10;
	};

	//MAGIC 32 hex chars and 3 underscores
	if (str.size() != 32 + 3){
		return false;
	}

	first = second = 0;

	for (std::size_t i = 0; i < 32; ++i){
		//MAGIC '_' per 8 chars
		char hex = str[i + i/8];
		if (hex < '0' || (hex > '9' && hex < 'a') || hex > 'f'){
			return false;
		}

		//MAGIC first 16 chars go to first
		if (i < 16){
			first <<= 4;
			first |= to_int(hex);
		}
		else{
			second <<= 4;
			second |= to_int(hex);
		}
	}
	return true;
}

}
