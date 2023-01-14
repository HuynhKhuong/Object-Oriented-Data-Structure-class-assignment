/**
 * @file HSLAPixel.h
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#pragma once

#include <iostream>
#include <sstream>

namespace uiuc {
  /*
    Test 1: HSLAPixel declaration
    h, s, l ,a are public members (I would modify this scope later), they all have range.
  */
  class HSLAPixel{
    public: 
      HSLAPixel():h(0),s(0.0),l(0.0),a(0.0){}; //default value 
      double h; //hue value
      double s;
      double l;
      double a; 
  };

}
