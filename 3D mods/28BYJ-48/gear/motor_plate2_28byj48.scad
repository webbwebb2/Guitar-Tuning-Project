//
//  Motor mount for 28BYJ-48 geared stepper motor
//
//  Based on http://www.thingiverse.com/thing:570797
//  "holo clock" by ekaggrat, Nov 30 2014
//
//  The 28BYJ-48 has a step angle of 5.625 degrees and 1/64 gearing
//  It is for 5VDC
//
//  Note: manual centering, but accurate to 0.01mm
//  Note: In OpenSCAD, use F6 to evaluate, F5 will not really work
//


module mount() {
	//intersection () {
	translate([303.25, -423.52, 91.01]) 
		import("C:\\Users\\Iluva\\Desktop\\28BYJ-48\\holo_clock\\files\\motor_plate_28byj48.stl");

	    color("red") cylinder(r=3.42, h=5, $fn=100); //r=3.39 leaves air gap, 3.41 fills 
	//}
}

module axle() {
	cylinder(r=9.25/2, h=1.5, $fn=100); // motor collar measures 9.14
	cylinder(r=6.0/2, h=10, $fn=100); // motor axle is 5.0
}

difference () {
	mount();
	axle();
}