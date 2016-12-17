$fn = 96;

//stirnrad(1, 10, 10, 5, 20, 5);
//pfeilrad(1, 10, 10, 5, 20, 20);
//hohlrad(1, 10, 10, 5, 20, 0);
//pfeilhohlrad(1, 10, 10, 5, 20, 0);
//planetengetriebe(1, 2, 40, 10, 2, 5, 20, 0);
//kegelrad(1, 20, 20, 5, 5);
//pfeilkegelrad(1, 10, 20, 5, 5);
//kegelradpaar(1, 10, 10, 10, 5);

/* Bibliothek für Evolventen-Zahnräder

Enthält die Module
1. stirnrad(modul, tooth, height, bore, eingriffswinkel = 20, schraegungswinkel = 0)
1. pfeilrad(modul, tooth, height, bore, eingriffswinkel = 20, schraegungswinkel = 0)
3. hohlrad(modul, tooth, height, randbreite, eingriffswinkel = 20, schraegungswinkel = 0
4. pfeilhohlrad(modul, tooth, height, randbreite, eingriffswinkel = 20, schraegungswinkel = 0)
5. planetengetriebe(modul, tooth_sonne, tooth_planet, height, randbreite, bore, eingriffswinkel=20, schraegungswinkel=0)
6. kegelrad(modul, tooth, teilkegelwinkel, zahnbreite, bore, eingriffswinkel = 20)
7. pfeilkegelrad(modul, tooth,  teilkegelwinkel, zahnbreite, bore, eingriffswinkel = 20, schraegungswinkel=10)
8. kegelradpaar(modul, tooth_rad, tooth_ritzel, zahnbreite, bore, eingriffswinkel = 20, schraegungswinkel=0)

Beispiele für jedes Modul befinden sich auskommentiert am Ende dieser Datei

Autor:		Dr Jörg Janssen
Stand:		20. Juni 2016
Version:	1.3
Lizenz:		Creative Commons - Attribution, Non Commercial, Share Alike

Erlaubte Module nach DIN 780:
0.05 0.06 0.08 0.10 0.12 0.16
0.20 0.25 0.3  0.4  0.5  0.6
0.7  0.8  0.9  1    1.25 1.5
2    2.5  3    4    5    6
8    10   12   16   20   25
32   40   50   60

*/


// Allgemeine Variablen
pi = 3.14159;
rad = 57.29578;
spiel = 0.05;	// Spiel zwischen Zähnen

/*	Wandelt Radian in Grad um */
function grad(eingriffswinkel) =  eingriffswinkel*rad;

/*	Wandelt Grad in Radian um */
function radian(eingriffswinkel) = eingriffswinkel/rad;

/*	Wandelt 2D-Polarkoordinaten in kartesische um
    Format: radius, phi; phi = Winkel zur x-Achse auf xy-Ebene */
function pol_zu_kart(polvect) = [
	polvect[0]*cos(polvect[1]),  
	polvect[0]*sin(polvect[1])
];

/*	Kreisevolventen-Funktion:
    Gibt die Polarkoordinaten einer Kreisevolvente aus
    r = Radius des Grundkreises
    rho = Abrollwinkel in Grad */
function ev(r,rho) = [
	r/cos(rho),
	grad(tan(rho)-radian(rho))
];

/*  Kugelevolventen-Funktion
    Gibt den Azimutwinkel einer Kugelevolvente aus
    theta0 = Polarwinkel des Kegels, an dessen Schnittkante zum Großkugel die Evolvente abrollt
    theta = Polarwinkel, für den der Azimutwinkel der Evolvente berechnet werden soll */
function kugelev(theta0,theta) = 1/sin(theta0)*acos(cos(theta)/cos(theta0))-acos(tan(theta0)/tan(theta));

/*  Wandelt Kugelkoordinaten in kartesische um
    Format: radius, theta, phi; theta = Winkel zu z-Achse, phi = Winkel zur x-Achse auf xy-Ebene */
function kugel_zu_kart(vect) = [
	vect[0]*sin(vect[1])*cos(vect[2]),  
	vect[0]*sin(vect[1])*sin(vect[2]),
	vect[0]*cos(vect[1])
];

/*	prüft, ob eine Zahl gerade ist
	= 1, wenn ja
	= 0, wenn die Zahl nicht gerade ist */
function istgerade(zahl) =
	(zahl == floor(zahl/2)*2) ? 1 : 0;

