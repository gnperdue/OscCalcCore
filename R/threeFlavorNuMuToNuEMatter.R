#!/usr/bin/env Rscript

dyn.load("../lib/libOscCalc.dylib");
enrgs   <- seq(from=0.2, to=10, by=0.01);
nen     <- length(enrgs);
probs   <- rep(0,nen);
baseln  <- 810.0;
matterc <- 1/4000.;

deltas <- seq(from=0.0, to=2*pi, by=pi/4);

for (deltacp in deltas) {

  helic   <- 1;
  hierarc <- 1;
  nu_oscp_nrm <- .C("threeFlavorNuMuToNuEMatterArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      matterConst=as.double(matterc),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);
  hierarc <- -1;
  nu_oscp_inv <- .C("threeFlavorNuMuToNuEMatterArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      matterConst=as.double(matterc),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);

  helic   <- -1;
  hierarc <- 1;
  antinu_oscp_nrm <- .C("threeFlavorNuMuToNuEMatterArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      matterConst=as.double(matterc),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);
  hierarc <- -1;
  antinu_oscp_inv <- .C("threeFlavorNuMuToNuEMatterArray_R",
      baseline=as.double(baseln),
      deltaCP=as.double(deltacp),
      matterConst=as.double(matterc),
      hierarchy=as.integer(hierarc),
      helicity=as.integer(helic),
      nenergies=as.integer(nen),
      energies=enrgs,probabilities=probs);

  pdftitle <- sprintf("threeFlavorNuMuToNuEMatter_base%.1f_dcp%.3f.pdf", baseln, deltacp);
  dcplabel <- sprintf("Delta-CP = %.3f", deltacp);
  bllabel  <- sprintf("Baseline = %.3f km", baseln);
  leglabels <- c(
      "Normal Neutrinos",
      "Normal Antineutrinos",
      "Inverted Neutrinos",
      "Inverted Antineutrinos");

  pdf( pdftitle );
  plot(nu_oscp_nrm$energies,nu_oscp_nrm$probabilities,
      main="Three-Flavor Muon-to-Electron Transition",
      xlab="Neutrino Energy (GeV)",
      ylab="Electrono Appearance Probability",
      xlim=c(0.2,10),
      ylim=c(0.0,0.08),
      col="red",
      type="l",
      log="x"
      );
  lines(antinu_oscp_nrm$energies,antinu_oscp_nrm$probabilities,
      col="red",
      lty=2,
      type="l");
  lines(nu_oscp_inv$energies,nu_oscp_inv$probabilities,
      col="blue",
      type="l");
  lines(antinu_oscp_inv$energies,antinu_oscp_inv$probabilities,
      col="blue",
      lty=2,
      type="l");
# Sadly, you just have to tune this carefully...
  legend(x=1.5, y=0.08, legend=leglabels, fill=c("red","red","blue","blue"), lty=c(1,2,1,2));
  text(x=3, y=0.06, labels=dcplabel);
  text(x=3, y=0.055, labels=bllabel);
  dev.off();

}
