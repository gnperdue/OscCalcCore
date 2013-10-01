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

void threeFlavorMuSurvive_R( 
    double *baseline,
    double *deltaCP,
    double *theta23,
    int    *nenergies,
    double energies[],
    double probabilities[])
{
  struct nuOscParams *params = create_default_nuOscParams();
  params->deltaCP = *deltaCP;
  params->theta23 = *theta23;
  for (int i = 0; i<(*nenergies); ++i) {
    probabilities[i] = threeFlavorMuSurvive( params, energies[i], *baseline ); 
  }
  free(params);
}


#endif