/*	größter gemeinsamer Teiler
	nach Euklidischem Algorithmus.
	Sortierung: a muss größer als b sein */
function ggt(a,b) = 
	a%b == 0 ? b : ggt(b,a%b);

/*  Stirnrad
    modul = Höhe des Zahnkopfes über dem Teilkreis
    tooth = Anzahl der Radzähne
    height = Höhe des Zahnrads
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel zur Rotationsachse; 0° = Geradverzahnung */
module stirnrad(modul, tooth, height, bore, eingriffswinkel = 20, schraegungswinkel = 0) {

	// Dimensions-Berechnungen	
	d = modul * tooth;								// Teilkreisdurchmesser
	r = d / 2;											// Teilkreisradius
	alpha_stirn = atan(tan(eingriffswinkel)/cos(schraegungswinkel));	// Schrägungswinkel im Stirnschnitt
	db = d * cos(alpha_stirn);							// Grundkreisdurchmesser
	rb = db / 2;										// Grundkreisradius
	da = (modul <1)? d + modul * 2.2 : d + modul * 2;	// Kopfkreisdurchmesser nach DIN 58400 bzw. DIN 867
	ra = da / 2;										// Kopfkreisradius
	c = modul / 6;										// Kopfspiel
	df = d - 2 * (modul + c);							// Fußkreisdurchmesser
	rf = df / 2;										// Fußkreisradius
	rho_ra = acos(rb/ra);								// maximaler Abrollwinkel;
														// Evolvente beginnt auf Grundkreis und endet an Kopfkreis
	rho_r = acos(rb/r);									// Abrollwinkel am Teilkreis;
														// Evolvente beginnt auf Grundkreis und endet an Kopfkreis
	phi_r = grad(tan(rho_r)-radian(rho_r));				// Winkel zum Punkt der Evolvente auf Teilkreis
	gamma = rad*height/(r*tan(90-schraegungswinkel));	// Torsionswinkel für Extrusion
	schritt = rho_ra/16;								// Evolvente wird in 16 Stücke geteilt
	tau = 360/tooth;									// Teilungswinkel

	// Zeichnung
	rotate([0,0,-phi_r-90*(1-spiel)/tooth]){				// Zahn auf x-Achse zentrieren;
															// macht Ausrichtung mit anderen Rädern einfacher

		linear_extrude(height = height, twist = gamma){
			difference(){
				union(){
					zahnbreite = (180*(1-spiel))/tooth+2*phi_r;
					circle(rf);										// Fußkreis	
					for (rot = [0:tau:360]){
						rotate (rot){								// "tooth-mal" kopieren und drehen
							polygon(concat(							// Zahn
								[[0,0]],							// Zahnsegment beginnt und endet im Ursprung
								[for (rho = [0:schritt:rho_ra])		// von null Grad (Grundkreis)
																	// bis maximalen Evolventenwinkel (Kopfkreis)
									pol_zu_kart(ev(rb,rho))],		// Erste Evolventen-Flanke

								[pol_zu_kart(ev(rb,rho_ra))],		// Punkt der Evolvente auf Kopfkreis

								[for (rho = [rho_ra:-schritt:0])	// von maximalen Evolventenwinkel (Kopfkreis)
																	// bis null Grad (Grundkreis)
									pol_zu_kart([ev(rb,rho)[0], zahnbreite-ev(rb,rho)[1]])]
																	// Zweite Evolventen-Flanke
																	// (180*(1-spiel)) statt 180 Grad,
																	// um Spiel an den Flanken zu erlauben
								)
							);
						}
					}
				}
				circle(r = bore/2);								// bore
			}
		}
	}
}


/*  Pfeilrad; verwendet das Modul "stirnrad"
    modul = Höhe des Zahnkopfes über dem Teilkreis
    tooth = Anzahl der Radzähne
    height = Höhe des Zahnrads
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel zur Rotationsachse, Standardwert = 0° (Geradverzahnung) */
module pfeilrad(modul, tooth, height, bore, eingriffswinkel = 20, schraegungswinkel = 0){

	height = height/2;

	translate([0,0,height]){
		union(){
			stirnrad(modul, tooth, height, bore, eingriffswinkel, schraegungswinkel);		// untere Hälfte
			mirror([0,0,1]){
				stirnrad(modul, tooth, height, bore, eingriffswinkel, schraegungswinkel);	// obere Hälfte
			}
		}
	}
}


