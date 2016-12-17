                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


http://www.thingiverse.com/thing:1604369
Getriebe Bibliothek für OpenSCAD / Gears Library for OpenSCAD by janssen86 is licensed under the Creative Commons - Attribution - Non-Commercial - Share Alike license.
http://creativecommons.org/licenses/by-nc-sa/3.0/

# Summary

<h3>OpenSCAD Bibliothek für Evolventen-Getriebe</h3>

Eine Bibliothek zur parametrischen Erzeugung von Stirn-, Hohl- und Kegelrädern sowie von Zusammensetzungen. Die deutschen Begriffe werden gemäß der Definitionen in DIN 868 verwendet.

+++

<h3>OpenSCAD Library for Involute Gears</h3>

A library for the parametric creation of spur-, ring- and bevel gears, as well assemblies.

+++
+++

<h4>Parametrisches Stirnrad mit Evolventen-Verzahnung</h4>

Erzeugt ein Stirnrad mit Evolventenverzahnung ohne Profilverschiebung nach DIN 867 / DIN 58400. Zwei Räder kämmen, wenn sie das gleiche Modul und entgegen gesetzten Schrägungswinkel aufweisen. Schrägverzahnte Räder laufen ruhiger als geradverzahnte Räder. Sie erzeugen jedoch eine belastende Axialkraft, die durch die Achslager ausgeglichen werden muss. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978.

Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 21,17° im Stirnschnitt bei 20° Schrägungswinkel.

<h5>Format:</h5>
stirnrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkreis
zahnzahl = Anzahl der Radzähne
hoehe = Höhe des Zahnrads
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Schrägungswinkel zur Rotationsachse; 0° = Geradverzahnung

+++

<h4>Parametric Involute Spur Gear</h4>

Creates an involute spur gear without profile displacement following DIN 867 / DIN 58400. Two gears will mesh if their modules are the same and their helix angles opposite. Helical gears run more smoothly than gears with straight teeth. However, they also create axial loads which the bearings must be designed to contain. Recommendations for the helix angle depending on the module can be found in DIN 3978.

This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 20° helix angle, a pressure angle of 20° becomes a pressure angle of 21.17° in the transverse section.

<h5>Format:</h5>
stirnrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl = number of teeth
hoehe = gear height
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle to the rotation axis; 0° = straight teeth

+++
+++

<h4>Parametrisches Pfeilrad mit Evolventenverzahnung</h4>

Erzeugt ein Stirnrad mit Pfeilverzahnung ohne Profilverschiebung. Zwei Räder kämmen, wenn sie das gleiche Modul und entgegen gesetzten Schrägungswinkel aufweisen. Pfeilverzahnte Räder laufen ruhiger als geradverzahnte Räder. Sie erzeugen, anders als schrägverzahnte Räder, keine belastende Axialkraft, die durch die Achslager ausgeglichen werden müsste.

Der Schrägungswinkel sollte zwischen zwischen 30° und 45° liegen. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978. 

Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 22,80° im Stirnschnitt bei 30° Schrägungswinkel.

<h5>Format:</h5>
pfeilrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkreis
zahnzahl = Anzahl der Radzähne
hoehe = Höhe des Zahnrads
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Schrägungswinkel, Standardwert = 0° (Geradverzahnung)

+++

<h4>Parametric Herringbone Involute Spur Gear</h4>

Creates a herringbone spur gear without profile displacement. Two gears will mesh if their modules are the same and their helix angles opposite. Herringbone gears run more smoothly than gears with straight teeth. They also do not create torque on the axis like helical gears do.

A helix angle, if used, should be set between between 30° and 45°. Recommendations for the helix angle depending on the module can be found in DIN 3978.

This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 30° helix angle, a pressure angle of 20° becomes a pressure angle of 22.80 in the transverse section.

<h5>Format:</h5>
pfeilrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl = number of teeth
hoehe = gear height
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle to the rotation axis; 0° = straight teeth

+++
+++

<h4>Parametrisches Hohlrad mit Evolventenverzahnung</h4>

