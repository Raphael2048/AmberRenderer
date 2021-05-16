
#include <iostream>
#include <fstream>
#include "amber.h"

using namespace std;
int main(int argc, char** argv)
{
    ofstream fout("1.ppm");
    int nx = 100, ny = 100;
    fout << "P3\n" << nx << " " << ny << "\n255\n";
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            float r = float(i) / nx;
            float g = float(j) / ny;
            float b = 0.2;
            int ir = int(r * 255.99);
            int ig = int(g * 255.99);
            int ib = int(b * 255.99);
            
            fout << ir << " " << ig << " " << ib << "\n";
        }
    }
    fout.close();
}
