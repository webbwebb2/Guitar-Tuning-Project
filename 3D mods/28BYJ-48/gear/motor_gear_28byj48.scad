//
//  Motor gear for 28BYJ-48 geared stepper motor
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

axle_dia = 5.0;
axle_flat = 3.0;
axle_length = 9.7;
mount_width = 4.6;
screw_dia = 3.1;

wheel_width = 7.77;

module wheel() {
	//intersection () {
	translate([-416.845, -612.92, 121.03]) 
		import("C:\\Users\\Iluva\\Desktop\\28BYJ-48\\holo_clock\\files\\motor_gear.stl");

	color("red") cylinder(r=1.66, h=7.77, $fn=100); //r=1.60 leaves air gap, 1.66 fills 
	//}
}

module axle() {
	translate([0, 0, wheel_width-(axle_length-mount_width)]) intersection () {
		cylinder(r=axle_dia/2, h=wheel_width, $fn=100);
		translate([-axle_flat/2, -axle_dia, 0]) cube([axle_flat, 2*axle_dia, wheel_width]);
	}
	cylinder(r=screw_dia/2, h=wheel_width, $fn=100);
}

difference () {
	wheel();
	axle();
}