/*	Hohlrad
    modul = Höhe des Zahnkopfes über dem Teilkreis
    tooth = Anzahl der Radzähne
    height = Höhe des Zahnrads
	randbreite = Breite des Randes ab Fußkreis
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel zur Rotationsachse, Standardwert = 0° (Geradverzahnung) */
module hohlrad(modul, tooth, height, randbreite, eingriffswinkel = 20, schraegungswinkel = 0) {

	// Dimensions-Berechnungen	
	ha = (tooth >= 20) ? 0.02 * atan((tooth/15)/pi) : 0.6;	// Verkürzungsfaktor Zahnkopfhöhe
	d = modul * tooth;											// Teilkreisdurchmesser
	r = d / 2;														// Teilkreisradius
	alpha_stirn = atan(tan(eingriffswinkel)/cos(schraegungswinkel));// Schrägungswinkel im Stirnschnitt
	db = d * cos(alpha_stirn);										// Grundkreisdurchmesser
	rb = db / 2;													// Grundkreisradius
	c = modul / 6;													// Kopfspiel
	da = (modul <1)? d + (modul+c) * 2.2 : d + (modul+c) * 2;		// Kopfkreisdurchmesser
	ra = da / 2;													// Kopfkreisradius
	df = d - 2 * modul * ha;										// Fußkreisdurchmesser
	rf = df / 2;													// Fußkreisradius
	rho_ra = acos(rb/ra);											// maximaler Evolventenwinkel;
																	// Evolvente beginnt auf Grundkreis und endet an Kopfkreis
	rho_r = acos(rb/r);												// Evolventenwinkel am Teilkreis;
																	// Evolvente beginnt auf Grundkreis und endet an Kopfkreis
	phi_r = grad(tan(rho_r)-radian(rho_r));							// Winkel zum Punkt der Evolvente auf Teilkreis
	gamma = rad*height/(r*tan(90-schraegungswinkel));				// Torsionswinkel für Extrusion
	schritt = rho_ra/16;											// Evolvente wird in 16 Stücke geteilt
	tau = 360/tooth;												// Teilungswinkel

	// Zeichnung
	rotate([0,0,-phi_r-90*(1+spiel)/tooth])						// Zahn auf x-Achse zentrieren;
																	// macht Ausrichtung mit anderen Rädern einfacher
	linear_extrude(height = height, twist = gamma){
		difference(){
			circle(r = ra + randbreite);							// Außenkreis
			union(){
				zahnbreite = (180*(1+spiel))/tooth+2*phi_r;
				circle(rf);											// Fußkreis	
				for (rot = [0:tau:360]){
					rotate (rot) {									// "tooth-mal" kopieren und drehen
						polygon( concat(
							[[0,0]],
							[for (rho = [0:schritt:rho_ra])			// von null Grad (Grundkreis)
																	// bis maximaler Evolventenwinkel (Kopfkreis)
								pol_zu_kart(ev(rb,rho))],
							[pol_zu_kart(ev(rb,rho_ra))],
							[for (rho = [rho_ra:-schritt:0])		// von maximaler Evolventenwinkel (Kopfkreis)
																	// bis null Grad (Grundkreis)
								pol_zu_kart([ev(rb,rho)[0], zahnbreite-ev(rb,rho)[1]])]
																	// (180*(1+spiel)) statt 180,
																	// um Spiel an den Flanken zu erlauben
							)
						);
					}
				}
			}
		}
	}

	echo("Außendurchmesser Hohlrad = ", 2*(ra + randbreite));
	
}

/*  Pfeil-Hohlrad; verwendet das Modul "hohlrad"
    modul = Höhe des Zahnkopfes über dem Teilkegel
    tooth = Anzahl der Radzähne
    height = Höhe des Zahnrads
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel zur Rotationsachse, Standardwert = 0° (Geradverzahnung) */
module pfeilhohlrad(modul, tooth, height, randbreite, eingriffswinkel = 20, schraegungswinkel = 0) {

	height = height / 2;
	translate([0,0,height])
		union(){
		hohlrad(modul, tooth, height, randbreite, eingriffswinkel, schraegungswinkel);		// untere Hälfte
		mirror([0,0,1])
			hohlrad(modul, tooth, height, randbreite, eingriffswinkel, schraegungswinkel);	// obere Hälfte
	}
}

