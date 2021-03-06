#ifndef OscCalcCore_c
#define OscCalcCore_c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "OscCalcCore.h"
#include "OscCalcDefs.h"

double twoFlavorMuSurvive( const struct nuOscParams* pp, double en, double bl )
{
  assert(en > 0);
  double sdelta23 = sin( Delta23( pp, bl/en ) );
  return 1 - SinSqrd2Theta23(pp) * sdelta23 * sdelta23; 
}

double threeFlavorMuSurvive( const struct nuOscParams* pp, double en, double bl )
{
  return 1 - threeFlavorMuDisappear(pp,en,bl);
}

double threeFlavorMuDisappear( const struct nuOscParams* pp, double en, double bl )
{
  assert(en > 0);
  double l_over_e = bl/en;
  double umu1sqrd = Umu1Sqrd(pp);
  double umu2sqrd = Umu2Sqrd(pp);
  double umu3sqrd = Umu3Sqrd(pp);
  double sdelta21 = sin( Delta21( pp, l_over_e ) );
  double sdelta31 = sin( Delta31( pp, l_over_e ) );
  double sdelta32 = sin( Delta32( pp, l_over_e ) );
  return 4 * (
      umu3sqrd*umu1sqrd*sdelta31*sdelta31
      + umu3sqrd*umu2sqrd*sdelta32*sdelta32
      + umu2sqrd*umu1sqrd*sdelta21*sdelta21
      );
} 

double threeFlavorEDisappear( const struct nuOscParams* pp, double en, double bl ) 
{
  assert(en > 0);
  double l_over_e = bl/en;
  double ue1sqrd = Ue1Sqrd(pp);
  double ue2sqrd = Ue2Sqrd(pp);
  double ue3sqrd = Ue3Sqrd(pp);
  double sdelta21 = sin( Delta21( pp, l_over_e ) );
  double sdelta31 = sin( Delta31( pp, l_over_e ) );
  double sdelta32 = sin( Delta32( pp, l_over_e ) );
  return 1 - 4 * (
      ue3sqrd*ue1sqrd*sdelta31*sdelta31
      + ue3sqrd*ue2sqrd*sdelta32*sdelta32
      + ue2sqrd*ue1sqrd*sdelta21*sdelta21
      );
}

double threeFlavorNuMuToNuEMatter( const struct nuOscParams* pp, 
    double en, double bl, double mc ) 
{
  assert(en > 0);
  double         l_over_e   = bl/en;
  double         aL         = pp->helicity > 0 ? bl * mc : -1.0 * bl * mc; 
  assert(aL != 0.);
  double         d31        = Delta31( pp, l_over_e );
  double         d32        = Delta32( pp, l_over_e );
  double         d21        = Delta21( pp, l_over_e );
  double         dlt        = pp->helicity > 0 ? pp->deltaCP : -1.0 * pp->deltaCP;
  double complex sqrt_p_atm = sin(pp->theta13) * sin(2*pp->theta23) * sin( d31 - aL )/( d31 - aL ) * d31 + 0.*I;
  double complex sqrt_p_sol = cos(pp->theta23) * sin(2*pp->theta12) * sin( aL )/( aL ) * d21 + 0.*I;
  double complex t1         = cos( d32 + dlt ) - sin( d32 + dlt )*I;
  double complex sum        = sqrt_p_atm * t1 + sqrt_p_sol;
  double         val        = sum*conj(sum);
  return val;
}

double threeFlavorNuMuToNuEVacuum( const struct nuOscParams* pp, double en, double bl ) 
{
  assert(en > 0);
  double         l_over_e = bl/en;
  double         d32      = Delta32( pp, l_over_e );
  double complex t1       = cos( d32 ) - sin( d32 )*I;
  double complex sum      = threeFlavorPatmVacuum(pp,en,bl)*t1 + 
    threeFlavorPsolVacuum(pp,en,bl);
  double         val      = sum*conj(sum);
  return val;
}

