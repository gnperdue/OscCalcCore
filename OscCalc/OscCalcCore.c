#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "OscCalcCore.h"

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
  printf("default_helicity  = %d\n", default_helicity); 
  printf("default_hierarchy = %d\n", default_hierarchy); 
  printf("default_deltaCP   = %f\n", default_deltaCP); 
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
  printf("default_theta12  = %f\n", default_theta12); 
  printf("default_theta23  = %f\n", default_theta23); 
  printf("default_theta13  = %f\n", default_theta13); 
  printf("default_baseline = %f\n", default_baseline); 
  printf("default_energy   = %f\n", default_energy); 


}


struct nuOscParams * create_default_nuOscParams()
{
  struct nuOscParams * params = malloc( sizeof( struct nuOscParams ) );
  assert( params != NULL );
  params->delta_m12_squared = default_dm12_squared;
  params->delta_m23_squared = default_dm23_squared_normal;
  params->delta_m13_squared = default_dm13_squared_normal;

  params->delta_m21_squared = default_dm12_squared;
  params->delta_m32_squared = default_dm32_squared_normal;
  params->delta_m31_squared = default_dm31_squared_normal;

  params->theta12 = default_theta12;
  params->theta23 = default_theta23;
  params->theta13 = default_theta13;

  params->hierarchy = default_hierarchy;  
  params->helicity = default_helicity;   

  params->deltaCP = default_deltaCP;

  params->defaultBaseline = default_baseline; 
  params->defaultEnergy = default_energy;  

  return params;
}


double getMass12Splitting( const struct nuOscParams * params )
{
  return params->delta_m12_squared;
}

double getMass23Splitting( const struct nuOscParams * params )
{
  double massSplitting = 0.0;
  /*
     static const double default_dm23_squared_inverted =  2.43e-3;
     static const double default_dm32_squared_inverted = -2.43e-3;
     if (params->helicity < 0) {
     massSplitting = params->
     } 
     else {

     }
     */
  return massSplitting;
}
