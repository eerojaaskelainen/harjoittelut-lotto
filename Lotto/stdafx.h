// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <iostream>
#include <cstdlib>			// for rand() and srand() and qsort()
#include <Windows.h>		// for Sleep().


const int perusnumeroidenMaara = 7;		// Peliss‰ arvottavien varsinaisten numeroiden m‰‰r‰
const int lisanumeroidenMaara = 3;		// Peliss‰ arvottavien lis‰numeroiden m‰‰r‰
const int suurinNumero = 39;			// Peliss‰ arvottava suurin numero

#include "lottokone.h"
#include "lottolappu.h"

using namespace std;

int LajittelunVertailu(const void * a, const void * b);			//Prototyyppi qsort() funktiolle, joka j‰rjest‰‰ arrayn nousevaan j‰rjestykseen.



