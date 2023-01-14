#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name:
Email:

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

  return firstImage;
}
