//Copyright 2012 Igor Campos
//
//This file is part of CustomStepper.
//
//CustomStepper is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//CustomStepper is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with CustomStepper.  If not, see <http://www.gnu.org/licenses/>.

#include <CustomStepper.h>

//Full constructor, just the first 4 parameters are necessary, they are the pins connected to the motor,
//the others are optional, and default to the following below
//the 5th paramater is the steps sequence, where the 1st element of the array is the number of steps
//it can have a maximum of 8 steps
//the 6th parameter is the SPR (Steps Per Rotation)
//the 7th parameter is the RPM
//the 8th parameter is the rotation orientation
//CustomStepper stepper(10, 11, 12, 13, (byte[]){8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001}, 4075.7728395, 12, CW);
CustomStepper stepper(10, 11, 12, 13);
//boolean rotate1 = true;
//boolean rotatedeg = false;
//boolean crotate = false;

int dir = CCW;
int i = 0;

void setup()
{
  //sets the RPM
  stepper.setRPM(12);
  //sets the Steps Per Rotation, in this case it is 64 * the 283712/4455 annoying ger ratio
  //for my motor (it works with float to be able to deal with these non-integer gear ratios)
  stepper.setSPR(4075.7728395);
  stepper.rotate(0);
}

void loop()
{
  
  stepper.run();
}
