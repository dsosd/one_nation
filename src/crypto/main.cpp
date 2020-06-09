#include "main.h"

#include <sodium/sodium.h>

namespace tul{
namespace crypto{

bool init(){
	//MAGIC spec says otherwise sodium is not safe to use
	return sodium_init() >= 0;
}

}
}