Erzeugt ein Hohlrad mit Evolventenverzahnung ohne Profilverschiebung nach DIN 3993. Schrägverzahnte Räder laufen ruhiger als geradverzahnte Räder. Sie erzeugen jedoch eine belastende Axialkraft, die durch die Achslager ausgeglichen werden muss. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978.

Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 21,17° im Stirnschnitt bei 20° Schrägungswinkel.

<h5>Format:</h5>
hohlrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkreis
zahnzahl = Anzahl der Radzähne
hoehe = Höhe des Zahnrads
randbreite = Breite des Randes ab Fußkreis
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Schrägungswinkel, Standardwert = 0° (Geradverzahnung)

+++

<h4>Parametric Involute Ring Gear</h4>

Creates a herringbone ring gear without profile displacement. Helical gears run more smoothly than gears with straight teeth. However, they also create axial loads which the bearings must be designed to contain. Recommendations for the helix angle depending on the module can be found in DIN 3978.

This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 20° helix angle, a pressure angle of 20° becomes a pressure angle of 21.17° in the transverse section.

<h5>Format:</h5>
hohlrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl = number of teeth
hoehe = gear height
randbreite = width of the rim around the ring gear, measured from the root circle
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle to the rotation axis; 0° = straight teeth

+++
+++

<h4>Parametrisches Pfeil-Hohlrad mit Evolventenverzahnung</h4>

Erzeugt ein Pfeil-Hohlrad mit Evolventenverzahnung ohne Profilverschiebung nach DIN 3993. Hohl- und Strinrad kämmen, wenn sie das gleiche Modul und entgegen gesetzten Schrägungswinkel aufweisen. Pfeilverzahnte Räder laufen ruhiger als geradverzahnte Räder. Sie erzeugen, anders als schrägverzahnte Räder, keine belastende Axialkraft, die durch die Achslager ausgeglichen werden müsste.

Der Schrägungswinkel sollte zwischen zwischen 30° und 45° liegen. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978.  Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 22,80° im Stirnschnitt bei 30° Schrägungswinkel.

<h5>Format:</h5>
pfeilhohlrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkreis
zahnzahl = Anzahl der Radzähne
hoehe = Höhe des Zahnrads
randbreite = Breite des Randes ab Fußkreis
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Schrägungswinkel, Standardwert = 0° (Geradverzahnung)

+++

<h4>Parametric Herringbone Involute Ring Gear</h4>

Creates a herringbone ring gear without profile displacement. A ring and spur gear mesh if they have the same module and opposite helix angels. Herringbone gears run more smoothly than gear with straight teeth. They also do not create axial load like helical gears do.

A helix angle, if used, should be set between between 30° and 45°. Recommendations for the helix angle depending on the module can be found in DIN 3978. This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 30° helix angle, a pressure angle of 20° becomes a pressure angle of 22.80° in the transverse section.

