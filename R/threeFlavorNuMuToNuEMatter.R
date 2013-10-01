#!/usr/bin/env Rscript

dyn.load("../lib/libOscCalc.dylib");
enrgs   <- seq(from=0.5, to=8, by=0.025);
nen     <- length(enrgs);
probs   <- rep(0,nen);
baseln  <- 735.0;
matterc <- 1/4000.;

deltacp <- pi/4.;

hierarc <- 1;
oscpnrm <- .C("threeFlavorNuMuToNuEMatterArray_R",
  baseline=as.double(baseln),
  deltaCP=as.double(deltacp),
  matterConst=as.double(matterc),
  hierarchy=as.integer(hierarc),
  nenergies=as.integer(nen),
  energies=enrgs,probabilities=probs);

hierarc <- -1;
oscpinv <- .C("threeFlavorNuMuToNuEMatterArray_R",
  baseline=as.double(baseln),
  deltaCP=as.double(deltacp),
  matterConst=as.double(matterc),
  hierarchy=as.integer(hierarc),
  nenergies=as.integer(nen),
  energies=enrgs,probabilities=probs);


pdf("threeFlavorNuMuToNuEMatter.pdf");
plot(oscpnrm$energies,oscpnrm$probabilities,
  main="Three-Flavor Muon-to-Electron Transition",
  xlab="Neutrino Energy (GeV)",
  ylab="Electrono Appearance Probability",
  col="red",
  type="l");
lines(oscpinv$energies,oscpinv$probabilities,
  col="blue",
  type="l");
dev.off();