/*	Planetengetriebe; verwendet die Module "pfeilrad" und "pfeilhohlrad"
    modul = Höhe des Zahnkopfes über dem Teilkegel
    tooth_sonne = Anzahl der Zähne des Sonnenrads
    tooth_planet = Anzahl der Zähne eines Planetenrads
    height = Höhe des Zahnrads
	randbreite = Breite des Randes ab Fußkreis
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel zur Rotationsachse, Standardwert = 0° (Geradverzahnung) */
module planetengetriebe(modul, tooth_sonne, tooth_planet, height, randbreite, bore, eingriffswinkel=20, schraegungswinkel=0){

	// Dimensions-Berechnungen
	d_sonne = modul*tooth_sonne;										// Teilkreisdurchmesser Sonne
	d_planet = modul*tooth_planet;									// Teilkreisdurchmesser Planeten
	achsabstand = (modul*tooth_sonne +  modul*tooth_planet) / 2;	// Abstand von Sonnenrad-/Hohlradachse und Planetenachse
	tooth_hohlrad = tooth_sonne + 2*tooth_planet;				// Anzahl der Zähne des Hohlrades

	drehen = istgerade(tooth_planet);								// Muss das Sonnenrad gedreht werden?
		
	n_planeten = (tooth_planet>tooth_sonne) ? ggt(tooth_planet,tooth_sonne) : ggt(tooth_sonne,tooth_planet);
																		// Anzahl Planetenräder = größter gemeinsamer
																		// Teiler von Anzahl der Zähne des Sonnen- und
																		// Planetenrads
	
	// Zeichnung
	rotate([0,0,180/tooth_sonne*drehen]){
		pfeilrad (modul, tooth_sonne, height, bore, eingriffswinkel, -schraegungswinkel);		// Sonnenrad
	}

	for(rot=[0:360/n_planeten:360/n_planeten*(n_planeten-1)]){
		translate(kugel_zu_kart([achsabstand,90,rot]))
			pfeilrad (modul, tooth_planet, height, bore, eingriffswinkel, schraegungswinkel);	// Planetenräder
		}
	
	pfeilhohlrad (modul, tooth_hohlrad, height, randbreite, eingriffswinkel, schraegungswinkel);	// Hohlrad
}

/*  Kegelrad
    modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
    tooth = Anzahl der Radzähne
    teilkegelwinkel = (Halb)winkel des Kegels, auf dem das jeweils andere Hohlrad abrollt
    zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
	schraegungswinkel = Schrägungswinkel, Standardwert = 0° */
module kegelrad(modul, tooth, teilkegelwinkel, zahnbreite, bore, eingriffswinkel = 20, schraegungswinkel=0) {

	// Dimensions-Berechnungen
	d_aussen = modul * tooth;									// Teilkegeldurchmesser auf der Kegelgrundfläche,
																	// entspricht der Sehne im Kugelschnitt
	r_aussen = d_aussen / 2;										// Teilkegelradius auf der Kegelgrundfläche 
	rg_aussen = r_aussen/sin(teilkegelwinkel);						// Großkegelradius für Zahn-Außenseite, entspricht der Länge der Kegelflanke;
	rg_innen = rg_aussen - zahnbreite;								// Großkegelradius für Zahn-Innenseite	
	r_innen = r_aussen*rg_innen/rg_aussen;
	alpha_stirn = atan(tan(eingriffswinkel)/cos(schraegungswinkel));// Schrägungswinkel im Stirnschnitt
	delta_b = asin(cos(alpha_stirn)*sin(teilkegelwinkel));			// Grundkegelwinkel		
	da_aussen = (modul <1)? d_aussen + (modul * 2.2) * cos(teilkegelwinkel): d_aussen + modul * 2 * cos(teilkegelwinkel);
	ra_aussen = da_aussen / 2;
	delta_a = asin(ra_aussen/rg_aussen);
	c = modul / 6;													// Kopfspiel
	df_aussen = d_aussen - (modul +c) * 2 * cos(teilkegelwinkel);
	rf_aussen = df_aussen / 2;
	delta_f = asin(rf_aussen/rg_aussen);
	rkf = rg_aussen*sin(delta_f);									// Radius des Kegelfußes
	height_f = rg_aussen*cos(delta_f);								// Höhe des Kegels vom Fußkegel
	
	echo("Teilkegeldurchmesser auf der Kegelgrundfläche = ", d_aussen);
	