<h5>Format:</h5>
pfeilhohlrad(modul, zahnzahl, hoehe, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl = number of teeth
hoehe = gear height
randbreite = width of the rim around the ring gear, measured from the root circle
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle to the rotation axis; 0° = straight teeth

+++
+++

<h3>Parametrisches Planetengetriebe mit Evolventen-Pfeilverzahnung</h3>

Dieses Modul berechnet sowohl das Hohlrad als auch die Anzahl und Geometrie der Planetenräder aus den Zahnzahlen für Sonne und Planeten. Der Schrägungswinkel sollte zwischen zwischen 30° und 45° liegen. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978.  Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 22,80° im Stirnschnitt bei 30° Schrägungswinkel.

Um beim 3D-Druck ein Verkleben der besonders der Planetenräder mit dem Hohlrad zu vermeiden, kann das Getriebe auseinander gebaut gedruckt werden (zusammen gebaut = 0). Dabei ist zu beachten, dass eine Pfeilverzahnung den Zusammenbau erschwert. Erfahrungsgemäß ist dies bei 30° noch möglich; sollte es hier jedoch zu Problemen kommen, dann ist ein geringerer Schrägungswinkel zu wählen. Natürlich kann man auch Geradverzahnung wählen (Schraegungswinkel = 0°).

Außerdem kann ein Verkleben durch ein ausreichend großes Spiel vermieden werden; ein ausreichendes Spiel vermeidet auch Probleme beim Kämmen. Das Spiel kann um so kleiner bleiben, je besser die Auflösung des 3D-Druckers ist, sollte erfahrungsgemäß 5% jedoch nicht unterschreiten.

<h5>Format:</h5>
planetengetriebe(modul, zahnzahl_sonne, zahnzahl_planet, hoehe, randbreite, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkegel
zahnzahl_sonne = Anzahl der Zähne des Sonnenrads
zahnzahl_planet = Anzahl der Zähne eines Planetenrads
hoehe = Höhe des Zahnrads
randbreite = Breite des Randes ab Fußkreis
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Schrägungswinkel (Geradverzahnung)

+++

<h3>Parametric Planetary Gear using Involute Tooth Geometry and Herringbone Shape</h3>

This module calculates both the ring gear as well as the number and geometry of the planetary gears from the number of teeth on the sun and planets. The helix angle should be between between 30° and 45°. Recommendations for the helix angle depending on the module can be found in DIN 3978. This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 30° helix angle, a pressure angle 20° becomes a pressure angle of 22.80° in the transverse section.

To avoid the gears sticking in a 3D print, particularly sticking of the planet gears to the ring gear, the gears can be printed in disassembled layout (zusammen gebaut = 0). In that case, please note that herringbone teeth complicate the re-assembly. Experience shows that reassembly is still possible at 30°; however in case of reassembly problems, a lesser helix angle should be selected. Of course, one could always choose straight teeth (Schraegungswinkel = 0).

The gears can also be kept from sticking by a sufficiently large clearance ("Spiel"); a sufficient clearance also avoids meshing problems. Clearance can be left smaller if the 3D printer offers good resolution, however experience shows that it should not be less than 5%.

<h5>Format:</h5>
planetengetriebe(modul, zahnzahl_sonne, zahnzahl_planet, hoehe, randbreite, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl_sonne = number of teeth on the sun gear
zahnzahl_planet = number of teeth per planet gear
hoehe = gear height
randbreite = width of the rim around the ring gear, measured from the root circle
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle to the rotation axis; 0° = straight teeth

+++
+++

<h4>Parametrisches Kegelrad mit Kugelevolventen-Verzahnung</h4>

Dieses Modul erzeugt ein Kegelrad mit Kugelevolventen-Verzahnung. Zwei Kegelräder kämmen, wenn sie das gleiche Modul und entgegen gesetzten Schrägungswinkel aufweisen. Schrägverzahnte Räder laufen ruhiger als geradverzahnte Räder. Sie erzeugen jedoch eine belastende Axialkraft, die durch die Achslager ausgeglichen werden muss. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978.

Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 21,17° im Stirnschnitt bei 20° Schrägungswinkel.

<h5>Format:</h5>
kegelrad(modul, zahnzahl, teilkegelwinkel, zahnbreite, bohrung, eingriffswinkel, verschiebungswinkel)

<h5>Parameters:</h5>
modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
zahnzahl = Anzahl der Radzähne
teilkegelwinkel = (Halb)winkel des Kegels, auf dem das jeweils andere Hohlrad abrollt
zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Winkel der Zähne zur Mantellinie des Teilkegels, 0° = Geradverzahnung


<h4>Parametric Bevel Gear with Spherical Involute Geometry</h4>

This module creates a bevel gear with spherical involute geometry. Two gears will mesh if their modules are the same and their helix angles opposite. Helical gears run more smoothly than gears with straight teeth. However, they also create axial loads which the bearings must be designed to contain. Recommendations for the helix angle depending on the module can be found in DIN 3978.

This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 20° helix angle, a pressure angle of 20° becomes a pressure angle of 21.17° in the transverse section.

<h5>Format:</h5>
kegelrad(modul, zahnzahl, teilkegelwinkel, zahnbreite, bohrung, eingriffswinkel, verschiebungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl = number of teeth
teilkegelwinkel = reference cone (half-)angle
zahnbreite = width of teth from the rim in direction of the reference cone tip
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = angle between the teeth and the reference cone envelope line, 0° = straight teeth

+++
+++

<h4>Parametrisches Paar von Kegelrädern</h4>

Dieses Modul berechnet ein Paar von Kegelrädern aus dem Modul sowie der Anzahl der Zähne für Rad und Ritzel. Der voreingestellte Winkel von 90° zwischen den Achsen beider Räder kann variiert werden. Es ist möglich, die Geometrie sowohl zusammengesetzt als auch zum Drucken auseinander gelegt zu berechnen.

<h5>Format:</h5>
kegelradpaar(modul, zahnzahl_rad, zahnzahl_ritzel, achsenwinkel, zahnbreite, bohrung_rad, bohrung_ritzel, eingriffswinkel, torsionswinkel, zusammen_gebaut)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
zahnzahl_rad = Anzahl der Radzähne am Rad
zahnzahl_ritzel = Anzahl der Radzähne am Ritzel
achsenwinkel = Winkel zwischen den Achsen von Rad und Ritzel, Standardwert = 90°
zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
bohrung_rad = Durchmesser der Mittelbohrung des Rads
bohrung_ritzel = Durchmesser der Mittelbohrungen des Ritzels
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Winkel der Zähne zur Mantellinie des Teilkegels, 0° = Geradverzahnung
zusammen_gebaut = Zusammen gebaut (1) oder zum Drucken getrennt (0)

+++

<h4>Parametric Pair of Bevel Gears</h4>

This module calculates both the gear and the pinion of a bevel gear pair, using the gears' module and their numbers of teeth. The preset angle of 90° between the axes of both gears can be varied. It is possible to calculate the pair both assembled as well as disassembled for printing.

<h5>Format:</h5>
kegelradpaar(modul, zahnzahl_sonne, zahnzahl_planet, hoehe, randbreite, bohrung, eingriffswinkel, schraegungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl_rad = number of teeth on the gear
zahnzahl_ritzel = number of teeth on the pinion
achsenwinkel = angle between the axes of pinion and gear, standard value = 90°
zahnbreite = width of the teeth from the rim in direction of the cone tip
bohrung_rad = central bore diameter of the gear
bohrung_ritzel = central bore diameter of the pinion
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle between the teeth and the reference cone envelope line, 0° = straight teeth
zusammen_gebaut = assembled (1) oder disassembled for printing (0)

+++
+++

<h4>Parametrisches Pfeil-Kegelrad mit Kugelevolventen-Verzahnung</h4>

Dieses Modul erzeugt ein Pfeil-Kegelrad mit Kugelevolventen-Verzahnung. Zwei Kegelräder kämmen, wenn sie das gleiche Modul und entgegen gesetzten Schrägungswinkel aufweisen. Pfeilverzahnte Räder laufen ruhiger als geradverzahnte Räder. Sie erzeugen, anders als schrägverzahnte Räder, keine belastende Axialkraft, die durch die Achslager ausgeglichen werden müsste. Empfehlungen für Schrägungswinkel abhängig vom Modul findet man in DIN 3978.

Das Modul passt den Eingriffswinkel im Stirnschnitt an den Schrägungswinkel an, d.h. 20° Eingriffswinkel werden zu 22,80° im Stirnschnitt bei 30° Schrägungswinkel.

<h5>Format:</h5>
kegelrad(modul, zahnzahl, teilkegelwinkel, zahnbreite, bohrung, eingriffswinkel, verschiebungswinkel)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
zahnzahl = Anzahl der Radzähne
teilkegelwinkel = (Halb)winkel des Kegels, auf dem das jeweils andere Hohlrad abrollt
zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
bohrung = Durchmesser der Mittelbohrung
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Winkel der Zähne zur Mantellinie des Teilkegels, 0° = Geradverzahnung

+++

<h4>Parametric Herringbone Bevel Gear with Spherical Involute Geometry</h4>

This module creates a herringbone bevel gear with spherical involute teeth geometry. Two gears will mesh if their modules are the same and their helix angles opposite. Herringbone gears run more smoothly than gear with straight teeth. They also do not create axial load like helical gears do. Recommendations for the helix angle depending on the module can be found in DIN 3978.

This module adjusts the pressure angle in the transverse section to the helix angle: e.g. with a 30° helix angle, a pressure angle of 20° becomes a pressure angle of 22.80° in the transverse section.

<h5>Format:</h5>
kegelrad(modul, zahnzahl, teilkegelwinkel, zahnbreite, bohrung, eingriffswinkel, verschiebungswinkel)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl = number of teeth
teilkegelwinkel = reference cone (half-)angle
zahnbreite = width of teeth from the rim in direction of the reference cone tip
bohrung = central bore diameter
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle between the teeth and the reference cone envelope line, 0° = straight teeth

+++
+++

<h4>Parametrisches Paar von Pfeil-Kegelrädern</h4>

Dieses Modul berechnet ein Paar von Pfeil-Kegelrädern aus dem Modul sowie der Anzahl der Zähne für Rad und Ritzel. Der voreingestellte Winkel von 90° zwischen den Achsen beider Räder kann variiert werden. Es ist möglich, die Geometrie sowohl zusammengesetzt als auch zum Drucken auseinander gelegt zu berechnen.

<h5>Format:</h5>
kegelradpaar(modul, zahnzahl_rad, zahnzahl_ritzel, achsenwinkel, zahnbreite, bohrung_rad, bohrung_ritzel, eingriffswinkel, torsionswinkel, zusammen_gebaut)

<h5>Parameter:</h5>
modul = Höhe des Zahnkopfes über dem Teilkegel; Angabe für die Aussenseite des Kegels
zahnzahl_rad = Anzahl der Radzähne am Rad
zahnzahl_ritzel = Anzahl der Radzähne am Ritzel
achsenwinkel = Winkel zwischen den Achsen von Rad und Ritzel, Standardwert = 90°
zahnbreite = Breite der Zähne von der Außenseite in Richtung Kegelspitze
bohrung_rad = Durchmesser der Mittelbohrung des Rads
bohrung_ritzel = Durchmesser der Mittelbohrungen des Ritzels
eingriffswinkel = Eingriffswinkel, Standardwert = 20° gemäß DIN 867
schraegungswinkel = Winkel der Zähne zur Mantellinie des Teilkegels, 0° = Geradverzahnung
zusammen_gebaut = Zusammen gebaut (1) oder zum Drucken getrennt (0)

+++

<h4>Parametric Pair of Herringbone Bevel Gears</h4>

This module calculates both the gear and the pinion of a herringbone bevel gear pair, using the gears' module and their numbers of teeth. The preset angle of 90° between the axes of both gears can be varied. It is possible to calculate the pair both assembled as well as disassembled for printing.

<h5>Format:</h5>
kegelradpaar(modul, zahnzahl_sonne, zahnzahl_planet, hoehe, randbreite, bohrung, eingriffswinkel=20, schraegungswinkel=0)

<h5>Parameters:</h5>
modul = gear module = 25.4 / diametrical pitch = circular pitch / pi
zahnzahl_rad = number of teeth on the gear
zahnzahl_ritzel = number of teeth on the pinion
achsenwinkel = angle between the axes of pinion and gear, standard value = 90°
zahnbreite = width of the teeth from the rim in direction of the cone tip
bohrung_rad = central bore diameter of the gear
bohrung_ritzel = central bore diameter of the pinion
eingriffswinkel = pressure angle, standard value = 20° according to DIN 867
schraegungswinkel = helix angle between the teeth and the reference cone envelope line, 0° = straight teeth
zusammen_gebaut = assembled (1) or disassembled for printing (0)