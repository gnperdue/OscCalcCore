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

const double L_OVER_E_CONVERTER = 1.2669;

/* References : apologies to those not filled in yet! */
const char* theta12Reference  = 
	"A. Gando et al., Phys. Rev. D 83, 052002 (2011).";
const char* theta23Reference  = 
	"R. Wendell et al., Phys. Rev. D 81, 092004 (2010).";
const char* theta13Reference  = 
	"Daya Bay Paper";
const char* deltaM12Reference = 
	"A. Gando et al., Phys. Rev. D 83, 052002 (2011).";
const char* deltaM23Reference = 
	"P. Adamson et al., Phys. Rev. Lett. 106, 181801 (2011).";
const char* deltaM13Reference = 
	"Some reference";
const char* globalFitsRef     = 
	"arXiv 1209.3023";

/* Current Ref: 1209.3023 */
const int    default_helicity   = 1;     /* Nu, negative is Antinu */
const int    default_hierarchy  = 1;     /* Normal, negatis is Inverted */
const double default_deltaCP    = 0.0;

/* 1-2 Splitting */
#define DEFDM12 -7.50e-5
const double default_dm12_squared          =      DEFDM12;
const double default_dm21_squared          = -1.0*DEFDM12;

/* Normal Hierarchy Mass Splittings */
#define DEFDM31 2.47e-3
const double default_dm31_squared_normal   =      DEFDM31;
const double default_dm32_squared_normal   =      DEFDM31 + DEFDM12;
const double default_dm13_squared_normal   = -1.0*DEFDM31;
const double default_dm23_squared_normal   = -1.0*(DEFDM31 + DEFDM12);

/* Inverted Hierarchy Splittings */
#define DEFDM32 -2.43e-3
const double default_dm32_squared_inverted =        DEFDM32;
const double default_dm23_squared_inverted =   -1.0*DEFDM32;
const double default_dm13_squared_inverted =   -1.0*DEFDM32 + DEFDM12;
const double default_dm31_squared_inverted = -1.0*(-1.0*DEFDM32 + DEFDM12);

/* Mixing Angles */
#define THETA12DEG 33.3
#define THETA23DEG 40.0
#define THETA13DEG 8.6
#define DEGTORAD 3.14159 / 180;
const double default_theta12  = THETA12DEG * DEGTORAD;
const double default_theta23  = THETA23DEG * DEGTORAD;
const double default_theta13  = THETA13DEG * DEGTORAD;

#define TOKAI_TO_KAMIOKA   270.0 /* km */ /* probably wrong... */
#define FNAL_TO_SOUDAN     735.0 /* km */
#define FNAL_TO_ASHRIVER   810.0 /* km */ /* probably wrong... */
#define FNAL_TO_HOMESTAKE 1350.0 /* km */ /* probably wrong... */

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

