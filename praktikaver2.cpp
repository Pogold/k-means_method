#include "CImg.h"
#include "k_means.h"
#include <iostream>
using namespace std;
using namespace cimg_library;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    const CImg<double> img("seal.bmp");
    
    int size = img.width() * img.height();
    rgb* mas = new rgb[size];
    int count = 0;
 
        for (int x = 0; x < img.width(); x++) 
        {

            for (int y = 0; y < img.height(); y++) {

                mas[count].r = img(x, y, 0, 0);
                mas[count].g = img(x, y, 0, 1);
                mas[count].b = img(x, y, 0, 2);
                count++;
            }

        }        

	K_means image_1(size, mas, 5); // кол-во пикселей, массив пикселей, кол-во кластеров
	ofstream dout;
	dout.open("Result.txt");
	dout << image_1; // запись начальных данных
	image_1.clustering(dout); // запись процесса кластеризации
    img.display("Изображение");
    
    delete[] mas;
    return 0;
}

