#include <png++/png.hpp>

png::rgb_pixel to_rgb(png::rgb_pixel in){
    png::rgb_pixel rValue;
    long long r = ((long long)(66 * long(in.red) + 129 * long(in.green) + 25 * long(in.blue) + 128));
    r >>= 8;
    r += 16;
    long long g = ((long long)(-38 * long(in.red) -74 * long(in.green) + 112 * long(in.blue) + 128)); 
    g >>= 8;
    g += 128;
    long long b = ((long long)(112 * long(in.red) -94 * long(in.green) -18 * long(in.blue) + 128)); 
    b >>= 8;
    b += 128;
    rValue.red = r;
    rValue.green = g;
    rValue.blue = b;
    return rValue;
}


int main(int argc, char *argv[]){
    if (argc < 3){
        return 0;
    }

    png::image< png::rgb_pixel > image(argv[1]);
    for (int i = 0; i < image.get_height(); i++){
        for (int ii = 0; ii < image.get_width(); ii++){
            image[i][ii] = to_rgb(image[i][ii]);
        }
    }
    
    image.write(argv[2]);
}