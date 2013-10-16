#ifndef OscCalcCore_h
#define OscCalcCore_h

#include <complex.h>

struct nuOscParams {

  double delta_m12_squared;
  double delta_m23_squared;
  double delta_m13_squared;

  double delta_m21_squared;
  double delta_m32_squared;
  double delta_m31_squared;

  double theta12;
  double theta23;
  double theta13;

  int hierarchy;  /* negative for inverted, positive for normal */
  int helicity;   /* negative for antinu, positive for nu */

  double deltaCP;
};

struct nuOscParams * create_default_nuOscParams();

/*! Print the current parameter set to std out.
  */
void printNuOscParams( const struct nuOscParams* pp );

/*! Survivial probability for muon-flavor neutrinos in a two-flavor approximation.
  */
double twoFlavorMuSurvive( 
    const struct nuOscParams* pp, 
    double energyInGeV, 
    double baselineInKm ); 

/*! Survivial probability for muon-flavor neutrinos in a three-flavor framework.
  */
double threeFlavorMuSurvive( 
    const struct nuOscParams* pp, 
    double energyInGeV,
    double baselineInKm ); 

/*! Disappearance probability for muon-flavor neutrinos in a three-flavor framework.
  */
double threeFlavorMuDisappear( 
    const struct nuOscParams* pp, 
    double energyInGeV,
    double baselineInKm ); 

/*! Disappearance probability for electron-flavor neutrinos in a three-flavor framework.
  */
double threeFlavorEDisappear( 
    const struct nuOscParams* pp, 
    double energyInGeV, 
    double baselineInKm );

/*! The transition probability for three-flavor e-mu-oscialltions in matter.
  1/4000 is an appropriate matter constant for a baseline measured in km. 
  */
double threeFlavorNuMuToNuEMatter( 
    const struct nuOscParams* pp, 
    double energyInGeV, 
    double baselineInKm,
    double matterConstant );  

/*! The transition probability for three-flavor e-mu-oscialltions in vacuum.
  The probability is calculated from the interference between the solar and 
  atmospheric probabilities.
  */
double threeFlavorNuMuToNuEVacuum( 
    const struct nuOscParams* pp, 
    double energyInGeV, 
    double baselineInKm );

/*! The "atmospheric" probability for three-flavor e-to-mu oscillations in vacuum.
  This is not a physically useful probability - the solar probability will always 
  contribute. This is broken out into a separate function ONLY For the purpose of 
  demonstrating the effect of the interference.
  */
double complex threeFlavorPatmVacuum( 
    const struct nuOscParams* pp, 
    double energyInGeV, 
    double baselineInKm );

/*! The "solar" probability for three-flavor e-to-mu oscillations in vacuum.
  This is not a physically useful probability - the atmospheric probability will always 
  contribute. This is broken out into a separate function ONLY For the purpose of 
  demonstrating the effect of the interference.
  */
double complex threeFlavorPsolVacuum( 
    const struct nuOscParams* pp, 
    double energyInGeV, 
    double baselineInKm );

void printReferences();
void printDefaultParameters();

void invert_hierarchy( struct nuOscParams * params );

double SinSqrd2Theta12( const struct nuOscParams * pp );
double SinSqrd2Theta13( const struct nuOscParams * pp );
double SinSqrd2Theta23( const struct nuOscParams * pp );
double SinSqrdTheta23( const struct nuOscParams * pp );
double CosSqrdTheta23( const struct nuOscParams * pp );

/* L in km, E in GeV, LovrE = L/E */
double Delta12( const struct nuOscParams * pp, double LovrE );
double Delta13( const struct nuOscParams * pp, double LovrE );
double Delta23( const struct nuOscParams * pp, double LovrE );
double Delta21( const struct nuOscParams * pp, double LovrE );
double Delta31( const struct nuOscParams * pp, double LovrE );
double Delta32( const struct nuOscParams * pp, double LovrE );

/* Convenience Functions for Sines and Cosines of mixing angles & \delta_{CP}. */
double  s12( const struct nuOscParams * pp ); 
double  s13( const struct nuOscParams * pp ); 
double  s23( const struct nuOscParams * pp ); 
double  c12( const struct nuOscParams * pp ); 
double  c13( const struct nuOscParams * pp ); 
double  c23( const struct nuOscParams * pp ); 
double cdlt( const struct nuOscParams * pp ); 
double sdlt( const struct nuOscParams * pp ); 

double complex Ufm( const struct nuOscParams * pp, int flavor, int mass );

double Ue1Sqrd( const struct nuOscParams * pp );   
double Ue2Sqrd( const struct nuOscParams * pp );   
double Ue3Sqrd( const struct nuOscParams * pp );   
double Umu1Sqrd( const struct nuOscParams * pp );  
double Umu2Sqrd( const struct nuOscParams * pp );  
double Umu3Sqrd( const struct nuOscParams * pp );  
double Utau1Sqrd( const struct nuOscParams * pp ); 
double Utau2Sqrd( const struct nuOscParams * pp ); 
double Utau3Sqrd( const struct nuOscParams * pp ); 

#endif
