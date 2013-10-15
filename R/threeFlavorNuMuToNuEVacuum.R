#!/usr/bin/env Rscript

dyn.load("../lib/libOscCalc.dylib");
enrgs   <- seq(from=0.2, to=10, by=0.01);
nen     <- length(enrgs);
probs   <- rep(0,nen);
baseln  <- 810.0;
matterc <- 1/4000.;
#matterc <- 1/1;

deltas <- seq(from=0.0, to=2*pi, by=pi/4);

for (deltacp in deltas) {

  helic   <- 1;

  hierarc <- 1;
  nu_atm_nrm <- .C("threeFlavorPatmVacuumArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);

  hierarc <- -1;
  nu_atm_inv <- .C("threeFlavorPatmVacuumArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);

  helic   <- -1;

  hierarc <- 1;
  antinu_atm_nrm <- .C("threeFlavorPatmVacuumArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);

  hierarc <- -1;
  antinu_atm_inv <- .C("threeFlavorPatmVacuumArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);

  pdftitle <- sprintf("threeFlavorNuMuToNuESolAtm_base%.1f_dcp%.3f.pdf", baseln, deltacp);
  dcplabel <- sprintf("Delta-CP = %.3f", deltacp);
  leglabels <- c(
      "Normal Neutrinos",
      "Normal Antineutrinos",
      "Inverted Neutrinos",
      "Inverted Antineutrinos");

  pdf( pdftitle );
  plot(nu_atm_nrm$energies,nu_atm_nrm$probabilities,
      main="Three-Flavor Muon-to-Electron Transition",
      xlab="Neutrino Energy (GeV)",
      ylab="Electrono Appearance Probability",
      xlim=c(0.2,10),
      ylim=c(0.0,0.08),
      col="red",
      type="l",
      log="x"
      );
  lines(antinu_atm_nrm$energies,antinu_atm_nrm$probabilities,
      col="red",
      lty=2,
      type="l");
  lines(nu_atm_inv$energies,nu_atm_inv$probabilities,
      col="blue",
      type="l");
  lines(antinu_atm_inv$energies,antinu_atm_inv$probabilities,
      col="blue",
      lty=2,
      type="l");
# Sadly, you just have to tune this carefully...
  legend(x=5, y=0.06, legend=leglabels, fill=c("red","red","blue","blue"), lty=c(1,2,1,2));
  text(x=6, y=0.04, labels=dcplabel);
  dev.off();

}