	// Größen für Komplementär-Kegelstumpf
	height_k = (rg_aussen-zahnbreite)/cos(teilkegelwinkel);			// Höhe des Komplementärkegels für richtige Zahnlänge
	rk = (rg_aussen-zahnbreite)/sin(teilkegelwinkel);				// Fußradius des Komplementärkegels
	rfk = rk*height_k*tan(delta_f)/(rk+height_k*tan(delta_f));		// Kopfradius des Zylinders für 
																	// Komplementär-Kegelstumpf
	height_fk = rk*height_k/(height_k*tan(delta_f)+rk);				// height des Komplementär-Kegelstumpfs

	echo("Höhe Kegelrad = ", height_f-height_fk);
	
	phi_r = kugelev(delta_b, teilkegelwinkel);						// Winkel zum Punkt der Evolvente auf Teilkegel
		
	// Torsionswinkel gamma aus Schrägungswinkel
	gamma_g = 2*atan(zahnbreite*tan(schraegungswinkel)/(2*rg_aussen-zahnbreite));
	gamma = 2*asin(rg_aussen/r_aussen*sin(gamma_g/2));
	
	schritt = (delta_a - delta_b)/16;
	tau = 360/tooth;												// Teilungswinkel
	start = (delta_b > delta_f) ? delta_b : delta_f;
	spiegelpunkt = (180*(1-spiel))/tooth+2*phi_r;

	// Zeichnung
	rotate([0,0,phi_r+90*(1-spiel)/tooth]){						// Zahn auf x-Achse zentrieren;
																	// macht Ausrichtung mit anderen Rädern einfacher
		translate([0,0,height_f]) rotate(a=[0,180,0]){
			union(){
				translate([0,0,height_f]) rotate(a=[0,180,0]){								// Kegelstumpf							
					difference(){
						linear_extrude(height=height_f-height_fk, scale=rfk/rkf) circle(rkf);
						translate([0,0,-1]){
							cylinder(h = height_f-height_fk+2, r = bore/2);				// bore
						}
					}	
				}
				for (rot = [0:tau:360]){
					rotate (rot) {															// "tooth-mal" kopieren und drehen
						union(){
							if (delta_b > delta_f){
								// Zahnfuß
								flankenpunkt_unten = 1*spiegelpunkt;
								flankenpunkt_oben = kugelev(delta_f, start);
								polyhedron(
									points = [
										kugel_zu_kart([rg_aussen, start*1.001, flankenpunkt_unten]),	// 1 promille Überlappung mit Zahn
										kugel_zu_kart([rg_innen, start*1.001, flankenpunkt_unten+gamma]),
										kugel_zu_kart([rg_innen, start*1.001, spiegelpunkt-flankenpunkt_unten+gamma]),
										kugel_zu_kart([rg_aussen, start*1.001, spiegelpunkt-flankenpunkt_unten]),								
										kugel_zu_kart([rg_aussen, delta_f, flankenpunkt_unten]),
										kugel_zu_kart([rg_innen, delta_f, flankenpunkt_unten+gamma]),
										kugel_zu_kart([rg_innen, delta_f, spiegelpunkt-flankenpunkt_unten+gamma]),
										kugel_zu_kart([rg_aussen, delta_f, spiegelpunkt-flankenpunkt_unten])								
									],
									faces = [[0,1,2],[0,2,3],[0,4,1],[1,4,5],[1,5,2],[2,5,6],[2,6,3],[3,6,7],[0,3,7],[0,7,4],[4,6,5],[4,7,6]],
									convexity =1
								);
							}
							// Zahn
							for (delta = [start:schritt:delta_a-schritt]){
								flankenpunkt_unten = kugelev(delta_b, delta);
								flankenpunkt_oben = kugelev(delta_b, delta+schritt);
								polyhedron(
									points = [
										kugel_zu_kart([rg_aussen, delta, flankenpunkt_unten]),
										kugel_zu_kart([rg_innen, delta, flankenpunkt_unten+gamma]),
										kugel_zu_kart([rg_innen, delta, spiegelpunkt-flankenpunkt_unten+gamma]),
										kugel_zu_kart([rg_aussen, delta, spiegelpunkt-flankenpunkt_unten]),								
										kugel_zu_kart([rg_aussen, delta+schritt, flankenpunkt_oben]),
										kugel_zu_kart([rg_innen, delta+schritt, flankenpunkt_oben+gamma]),
										kugel_zu_kart([rg_innen, delta+schritt, spiegelpunkt-flankenpunkt_oben+gamma]),
										kugel_zu_kart([rg_aussen, delta+schritt, spiegelpunkt-flankenpunkt_oben])									
									],
									faces = [[0,1,2],[0,2,3],[0,4,1],[1,4,5],[1,5,2],[2,5,6],[2,6,3],[3,6,7],[0,3,7],[0,7,4],[4,6,5],[4,7,6]],
									convexity =1
								);
							}
						}
					}
				}	
			}
		}
	}
}

