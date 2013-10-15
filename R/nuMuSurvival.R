#!/usr/bin/env Rscript

dyn.load("../lib/libOscCalc.dylib");
enrgs     <- seq(from=0.01, to=5.01, by=0.01);
nen       <- length(enrgs);
baseln    <- 735.0;
deltacp   <- 0.0;
t23       <- 45 * pi / 180.;

probs2f   <- rep(0,nen);
oscprob2f <- .C("twoFlavorMuSurviveArray_R",
  baseline=as.double(baseln),
  nenergies=as.integer(nen),
  energies=enrgs,probabilities=probs2f);

probs3f   <- rep(0,nen);
oscprob3f <- .C("threeFlavorMuSurviveArray_R",
  baseline=as.double(baseln),
  deltaCP=as.double(deltacp),
  theta23=as.double(t23),
  nenergies=as.integer(nen),
  energies=enrgs,probabilities=probs3f);

pdftitle <- sprintf("nuMuSurvival_2f_base%.1f_dcp%.3f.pdf", baseln, deltacp);
pdf(pdftitle);
plot(oscprob2f$energies,oscprob2f$probabilities,
  main="Two-Flavor Muon-Neutrino Survival",
  xlab="Neutrino Energy (GeV)",
  ylab="Survival Probability",
  xlim=c(0.0,5.0),
  ylim=c(0.0,1.02),
  col="red",
  type="l");
dev.off();

pdftitle <- sprintf("nuMuSurvival_3f_base%.1f_dcp%.3f.pdf", baseln, deltacp);
pdf(pdftitle);
plot(oscprob3f$energies,oscprob3f$probabilities,
  main="Three-Flavor Muon-Neutrino Survival",
  xlab="Neutrino Energy (GeV)",
  ylab="Survival Probability",
  xlim=c(0.0,5.0),
  ylim=c(0.0,1.02),
  col="red",
  type="l");
dev.off();

