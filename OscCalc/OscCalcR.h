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

/*! R-API: Survivial probability for muon-flavor neutrinos in a three-flavor framework.
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

/*! R-API: The transition probability for three-flavor e-mu-oscialltions in matter.
  \param baseline      Input
  \param deltaCP       Input
  \param matterConst   Input : 1/4000 is an appropriate matter constant for a baseline measured in km. 
  \param hierarchy     Input : Positive value for normal, negative value for inverted.
  \param helicity      Input : Positive value for neutrinos, negative value for antineutrinos.
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  */
void threeFlavorNuMuToNuEMatterArray_R( 
    double *baseline,
    double *deltaCP,
    double *matterConst,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[]);

/*! R-API: The transition probability for three-flavor e-mu-oscialltions in vacuum.
  \param baseline      Input
  \param deltaCP       Input
  \param hierarchy     Input : Positive value for normal, negative value for inverted.
  \param helicity      Input : Positive value for neutrinos, negative value for antineutrinos.
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  */
void threeFlavorNuMuToNuEVacuumArray_R( 
    double *baseline,
    double *deltaCP,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[]);

/*! R-API: The "atmospheric" probability for three-flavor e-to-mu oscillations in vacuum.
  This is not a physically useful probability - the solar probability will always 
  contribute. This is broken out into a separate function ONLY For the purpose of 
  demonstrating the effect of the interference.
  \param baseline      Input
  \param deltaCP       Input
  \param hierarchy     Input : Positive value for normal, negative value for inverted.
  \param helicity      Input : Positive value for neutrinos, negative value for antineutrinos.
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  */
void threeFlavorPatmVacuumArray_R( 
    double *baseline,
    double *deltaCP,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[]);

/*! R-API: The "solar" probability for three-flavor e-to-mu oscillations in vacuum.
  This is not a physically useful probability - the atmospheric probability will always 
  contribute. This is broken out into a separate function ONLY For the purpose of 
  demonstrating the effect of the interference.
  \param baseline      Input
  \param deltaCP       Input
  \param hierarchy     Input : Positive value for normal, negative value for inverted.
  \param helicity      Input : Positive value for neutrinos, negative value for antineutrinos.
  \param nenergies     Input : The length of the energies array and the probabilities array.
  \param energies      Input : Array of energies.
  \param probabilities Output: Array of calculated probabilies.
  */
void threeFlavorPsolVacuumArray_R( 
    double *baseline,
    double *deltaCP,
    int    *hierarchy,
    int    *helicity,
    int    *nenergies,
    double energies[],
    double probabilities[]);

#endif