/*  Pfeil-Kegelrad; verwendet das Modul "kegelrad"
    modul = Höhe des Zahnkopfes über dem Teilkreis
    tooth = Anzahl der Radzähne
    height = Höhe des Zahnrads
    bore = Durchmesser der Mittelbore
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel, Standardwert = 0° */
module pfeilkegelrad(modul, tooth, teilkegelwinkel, zahnbreite, bore, eingriffswinkel = 20, schraegungswinkel=0){

	// Dimensions-Berechnungen
	
	zahnbreite = zahnbreite / 2;
	
	d_aussen = modul * tooth;								// Teilkegeldurchmesser auf der Kegelgrundfläche,
																// entspricht der Sehne im Kugelschnitt
	r_aussen = d_aussen / 2;									// Teilkegelradius auf der Kegelgrundfläche 
	rg_aussen = r_aussen/sin(teilkegelwinkel);					// Großkegelradius, entspricht der Länge der Kegelflanke;
	c = modul / 6;												// Kopfspiel
	df_aussen = d_aussen - (modul +c) * 2 * cos(teilkegelwinkel);
	rf_aussen = df_aussen / 2;
	delta_f = asin(rf_aussen/rg_aussen);
	height_f = rg_aussen*cos(delta_f);							// Höhe des Kegels vom Fußkegel

	// Torsionswinkel gamma aus Schrägungswinkel
	gamma_g = 2*atan(zahnbreite*tan(schraegungswinkel)/(2*rg_aussen-zahnbreite));
	gamma = 2*asin(rg_aussen/r_aussen*sin(gamma_g/2));
	
	echo("Teilkegeldurchmesser auf der Kegelgrundfläche = ", d_aussen);
	
	// Größen für Komplementär-Kegelstumpf
	height_k = (rg_aussen-zahnbreite)/cos(teilkegelwinkel);		// Höhe des Komplementärkegels für richtige Zahnlänge
	rk = (rg_aussen-zahnbreite)/sin(teilkegelwinkel);			// Fußradius des Komplementärkegels
	rfk = rk*height_k*tan(delta_f)/(rk+height_k*tan(delta_f));	// Kopfradius des Zylinders für 
																// Komplementär-Kegelstumpf
	height_fk = rk*height_k/(height_k*tan(delta_f)+rk);			// height des Komplementär-Kegelstumpfs
	
	modul_innen = modul-zahnbreite/rg_aussen;

		union(){
		kegelrad(modul, tooth, teilkegelwinkel, zahnbreite, bore, eingriffswinkel, schraegungswinkel);		// untere Hälfte
		translate([0,0,height_f-height_fk])
			rotate(a=-gamma,v=[0,0,1])
				kegelrad(modul_innen, tooth, teilkegelwinkel, zahnbreite, bore, eingriffswinkel, -schraegungswinkel);	// obere Hälfte
	}
}

/*	Kegelradpaar mit beliebigem Achsenwinkel; verwendet das Modul "kegelrad"
    modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
    tooth_rad = Anzahl der Radzähne am Rad
    tooth_ritzel = Anzahl der Radzähne am Ritzel
	achsenwinkel = Winkel zwischen den Achsen von Rad und Ritzel
    zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
    bore_rad = Durchmesser der Mittelbore des Rads
    bore_ritzel = Durchmesser der Mittelboreen des Ritzels
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
	schraegungswinkel = Schrägungswinkel, Standardwert = 0° */
module kegelradpaar(modul, tooth_rad, tooth_ritzel, achsenwinkel=90, zahnbreite, bore_rad, bore_ritzel, eingriffswinkel=20, schraegungswinkel=0, zusammen_gebaut=1){
 
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
	
	// Zeichnung
	// Rad
	rotate([0,0,180*(1-spiel)/tooth_rad*drehen])
		kegelrad(modul, tooth_rad, delta_rad, zahnbreite, bore_rad, eingriffswinkel, schraegungswinkel);
	
