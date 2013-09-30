#ifndef OscCalcR_c
#define OscCalcR_c

#include <stdio.h>
#include <stdlib.h>
#include "OscCalcR.h"

void twoFlavorMuSurviveArray_R( 
    double *baseline,
    int    *nenergies,
    double energies[],
    double probabilities[]) 
{
  struct nuOscParams *params = create_default_nuOscParams();
  for (int i = 0; i<(*nenergies); ++i) {
    probabilities[i] = twoFlavorMuSurvive( params, energies[i], *baseline ); 
  }
  free(params);
}

#endif
