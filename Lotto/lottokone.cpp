

#include "stdafx.h"
#include "lottokone.h"

#include <ctime> // time() -funktiota varten



Lottonumerot ArvoNumerot() {
	/* Funktio arpoo loton viralliset numerot: 7 varsinaista ja 3 varanumeroa. Numeroiden m‰‰r‰t m‰‰ritet‰‰n lottokone.h -tiedostossa.*/

	srand(time(0));																		// Generoidaan p‰iv‰n virallinen siemen
	Lottonumerot palauta;																// Ryhmitelty palautusmuuttuja, johon tulee erikseen lis‰numerot.

	// Alustetaan lottonumerot:
	for (int i = 0; i < perusnumeroidenMaara; i++) {
		palauta.numerot[i] = 0;
	}
	for (int i = 0; i < lisanumeroidenMaara; i++) {
		palauta.lisanumerot[i] = 0;
	}


	// Tulostetaan pelin alkutekstit:

	cout << " ------------------------------------------------------" << endl
		<< "|                                                       |" << endl
		<< "|                L    O    T    T    O                  |" << endl
		<< "|               ----------------------                  |" << endl
		<< "|                                                       |" << endl
		<< "|     Arvotaan " << perusnumeroidenMaara << " numeroa ja " << lisanumeroidenMaara << " lisanumeroa.              |" << endl
		<< "|                                                       |" << endl
		<< " ------------------------------------------------------ " << endl << endl << endl;
	
	// Arvotaan p‰‰numerot:
	Sleep(5000);				// Odotutetaan hetki, k‰ytt‰j‰lle j‰nnityst‰

	// Ajetaan looppi, jossa haetaan taulukon soluihin yksilˆllinen satunnaisluku:
	for (int i = 0; i < perusnumeroidenMaara;) {		// Iteraattoria ei kasvateta t‰ss‰: Vain kun numero on kelvollinen (yksilˆllinen)

		int pallo = PoimiPallo();											// Poimitaan numero arvioitavaksi
		bool ollutJo = false;												// Muuttuu, mik‰li pallo on jo arvottu aiemmin.

		// K‰yd‰‰n l‰pi jo arvotut numerot, ja katsotaan ettei numeroa ole ennest‰‰n arvottu:
		for (int a = 0; a < i; a++) {										// K‰yd‰‰n vain t‰h‰n asti arvotut numerot l‰pi
			if (palauta.numerot[a] == pallo) {
				// Pallo oli jo arvottu!!!
				ollutJo = true;
				break;														// Ei tarvitse tarkistaa enemp‰‰: Uusi numero on arvottava
			}
		}

		// Tarkistetaan, tuliko edellisess‰ loopissa vastaan sama pallo jo arvottuna:

		if (ollutJo == false) {
			// Pallo on tuore, eli kelpaa:
			palauta.numerot[i] = pallo;				// Lis‰t‰‰n pallo tulokseen
			cout << pallo << "   ";
			Sleep(5000);							// Kasvatetaan j‰nnityst‰: 5 sekuntia pallon v‰lill‰.
			i++;									// Kasvatetaan iteraattoria
		}
	}

	// Arvotaan lis‰numerot:
	cout << "\n\nJa lisanumerot ovat:" << endl << endl;

	// Looppi on vastaava kuin edell‰ oleva perusnumeroiden haku.
	for (int i = 0; i < lisanumeroidenMaara;) {

		int pallo = PoimiPallo();											// Poimitaan numero arvioitavaksi
		bool ollutJo = false;												// Muuttuu, mik‰li pallo on jo arvottu aiemmin.

		// K‰yd‰‰n l‰pi jo arvotut numerot, ja katsotaan ettei numeroa ole ennest‰‰n arvottu:

		// Ensin varsinaiset numerot:
		for (int a = 0; a < perusnumeroidenMaara; a++) {						
			if (palauta.numerot[a] == pallo) {
				// Pallo oli jo arvottu!!!
				ollutJo = true;
				break;														// Ei tarvitse tarkistaa enemp‰‰: Uusi numero on arvottava
			}
		}

		// Sitten lis‰numerot:
		for (int a = 0; a < i; a++) {										// K‰yd‰‰n vain t‰h‰n asti arvotut
			if (palauta.lisanumerot[a] == pallo) {
				// Pallo oli jo arvottu!!!
				ollutJo = true;
				break;														// Ei tarvitse tarkistaa enemp‰‰: Uusi numero on arvottava
			}
		}

		// Tarkistetaan, tuliko edellisess‰ loopissa vastaan sama pallo jo arvottuna:

		if (ollutJo == false) {
			// Pallo on tuore, eli kelpaa:
			palauta.lisanumerot[i] = pallo;				// Lis‰t‰‰n pallo tulokseen
			cout << pallo << "   ";						// Tulostetaan numero
			Sleep(5000);							//Kasvatetaan j‰nnityst‰: 5 sekuntia pallon v‰lill‰.
			i++;									// Kasvatetaan iteraattoria
		}
	}

	// Numerot arvottu, palautetaan:

	return palauta;
}

int PoimiPallo() {
	// Poimitaan pallo k‰ytt‰en rand() -funktiota. Seed on annettu kerran ennen funktion kutsuja.

	int minimi = 1;
	int maksimi = suurinNumero;
	return (rand() % (maksimi - minimi + 1)) + minimi;
}
