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

void threeFlavorMuSurviveArray_R( 
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

void threeFlavorNuMuToNuEMatterArray_R( 
    double *baseline,
    double *deltaCP,
    double *matterConst,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[])
{
  struct nuOscParams *params = create_default_nuOscParams();
  params->deltaCP = *deltaCP;
  params->helicity = *helicity;
  if (*hierarchy < 0) invert_hierarchy( params );
  for (int i = 0; i<(*nenergies); ++i) {
    probabilities[i] = threeFlavorNuMuToNuEMatter( 
        params, energies[i], *baseline, *matterConst );
  }
  free(params);
}

void threeFlavorPatmVacuumArray_R( 
    double *baseline,
    double *deltaCP,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[])
{
  struct nuOscParams *params = create_default_nuOscParams();
  params->deltaCP = *deltaCP;
  params->helicity = *helicity;
  if (*hierarchy < 0) invert_hierarchy( params );
  for (int i = 0; i<(*nenergies); ++i) {
    double complex prob = threeFlavorPatmVacuum( 
        params, energies[i], *baseline );
    probabilities[i] = prob * conj(prob);
  }
  free(params);
}

void threeFlavorPsolVacuumArray_R( 
    double *baseline,
    double *deltaCP,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[])
{
  struct nuOscParams *params = create_default_nuOscParams();
  params->deltaCP = *deltaCP;
  params->helicity = *helicity;
  if (*hierarchy < 0) invert_hierarchy( params );
  for (int i = 0; i<(*nenergies); ++i) {
    double complex prob = threeFlavorPsolVacuum( 
        params, energies[i], *baseline );
    probabilities[i] = prob * conj(prob);
  }
  free(params);
}


#endif
