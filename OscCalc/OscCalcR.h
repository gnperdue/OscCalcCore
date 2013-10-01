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
void threeFlavorMuSurviveArray_R( 
    double *baseline,
    double *deltaCP,
    double *theta23,
    int    *nenergies,
    double energies[],
    double probabilities[]);

/*! The transition probability for three-flavor e-mu-oscialltions in matter.
  \param baseline      Input
  \param deltaCP       Input
  \param matterConst   Input : 1/4000 is an appropriate matter constant for a baseline measured in km. 
  \param hierarchy     Input : Positive value for normal, negative value for inverted.
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  
  */
void threeFlavorNuMuToNuEMatterArray_R( 
    double *baseline,
    double *deltaCP,
    double *matterConst,
    int    *hierarchy,
    int    *nenergies,
    double energies[],
    double probabilities[]);

#endif
