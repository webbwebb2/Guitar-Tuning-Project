use <gear.scad>
use <28BYJ_48.scad>

kegelradpaar(modul=1, tooth_rad=30, tooth_ritzel=11, achsenwinkel=90, zahnbreite=5, bore=4, eingriffswinkel = 20, schraegungswinkel=0, zusammen_gebaut=1);

translate([30, 0, 0])
    cone_wheel_2(modul=1, tooth_rad=30, tooth_ritzel=11, achsenwinkel=90, zahnbreite=5, bore=4, eingriffswinkel = 20, schraegungswinkel=0, zusammen_gebaut=1);
    
translate([0, 40, 0])
    cone_wheel_1(modul=1, tooth_rad=30, tooth_ritzel=11, achsenwinkel=90, zahnbreite=5, bore=4, eingriffswinkel = 20, schraegungswinkel=0, zusammen_gebaut=1);

translate([-40, 0, 0])
    gearedMotor28BYJ_48();

module cone_wheel_1(modul, tooth_rad, tooth_ritzel, achsenwinkel=90, zahnbreite, bore_rad, bore_ritzel, eingriffswinkel=20, schraegungswinkel=0, zusammen_gebaut=1) {
    
    // Dimensions-Berechnungen
	r_rad = modul*tooth_rad/2;							// Teilkegelradius des Rads
	delta_rad = atan(sin(achsenwinkel)/(tooth_ritzel/tooth_rad+cos(achsenwinkel)));	// Kegelwinkel des Rads
	delta_ritzel = atan(sin(achsenwinkel)/(tooth_rad/tooth_ritzel+cos(achsenwinkel)));// Kegelwingel des Ritzels
	rg = r_rad/sin(delta_rad);								// Radius der Großkugel
	c = modul / 6;											// Kopfspiel
	df_ritzel = 4*pi*rg*delta_ritzel/360 - 2 * (modul + c);	// Fußkegeldurchmesser auf der Großkugel 
	rf_ritzel = df_ritzel / 2;								// Fußkegelradius auf der Großkugel
	delta_f_ritzel = rf_ritzel/(2*pi*rg) * 360;				// Kopfkegelwinkel
	rkf_ritzel = rg*sin(delta_f_ritzel);					// Radius des Kegelfußes
	height_f_ritzel = rg*cos(delta_f_ritzel);				// Höhe des Kegels vom Fußkegel
	
	echo("Kegelwinkel Rad = ", delta_rad);
	echo("Kegelwinkel Ritzel = ", delta_ritzel);
 
	df_rad = 4*pi*rg*delta_rad/360 - 2 * (modul + c);		// Fußkegeldurchmesser auf der Großkugel 
	rf_rad = df_rad / 2;									// Fußkegelradius auf der Großkugel
	delta_f_rad = rf_rad/(2*pi*rg) * 360;					// Kopfkegelwinkel
	rkf_rad = rg*sin(delta_f_rad);							// Radius des Kegelfußes
	height_f_rad = rg*cos(delta_f_rad);						// Höhe des Kegels vom Fußkegel

	echo("Höhe Rad = ", height_f_rad);
	echo("Höhe Ritzel = ", height_f_ritzel);
	
	drehen = istgerade(tooth_ritzel);
    
    kegelrad(modul, tooth_rad, delta_rad, zahnbreite, bore_rad, eingriffswinkel, schraegungswinkel);
}

module cone_wheel_2(modul, tooth_rad, tooth_ritzel, achsenwinkel=90, zahnbreite, bore_rad, bore_ritzel, eingriffswinkel=20, schraegungswinkel=0, zusammen_gebaut=1) {
    
    // Dimensions-Berechnungen
	r_rad = modul*tooth_rad/2;							// Teilkegelradius des Rads
	delta_rad = atan(sin(achsenwinkel)/(tooth_ritzel/tooth_rad+cos(achsenwinkel)));	// Kegelwinkel des Rads
	delta_ritzel = atan(sin(achsenwinkel)/(tooth_rad/tooth_ritzel+cos(achsenwinkel)));// Kegelwingel des Ritzels
	rg = r_rad/sin(delta_rad);								// Radius der Großkugel
	c = modul / 6;											// Kopfspiel
	df_ritzel = 4*pi*rg*delta_ritzel/360 - 2 * (modul + c);	// Fußkegeldurchmesser auf der Großkugel 
	rf_ritzel = df_ritzel / 2;								// Fußkegelradius auf der Großkugel
	delta_f_ritzel = rf_ritzel/(2*pi*rg) * 360;				// Kopfkegelwinkel
	rkf_ritzel = rg*sin(delta_f_ritzel);					// Radius des Kegelfußes
	height_f_ritzel = rg*cos(delta_f_ritzel);				// Höhe des Kegels vom Fußkegel
	
	echo("Kegelwinkel Rad = ", delta_rad);
	echo("Kegelwinkel Ritzel = ", delta_ritzel);
 
	df_rad = 4*pi*rg*delta_rad/360 - 2 * (modul + c);		// Fußkegeldurchmesser auf der Großkugel 
	rf_rad = df_rad / 2;									// Fußkegelradius auf der Großkugel
	delta_f_rad = rf_rad/(2*pi*rg) * 360;					// Kopfkegelwinkel
	rkf_rad = rg*sin(delta_f_rad);							// Radius des Kegelfußes
	height_f_rad = rg*cos(delta_f_rad);						// Höhe des Kegels vom Fußkegel

	echo("Höhe Rad = ", height_f_rad);
	echo("Höhe Ritzel = ", height_f_ritzel);
	
	drehen = istgerade(tooth_ritzel);
	
	// Ritzel
    kegelrad(modul, tooth_ritzel, delta_ritzel, zahnbreite, 5, eingriffswinkel, -schraegungswinkel);
}