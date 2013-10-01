#ifndef OscCalcR_h
#define OscCalcR_h

#include "OscCalcCore.h"

/*! R-API: Survivial probability for muon-flavor neutrinos in a two-flavor approximation.
  \param baseline      Input
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  */
void twoFlavorMuSurviveArray_R( 
    double *baseline,
    int    *nenergies,
    double energies[],
    double probabilities[]);

/*! Survivial probability for muon-flavor neutrinos in a three-flavor framework.
  \param baseline      Input
  \param deltaCP       Input
  \param theta23       Input : Study the octant of theta23.
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  */
void threeFlavorMuSurvive_R( 
    double *baseline,
    double *deltaCP,
    double *theta23,
    int    *nenergies,
    double energies[],
    double probabilities[]);


#endif
