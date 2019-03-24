#include "imgcodecs.hpp"

using namespace cv;

int main(int argc, char **argv)
{
	int result = imread(argv[1], 199);
    return result;
}