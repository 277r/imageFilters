#include <png++/png.hpp>

png::rgb_pixel to_yuv(png::rgb_pixel in){
	png::rgb_pixel rValue;
	rValue.red = long(0.299 * long(in.red) + 0.587 * long(in.green) + 0.114 * long(in.blue)) & 255;
	rValue.green = long(-0.147 * long(in.red) - 0.289 * long(in.green) + 0.436 * long(in.blue)) & 255;
	rValue.blue = long(0.651 * long(in.red) - 0.515 * long(in.green) - 0.100 * long(in.blue)) & 255;
	return rValue;
}


int main(int argc, char *argv[]){
	if (argc < 3){
		return 0;
	}

	png::image< png::rgb_pixel > image(argv[1]);
	for (int i = 0; i < image.get_height(); i++){
		for (int ii = 0; ii < image.get_width(); ii++){
			image[i][ii] = to_yuv(image[i][ii]);
		}
	}
	
	image.write(argv[2]);
}