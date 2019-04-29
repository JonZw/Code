#pragma once

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <algorithm>

void save_image(const char* filename, const float* data, int w, int h) {
  unsigned char* tmp = new unsigned char[h*w];
  for(int i = 0; i < h*w; ++i) {
    tmp[i] = std::max(std::min(data[i]*255.0, 255.0), 0.0);
  }
  stbi_write_png(filename, w, h, 1, tmp, w);
  delete tmp;
}