double complex threeFlavorPatmVacuum( const struct nuOscParams* pp, double en, double bl ) 
{
  assert(en > 0);
  double         l_over_e   = bl/en;
  double complex umu3dagger = conj( Ufm(pp,2,3) );
  double complex ue3        = Ufm(pp,1,3);
  double complex s1         = 2 * sin( Delta31(pp,l_over_e) ) + 0.*I;
  return umu3dagger*ue3*s1;
}

double complex threeFlavorPsolVacuum( const struct nuOscParams* pp, double en, double bl ) 
{
  assert(en > 0);
  double         l_over_e   = bl/en;
  double complex umu2dagger = conj( Ufm(pp,2,2) );
  double complex ue2        = Ufm(pp,1,2);
  double complex s2         = 2 * sin( Delta21(pp,l_over_e) ) + 0.*I;
  return umu2dagger*ue2*s2;
}


struct nuOscParams * create_default_nuOscParams()
{
  struct nuOscParams * params = malloc( sizeof( struct nuOscParams ) );
  assert( params != NULL );
  params->delta_m12_squared = default_dm12_squared;
  params->delta_m23_squared = default_dm23_squared_normal;
  params->delta_m13_squared = default_dm13_squared_normal;
  params->delta_m21_squared = default_dm21_squared;
  params->delta_m32_squared = default_dm32_squared_normal;
  params->delta_m31_squared = default_dm31_squared_normal;
  params->theta12           = default_theta12;
  params->theta23           = default_theta23;
  params->theta13           = default_theta13;
  params->hierarchy         = default_hierarchy;  
  params->helicity          = default_helicity;   
  params->deltaCP           = default_deltaCP;
  return params;
}

void printNuOscParams( const struct nuOscParams* params )
{
  printf("Nu Osc Params:\n");
  printf(" Delta M12^2 = %f\n", params->delta_m12_squared);
  printf(" Delta M23^2 = %f\n", params->delta_m23_squared);
  printf(" Delta M13^2 = %f\n", params->delta_m13_squared);
  printf(" Delta M21^2 = %f\n", params->delta_m21_squared);
  printf(" Delta M32^2 = %f\n", params->delta_m32_squared);
  printf(" Delta M31^2 = %f\n", params->delta_m31_squared);
  printf(" Theta 12    = %f\n", params->theta12);
  printf(" Theta 23    = %f\n", params->theta23);
  printf(" Theta 13    = %f\n", params->theta13);
  printf(" Hierarchy   = %d\n", params->hierarchy);
  printf(" Helicity    = %d\n", params->helicity);
  printf(" Delta CP    = %f\n", params->deltaCP);
  printf("\n");
}

void printReferences() 
{
  printf("%s\n", theta12Reference);
  printf("%s\n", theta23Reference);
  printf("%s\n", theta13Reference);
  printf("%s\n", deltaM12Reference);
  printf("%s\n", deltaM23Reference);
  printf("%s\n", deltaM13Reference);
  printf("%s\n", globalFitsRef);
}

void printDefaultParameters()
{
  printf("default_helicity              = %d\n", default_helicity); 
  printf("default_hierarchy             = %d\n", default_hierarchy); 
  printf("default_deltaCP               = %f\n", default_deltaCP); 
  printf("default_dm12_squared          = %f\n", 
      default_dm12_squared); 
  printf("default_dm21_squared          = %f\n", 
      default_dm21_squared); 
  printf("default_dm31_squared_normal   = %f\n", 
      default_dm31_squared_normal); 
  printf("default_dm32_squared_normal   = %f\n", 
      default_dm32_squared_normal); 
  printf("default_dm13_squared_normal   = %f\n", 
      default_dm13_squared_normal); 
  printf("default_dm23_squared_normal   = %f\n", 
      default_dm23_squared_normal); 
  printf("default_dm32_squared_inverted = %f\n", 
      default_dm32_squared_inverted); 
  printf("default_dm23_squared_inverted = %f\n", 
      default_dm23_squared_inverted); 
  printf("default_dm13_squared_inverted = %f\n", 
      default_dm13_squared_inverted); 
  printf("default_dm31_squared_inverted = %f\n", 
      default_dm31_squared_inverted); 
  printf("default_theta12               = %f\n", default_theta12); 
  printf("default_theta23               = %f\n", default_theta23); 
  printf("default_theta13               = %f\n", default_theta13); 
}

