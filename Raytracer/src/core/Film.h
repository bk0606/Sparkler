#pragma once

#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <FreeImage.h>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace glm;
using namespace std;

namespace raytracer 
{
	typedef vec3 Color;

	class Film {
	private:
		int _width, _height;
		FIBITMAP* _imageBitmap;
		FIBITMAP* loadedImg;

	public:
		void                commitFragment(int x, int y, Color color);

		void                writeToImage(const char* pngImgPathAndName);

							Film(int width, int height, short bitsPerPixel = 24);
							~Film();

							Film(const Film&) = delete;
							Film& operator = (const Film&) = delete;
	};

}