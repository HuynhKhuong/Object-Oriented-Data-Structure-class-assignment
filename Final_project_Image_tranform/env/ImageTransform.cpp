#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name: Huynh Khuong
Email: khuong.huynhdiendientu@hcmut.edu.vn

(...end multi-line comment.)
******************** */
#define MIN_COMMON  0.0

#define HUE_MAX   360.0
#define HUE_MIN   MIN_COMMON

#define SATURATION_MAX  1.0
#define SATURATION_MIN  MIN_COMMON

#define LUMINANCE_MAX   1.0
#define LUMINANCE_MIN   MIN_COMMON

#define ALPHA_MAX   1.0
#define ALPHA_MIN   MIN_COMMON

#define HUE_ORANGE  11.0
#define HUE_BLUE    216.0

#define CIRCLE_ROUND  360.0
using uiuc::PNG;
using uiuc::HSLAPixel;

//Create a boundary check function to check whether the hue value is in the range or not 
static double hue_boundaries_check(const HSLAPixel& pixel) {
  if(pixel.h > HUE_MAX) return (pixel.h - HUE_MAX);
  if(pixel.h < HUE_MIN) return HUE_MIN;
  return pixel.h;
}

static double gap_check(const double threshold, const double input){
  //gap check is done by checking 2 cases: 
  //case 1: gap check between input and the threshold IN THE SAME CYCLE
  //case 2: gap check between input and the threshold IN THE NEXT/PAST CYCLE
  //we check NEXT CYCLE when input > threshold
  //we check PAST CYCLE when input < threshold
  double result = 0;
  double gap_in_same_cycle = 0; 
  double gap_in_diff_cycle = 0;
  if(input > threshold){
    gap_in_same_cycle = input - threshold;
    gap_in_diff_cycle = (CIRCLE_ROUND - input) + threshold;
  }
  else{
    gap_in_same_cycle = threshold - input;
    gap_in_diff_cycle = input + (CIRCLE_ROUND - threshold);
  }
  return (gap_in_same_cycle > gap_in_diff_cycle)?gap_in_diff_cycle:gap_in_same_cycle ;
}

static bool hue_orange_blue_range(const HSLAPixel& pixel){
  bool close_to_orange = false;
  const double pixel_h = hue_boundaries_check(pixel);
  const double blue_range = gap_check(HUE_BLUE, pixel_h);
  const double orange_range = gap_check(HUE_ORANGE, pixel_h);
  
  if(blue_range > orange_range) close_to_orange = true;
  else close_to_orange = false;


  return close_to_orange;
}

//functions calculating Euclide distance

static unsigned int Euclide_distance(int current_x,int current_y, int center_x, int center_y){
  int gap_x = current_x - center_x;  //subtract result won't exceed the limit of a member itself
  int gap_y = current_y - center_y;

  unsigned int Euclide_distance_sq = (gap_x * gap_x)+(gap_y*gap_y);
  return sqrt(Euclide_distance_sq);
}


/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a reference to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly. No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
  unsigned int image_height = image.height(); //x max
  unsigned int image_width = image.width(); //y max
  unsigned int euclide_dis = 0;
  float remaining_brightness = 0;
  for(unsigned int y = 0; y < image_height; y++){
    for(unsigned int x = 0; x < image_width; x ++){
      euclide_dis = Euclide_distance(x, y, centerX, centerY);
      remaining_brightness = ((0.5*euclide_dis/100) > 0.8)?(0.2):(1 - 0.5*euclide_dis/100);
      //remodify brightness of pixel, add boundary check: the l loss won't exceed 80%
      image.getPixel(x,y).l = image.getPixel(x,y).l*remaining_brightness;
    }
  }

  return image;
  
}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
  //Iterate via all pixels of image
  unsigned int image_height = image.height(); //x max
  unsigned int image_width = image.width(); //y max

  bool close_to_orange = false;
  for(unsigned int y = 0; y < image_height; y++){
    for(unsigned int x = 0; x < image_width; x ++){
      close_to_orange = hue_orange_blue_range(image.getPixel(x, y));
      if(close_to_orange) image.getPixel(x, y).h = HUE_ORANGE;
      else image.getPixel(x, y).h = HUE_BLUE;
    }
  }
  return image;
}

 

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
  //Assuming the two image are placed at the upper-left corner overlapping at the same coordinates
  unsigned int first_image_height = firstImage.height(); //x max
  unsigned int first_image_width = firstImage.width(); //y max
  
  unsigned int second_image_height = secondImage.height(); //x max
  unsigned int second_image_width = secondImage.width(); //y max
  double target_l = 0;
  //Second image are overlapping first image, check range inside the second image only
  for(unsigned int y = 0; y < first_image_height; y++){
    for(unsigned int x = 0; x < first_image_width; x ++){
      //check out range condition
      if(y >= second_image_height) continue;
      if(x >= second_image_width) continue;
      //check mark condition
      if(secondImage.getPixel(x,y).l < 1) continue;

      target_l = firstImage.getPixel(x,y).l + 0.2; 
      firstImage.getPixel(x,y).l = (target_l  > 1)?1:(target_l);
    }
  }
  return firstImage;
}