void invert_hierarchy( struct nuOscParams * params )
{
  assert(0 != params->hierarchy);
  params->hierarchy = -params->hierarchy;
  if (params->hierarchy > 0) {
    params->delta_m23_squared = default_dm23_squared_normal;
    params->delta_m13_squared = default_dm13_squared_normal;
    params->delta_m32_squared = default_dm32_squared_normal;
    params->delta_m31_squared = default_dm31_squared_normal;
  } 
  else {
    params->delta_m23_squared = default_dm23_squared_inverted;
    params->delta_m13_squared = default_dm13_squared_inverted;
    params->delta_m32_squared = default_dm32_squared_inverted;
    params->delta_m31_squared = default_dm31_squared_inverted;
  }
}

double SinSqrd2Theta12( const struct nuOscParams * pp ) { 
  double Theta12 = pp->theta12;
  return sin( 2 * Theta12 ) * sin( 2 * Theta12 ); 
}

double SinSqrd2Theta13( const struct nuOscParams * pp ) { 
  double Theta13 = pp->theta13;
  return sin( 2 * Theta13 ) * sin( 2 * Theta13 ); 
}

double SinSqrd2Theta23( const struct nuOscParams * pp ) { 
  double Theta23 = pp->theta23;
  return sin( 2 * Theta23 ) * sin( 2 * Theta23 ); 
}

double SinSqrdTheta23( const struct nuOscParams * pp )  { 
  double Theta23 = pp->theta23;
  return sin( Theta23 ) * sin( Theta23 ); 
}

double CosSqrdTheta23( const struct nuOscParams * pp )  { 
  double Theta23 = pp->theta23;
  return cos( Theta23 ) * cos( Theta23 ); 
}

/* L in km, E in GeV */
double Delta12( const struct nuOscParams * pp, double LovrE ) { 
  return L_OVER_E_CONVERTER * pp->delta_m12_squared * LovrE; 
}

double Delta13( const struct nuOscParams * pp, double LovrE ) { 
  return L_OVER_E_CONVERTER * pp->delta_m13_squared * LovrE; 
}

double Delta23( const struct nuOscParams * pp, double LovrE ) { 
  return L_OVER_E_CONVERTER * pp->delta_m23_squared * LovrE; 
}

double Delta21( const struct nuOscParams * pp, double LovrE ) { 
  return L_OVER_E_CONVERTER * pp->delta_m21_squared * LovrE; 
}

double Delta31( const struct nuOscParams * pp, double LovrE ) { 
  return L_OVER_E_CONVERTER * pp->delta_m31_squared * LovrE; 
}

double Delta32( const struct nuOscParams * pp, double LovrE ) { 
  return L_OVER_E_CONVERTER * pp->delta_m32_squared * LovrE; 
}

/* Convenience Functions for Sines and Cosines of mixing angles & \delta_{CP}. */
double  s12( const struct nuOscParams * pp ) { 
  return sin( pp->theta12 ); 
}

double  s13( const struct nuOscParams * pp ) { 
  return sin( pp->theta13 ); 
}

double  s23( const struct nuOscParams * pp ) { 
  return sin( pp->theta23 ); 
}

double  c12( const struct nuOscParams * pp ) { 
  return cos( pp->theta12 ); 
}

double  c13( const struct nuOscParams * pp ) { 
  return cos( pp->theta13 ); 
}

