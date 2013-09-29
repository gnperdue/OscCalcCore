#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "OscCalcCore.h"

int main( int argc, char* argv[] ) 
{
  const int nenergies = 100;
  const double baseline = FNAL_TO_SOUDAN;

  printDefaultParameters();

  struct nuOscParams *params = create_default_nuOscParams();

  double energies[nenergies];
  double probabilities[nenergies];
  for (int i = 0; i < nenergies; ++i) {
    energies[i] = i * 0.1 + 0.1;
    probabilities[i] = twoFlavorMuSurvive(params, energies[i], baseline);
    printf("%0.2f  %0.5f\n", energies[i], probabilities[i]);
  }

  free(params);

  return 0;
}


