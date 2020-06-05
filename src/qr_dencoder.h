#ifndef uuid_guard_5876fed7_41712b48_c5d4fe95_f764a81f
#define uuid_guard_5876fed7_41712b48_c5d4fe95_f764a81f

#include <vector>

#include "image.h"

namespace tul{
namespace project{
namespace on{

//encode between qr code data and image(s)

class Qr_dencoder{
public:
	std::vector<Image> encode_image(int index);
	bool decode_image(std::vector<Image> image);
	bool image_decoded() const;

	//TODO check for data capacity limitations. qr code quality should be M/Q or above
	bool set_data(const std::vector<unsigned char>& data_);
	std::vector<unsigned char> get_data() const;
private:
	//TODO support multi code processing up to 8
	//per qr code generated
	//3 bits for image index
	//3 bits for max index

	//TODO get an optional here or set a bool flag in Image
	std::vector<Image> images;
	std::vector<unsigned char> data;
};

}
}
}

#endif // uuid_guard_5876fed7_41712b48_c5d4fe95_f764a81f
