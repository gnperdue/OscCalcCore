#!/usr/bin/env Rscript

dyn.load("../lib/libOscCalc.dylib");
enrgs   <- seq(from=0.025, to=8, by=0.025);
nen     <- length(enrgs);
probs   <- rep(0,nen);
baseln  <- 735.0;
oscprob <- .C("twoFlavorMuSurviveArray_R",
  baseline=as.double(baseln),
  nenergies=as.integer(nen),
  energies=enrgs,probabilities=probs);

pdf("twoFlavorNuMuSurvival.pdf");
plot(oscprob$energies,oscprob$probabilities,
  main="Two-Flavor Muon-Neutrino Survival",
  xlab="Neutrino Energy (GeV)",
  ylab="Survival Probability",
  col="red",
  type="l");
dev.off();

