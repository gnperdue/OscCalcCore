
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
const int    default_helicity   = 1;     /* Normal */
const int    default_hierarchy  = 1;     /* Nu */
const double default_deltaCP    = 0.0;

/* 1-2 Splitting */
const double default_dm12_squared          = -7.50e-5;
const double default_dm21_squared          =  7.50e-5;

/* Normal Hierarchy Mass Splittings */
const double default_dm31_squared_normal   =    2.47e-3;
const double default_dm32_squared_normal   =    2.47e-3 - 7.50e-5;
const double default_dm13_squared_normal   =   -2.47e-3;
const double default_dm23_squared_normal   =  -(2.47e-3 - 7.50e-5);

/* Inverted Hierarchy Splittings */
const double default_dm32_squared_inverted =  -2.43e-3;
const double default_dm23_squared_inverted =   2.43e-3;
const double default_dm13_squared_inverted =   2.43e-3 - 7.50e-5;
const double default_dm31_squared_inverted = -(2.43e-3 - 7.50e-5);

/* Mixing Angles */
const double default_theta12  = 33.3 * 3.14159 / 180;
const double default_theta23  = 40.0 * 3.14159 / 180;
const double default_theta13  = 8.6 * 3.14159 / 180;
const double default_baseline = 735.0; /* km */

/* Default Experimental Parameters */
const double default_energy   = 2.0;   /* GeV */

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

  double defaultBaseline;  /* km, need a special mechanism to make m nice? */
  double defaultEnergy;    /* GeV, need a special concern for MeV? */
};

void printReferences();
void printDefaultParameters();

struct nuOscParams * create_default_nuOscParams();

double getMass12Splitting( const struct nuOscParams * params );
double getMass23Splitting( const struct nuOscParams * params );
