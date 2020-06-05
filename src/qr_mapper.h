#ifndef uuid_guard_053e92d1_7a99b9fd_93c918d5_7ad01b10
#define uuid_guard_053e92d1_7a99b9fd_93c918d5_7ad01b10

#include <util/uuid.h>

#include "key.h"

namespace tul{
namespace project{
namespace on{

//map between qr code and uuids/keys

enum class Data_t{
	unknown,
	uuid,
	key
};

class Qr_mapper{
public:
	Data_t get_type() const;

	Uuid get_uuid() const;
	Key get_key() const;

	void set_data(const std::vector<unsigned char>& data);
private:
	std::vector<unsigned char> data;
};

}
}
}

#endif // uuid_guard_053e92d1_7a99b9fd_93c918d5_7ad01b10
