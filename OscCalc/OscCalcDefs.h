#ifndef OscCalcDefs_h
#define OscCalcDefs_h

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

/* Common Baselines */
#define TOKAI_TO_KAMIOKA   270.0 /* km */ /* probably wrong... */
#define FNAL_TO_SOUDAN     735.0 /* km */
#define FNAL_TO_ASHRIVER   810.0 /* km */ /* probably wrong... */
#define FNAL_TO_HOMESTAKE 1350.0 /* km */ /* probably wrong... */


#endif
