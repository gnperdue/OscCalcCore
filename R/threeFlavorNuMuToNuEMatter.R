#!/usr/bin/env Rscript

dyn.load("../lib/libOscCalc.dylib");
enrgs   <- seq(from=0.5, to=8, by=0.025);
nen     <- length(enrgs);
probs   <- rep(0,nen);
baseln  <- 735.0;
matterc <- 1/4000.;

deltas <- seq(from=0.0, to=2*pi, by=pi/4);

for (deltacp in deltas) {

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

  pdftitle <- sprintf("threeFlavorNuMuToNuEMatter_base%.1f_dcp%.3f.pdf", baseln, deltacp);
  dcplabel <- sprintf("Delta-CP = %.3f", deltacp);
  leglabels <- c("Normal Hierarchy","Inverted Hierarchy");

  pdf( pdftitle );
  plot(oscpnrm$energies,oscpnrm$probabilities,
      main="Three-Flavor Muon-to-Electron Transition",
      xlab="Neutrino Energy (GeV)",
      ylab="Electrono Appearance Probability",
      xlim=c(0.5,8),
      ylim=c(0.0,0.08),
      col="red",
      type="l");
  lines(oscpinv$energies,oscpinv$probabilities,
      col="blue",
      type="l");
# Sadly, you just have to tune this carefully...
  legend(x=5, y=0.06, legend=leglabels, fill=c("red","blue"));
  text(x=6, y=0.04, labels=dcplabel);
  dev.off();

}
