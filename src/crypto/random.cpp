#include "random.h"

#include <exception>

#include <sodium/sodium.h>

#include "main.h"

namespace tul{
namespace crypto{

std::vector<unsigned char> rand(std::size_t size){
	if (!init()){
		throw std::exception();
	}

	std::vector<unsigned char> ret;
	ret.resize(size);

	for (auto& it: ret){
		it = randombytes_random();
	}
	return ret;
}

}
}
