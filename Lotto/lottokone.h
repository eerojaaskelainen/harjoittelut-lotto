#ifndef LOTTOKONE
#define LOTTOKONE 1



struct Lottonumerot {						// Arvotut lottonumerot sisältävä struct-muuttuja
	int numerot[perusnumeroidenMaara];		// Perusnumerot
	int lisanumerot[lisanumeroidenMaara];	// Lisänumerot
};

Lottonumerot ArvoNumerot();
int PoimiPallo();
#endif