	// Ritzel
	if (zusammen_gebaut == 1)
		translate([-height_f_ritzel*cos(90-achsenwinkel),0,height_f_rad-height_f_ritzel*sin(90-achsenwinkel)])
			rotate([0,achsenwinkel,0])
				kegelrad(modul, tooth_ritzel, delta_ritzel, zahnbreite, bore_ritzel, eingriffswinkel, -schraegungswinkel);
	else
		translate([rkf_ritzel*2+modul+rkf_rad,0,0])
			kegelrad(modul, tooth_ritzel, delta_ritzel, zahnbreite, bore_ritzel, eingriffswinkel, -schraegungswinkel);
 }

/*	Pfeil-Kegelradpaar mit beliebigem Achsenwinkel; verwendet das Modul "pfeilkegelrad"
    modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
    tooth_rad = Anzahl der Radzähne am Rad
    tooth_ritzel = Anzahl der Radzähne am Ritzel
	achsenwinkel = Winkel zwischen den Achsen von Rad und Ritzel
    zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
    bore_rad = Durchmesser der Mittelbore des Rads
    bore_ritzel = Durchmesser der Mittelboreen des Ritzels
    eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
    schraegungswinkel = Schrägungswinkel, Standardwert = 0° */
module pfeilkegelradpaar(modul, tooth_rad, tooth_ritzel, achsenwinkel=90, zahnbreite, bore_rad, bore_ritzel, eingriffswinkel = 20, schraegungswinkel=10, zusammen_gebaut=1){
 
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
	
	// Rad
	rotate([0,0,180*(1-spiel)/tooth_rad*drehen])
		pfeilkegelrad(modul, tooth_rad, delta_rad, zahnbreite, bore_rad, eingriffswinkel, schraegungswinkel);
	
	// Ritzel
	if (zusammen_gebaut == 1)
		translate([-height_f_ritzel*cos(90-achsenwinkel),0,height_f_rad-height_f_ritzel*sin(90-achsenwinkel)])
			rotate([0,achsenwinkel,0])
				pfeilkegelrad(modul, tooth_ritzel, delta_ritzel, zahnbreite, bore_ritzel, eingriffswinkel, -schraegungswinkel);
	else
		translate([rkf_ritzel*2+modul+rkf_rad,0,0])
			pfeilkegelrad(modul, tooth_ritzel, delta_ritzel, zahnbreite, bore_ritzel, eingriffswinkel, -schraegungswinkel);

}

// stirnrad (modul=1, tooth=30, height=5, bore=0, eingriffswinkel=20, schraegungswinkel=20);

// pfeilrad (modul=1, tooth=30, height=5, bore=4, eingriffswinkel=20, schraegungswinkel=30);

// hohlrad (modul=1, tooth=30, height=5, randbreite=5, eingriffswinkel=20, schraegungswinkel=20);

// pfeilhohlrad (modul=1, tooth=30, height=5, randbreite=5, eingriffswinkel=20, schraegungswinkel=30);

// planetengetriebe(modul=1, tooth_sonne=15, tooth_planet=12, height=6, randbreite=5, bore=4, eingriffswinkel=20, schraegungswinkel=30);

// kegelrad(modul=1, tooth=30,  teilkegelwinkel=45, zahnbreite=5, bore=4, eingriffswinkel=20, schraegungswinkel=20);

// pfeilkegelrad(modul=1, tooth=30, teilkegelwinkel=45, zahnbreite=5, bore=4, eingriffswinkel=20, schraegungswinkel=30);

// kegelradpaar(modul=1, tooth_rad=30, tooth_ritzel=11, achsenwinkel=100, zahnbreite=5, bore=4, eingriffswinkel = 20, schraegungswinkel=20, zusammen_gebaut=1);

// pfeilkegelradpaar(modul=1, tooth_rad=30, tooth_ritzel=11, achsenwinkel=100, zahnbreite=5, bore=4, eingriffswinkel = 20, schraegungswinkel=30, zusammen_gebaut=1);


// my

 kegelradpaar(modul=1, tooth_rad=30, tooth_ritzel=11, achsenwinkel=90, zahnbreite=5, bore=2, eingriffswinkel = 20, schraegungswinkel=0, zusammen_gebaut=1);


// pfeilkegelradpaar(modul=1, tooth_rad=30, tooth_ritzel=10, achsenwinkel=90, zahnbreite=5, bore=4, eingriffswinkel = 20, schraegungswinkel=30, zusammen_gebaut=1);