double  c23( const struct nuOscParams * pp ) { 
  return cos( pp->theta23 ); 
}

double cdlt( const struct nuOscParams * pp ) { 
  double dlt = pp->helicity > 0.0 ? pp->deltaCP : -1.0 * pp->deltaCP;
  return cos( dlt ); 
}

double sdlt( const struct nuOscParams * pp ) { 
  double dlt = pp->helicity > 0.0 ? pp->deltaCP : -1.0 * pp->deltaCP;
  return sin( dlt ); 
}

#define S12 s12(pp)
#define S13 s13(pp)
#define S23 s23(pp)
#define C12 c12(pp)
#define C13 c13(pp)
#define C23 c23(pp)
#define CDLT cdlt(pp)
#define SDLT sdlt(pp)
double complex Ufm( const struct nuOscParams * pp, int flavor, int mass )
{
  /* |   e1   e2   e3 | */
  /* |  mu1  mu2  mu3 | */
  /* | tau1 tau2 tau3 | */
  double real = 0.;
  double im   = 0.;
  if( 1==flavor && 1==mass ) { // e1
    real = C13*C12;
  }
  else if( 2==flavor && 1==mass ) { // mu1 
    real = -C23*S12 - S13*C12*S23*CDLT;
    im   = -S13*C12*S23*SDLT;
  }
  else if( 3==flavor && 1==mass ) { // tau1 
    real = S23*S12 - S13*C12*C23*CDLT;
    im   = -S13*C12*C23*SDLT;
  }
  else if( 1==flavor && 2==mass ) { // e2
    real = C13*S12;
  }
  else if( 2==flavor && 2==mass ) { // mu2
    real = C23*C12 - S13*S12*S23*CDLT;
    im   = -S13*S12*S23*SDLT;
  }
  else if( 3==flavor && 2==mass ) { // tau2
    real = -S23*C12 - S13*S12*C23*CDLT;
    im   = -S13*S12*C23*SDLT;
  }
  else if( 1==flavor && 3==mass ) { // e3
    real = S13*CDLT;
    im   = -S13*SDLT;
  }
  else if( 2==flavor && 3==mass ) { // mu3
    real = C13*S23;
  }
  else if( 3==flavor && 3==mass ) { // tau3
    real = C13*C23;
  }
  double complex retval = real +  im*I;
  return retval;
}

double Ue1Sqrd( const struct nuOscParams * pp )   { 
  return fabs( Ufm(pp,1,1)*conj(Ufm(pp,1,1)) ); 
}

double Ue2Sqrd( const struct nuOscParams * pp )   { 
  return fabs( Ufm(pp,1,2)*conj(Ufm(pp,1,2)) ); 
}

double Ue3Sqrd( const struct nuOscParams * pp )   { 
  return fabs( Ufm(pp,1,3)*conj(Ufm(pp,1,3)) ); 
}

double Umu1Sqrd( const struct nuOscParams * pp )  { 
  return fabs( Ufm(pp,2,1)*conj(Ufm(pp,2,1)) ); 
}

double Umu2Sqrd( const struct nuOscParams * pp )  { 
  return fabs( Ufm(pp,2,2)*conj(Ufm(pp,2,2)) ); 
}

double Umu3Sqrd( const struct nuOscParams * pp )  { 
  return fabs( Ufm(pp,2,3)*conj(Ufm(pp,2,3)) ); 
}

double Utau1Sqrd( const struct nuOscParams * pp ) { 
  return fabs( Ufm(pp,3,1)*conj(Ufm(pp,3,1)) ); 
}

double Utau2Sqrd( const struct nuOscParams * pp ) { 
  return fabs( Ufm(pp,3,2)*conj(Ufm(pp,3,2)) ); 
}

double Utau3Sqrd( const struct nuOscParams * pp ) { 
  return fabs( Ufm(pp,3,3)*conj(Ufm(pp,3,3)) ); 
}

#endif
