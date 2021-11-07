#include <png++/png.hpp>

png::rgb_pixel invert(png::rgb_pixel in){
	in.blue = 255 - in.blue;
    in.red = 255 - in.red;
    in.green = 255 - in.green;
    return in;
}


int main(int argc, char *argv[]){
	if (argc < 3){
		return 0;
	}

	png::image< png::rgb_pixel > image(argv[1]);
	for (int i = 0; i < image.get_height(); i++){
		for (int ii = 0; ii < image.get_width(); ii++){
			image[i][ii] = invert(image[i][ii]);
		}
	}
	
	image.write(argv[2]);
}