//
// 28BYJ_48 5V Geared Stepper Motor Model
// 
// Author : Steven Knudsen
// 
// Copyright : This work is licensed under a Creative Commons Attribution 4.0 International License.
//

// Useful constants
 28BYJ_48_MotorBodyDia    = 28; // mm
 28BYJ_48_MotorBodyHeight = 19.3; // mm
 
 
 // shaft
 28BYJ_48_ShaftDia        = 5; // mm
 28BYJ_48_ShaftFlatWidth  = 3; // mm
 28BYJ_48_ShaftFlatLength = 6; // mm 
 28BYJ_48_ShaftLength     = 8; // mm
 
   // housing tab
 28BYJ_48_TabThick          =  0.85; // mm
 28BYJ_48_TabTotalWidth     = 42.0; // mm
 28BYJ_48_TabHoleSeparation = 35.0; // mm
 28BYJ_48_TabHoleDia        =  4.0; // mm

 module gearedMotor28BYJ_48() {
  $fn=50;

   // raised disk at shaft base   
   shaftBaseDia    = 9.2; // mm
   shaftBaseHeight = 1.0; // mm
   shaftBaseInset  = 1.5; // mm
   
   // shaft
   shaftFlatStart = 2; // mm above the base
   
   // housing tab
   tabDepth          =  7.0; // mm
   
   // motor body
   cylinder(r=28BYJ_48_MotorBodyDia/2, h= 28BYJ_48_MotorBodyHeight);
   
   // tabs
   translate([-28BYJ_48_TabTotalWidth/2,-tabDepth/2,28BYJ_48_MotorBodyHeight-28BYJ_48_TabThick])
   difference() {
     union() {
       // extend tab all the way across the top of the motor
       translate([tabDepth/2,0,0]) cube([28BYJ_48_TabTotalWidth-tabDepth,tabDepth,28BYJ_48_TabThick]);
       // add rounded ends
       translate([tabDepth/2,tabDepth/2,0]) cylinder(r=tabDepth/2, h=28BYJ_48_TabThick);
       translate([28BYJ_48_TabTotalWidth-tabDepth/2,tabDepth/2,0]) cylinder(r=tabDepth/2, h=28BYJ_48_TabThick);
     }
     // punch holes
     color("green") {
       translate([tabDepth/2,tabDepth/2,-1]) cylinder(r=28BYJ_48_TabHoleDia/2, h=28BYJ_48_TabThick+2);
       translate([28BYJ_48_TabTotalWidth-tabDepth/2,tabDepth/2,-1]) cylinder(r=28BYJ_48_TabHoleDia/2, h=28BYJ_48_TabThick+2);
     }
   }
   
   // shaft base and shaft
   color("brown") {
   translate([0,28BYJ_48_MotorBodyDia/2-shaftBaseDia/2-shaftBaseInset,28BYJ_48_MotorBodyHeight])
     difference() {
       union() {
         cylinder(r=shaftBaseDia/2, h=shaftBaseHeight);
         cylinder(r=28BYJ_48_ShaftDia/2, h=shaftBaseHeight+28BYJ_48_ShaftLength);
       }
       translate([28BYJ_48_ShaftFlatWidth/2,-28BYJ_48_ShaftDia/2-1,shaftBaseHeight+shaftFlatStart])
         cube([28BYJ_48_ShaftDia,28BYJ_48_ShaftDia+2,28BYJ_48_ShaftLength]);
       translate([-28BYJ_48_ShaftDia-28BYJ_48_ShaftFlatWidth/2,-28BYJ_48_ShaftDia/2-1,shaftBaseHeight+shaftFlatStart])
         cube([28BYJ_48_ShaftDia,28BYJ_48_ShaftDia+2,28BYJ_48_ShaftLength]);
     }
   }
   
   // wire housing
   housingTopWidth = 14.7; // mm
   housingHeight = 16.7; // mm
   housingDepth = 31.4 - 28BYJ_48_MotorBodyDia; // mm
   housingFlangeWidth = 17.65; // mm
   housingFlangeHeight = 12.75; // mm
   
   difference() {
     color("blue") {
       union() {
         translate([-housingTopWidth/2,-28BYJ_48_MotorBodyDia/2-housingDepth,28BYJ_48_MotorBodyHeight-housingHeight])
           cube([housingTopWidth,2*housingDepth,housingHeight]);
         translate([-housingFlangeWidth/2,-28BYJ_48_MotorBodyDia/2-housingDepth+2,28BYJ_48_MotorBodyHeight-housingHeight])
           cube([housingFlangeWidth,2*housingDepth,housingFlangeHeight]);
       }
     }
     color("black") {
       translate([-housingFlangeWidth/2-1,-28BYJ_48_MotorBodyDia/2-housingDepth-.5,28BYJ_48_MotorBodyHeight-housingHeight-1])
         rotate([0,0,45])
         cube([housingDepth,housingDepth,housingFlangeHeight+2]);
       translate([housingFlangeWidth/2-1.5,-28BYJ_48_MotorBodyDia/2-housingDepth+2,28BYJ_48_MotorBodyHeight-housingHeight-1])
         rotate([0,0,-45])
         cube([housingDepth,housingDepth,housingFlangeHeight+2]);
     }
   }
 }
 
 gearedMotor28BYJ_48();