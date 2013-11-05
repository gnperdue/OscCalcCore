#!/usr/bin/env Rscript

# Reproduce some plots from http://arxiv.org/abs/1311.0212

dyn.load("../lib/libOscCalc.dylib");
enrgs   <- seq(from=0.01, to=10, by=0.001);
nen     <- length(enrgs);
probs   <- rep(0,nen);
matterc <- 1/4000.;
deltacp <- 0.;


helic   <- 1;
hierarc <- 1;

baseln  <- 1000;
nu_oscp_nrm1000 <- .C("threeFlavorNuMuToNuEMatterArray_R",
    baseline=as.double(baseln),
    deltaCP=as.double(deltacp),
    matterConst=as.double(matterc),
    hierarchy=as.integer(hierarc),
    helicity=as.integer(helic),
    nenergies=as.integer(nen),
    energies=enrgs,probabilities=probs);

baseln  <- 2000;
nu_oscp_nrm2000 <- .C("threeFlavorNuMuToNuEMatterArray_R",
    baseline=as.double(baseln),
    deltaCP=as.double(deltacp),
    matterConst=as.double(matterc),
    hierarchy=as.integer(hierarc),
    helicity=as.integer(helic),
    nenergies=as.integer(nen),
    energies=enrgs,probabilities=probs);

baseln  <- 3000;
nu_oscp_nrm3000 <- .C("threeFlavorNuMuToNuEMatterArray_R",
    baseline=as.double(baseln),
    deltaCP=as.double(deltacp),
    matterConst=as.double(matterc),
    hierarchy=as.integer(hierarc),
    helicity=as.integer(helic),
    nenergies=as.integer(nen),
    energies=enrgs,probabilities=probs);

hierarc <- -1;

baseln  <- 3000;
nu_oscp_inv3000 <- .C("threeFlavorNuMuToNuEMatterArray_R",
    baseline=as.double(baseln),
    deltaCP=as.double(deltacp),
    matterConst=as.double(matterc),
    hierarchy=as.integer(hierarc),
    helicity=as.integer(helic),
    nenergies=as.integer(nen),
    energies=enrgs,probabilities=probs);

pdftitle <- sprintf("threeFlavorNuMuToNuEMatter_PvsLovrE_fig1.pdf");
leglabels <- c(
    "Matter Effect at 1000 km, NH"
    ,"Matter Effect at 2000 km, NH"
    ,"Matter Effect at 3000 km, NH"
    ,"Matter Effect at 3000 km, IH"
    );

pdf( pdftitle );

plot(1000/nu_oscp_nrm1000$energies,nu_oscp_nrm1000$probabilities
    ,main="Three-Flavor Muon-to-Electron Transition"
    ,xlab="Baseline/Neutrino Energy (km/GeV)"
    ,ylab="Electrono Appearance Probability"
    ,xlim=c(1,5000)
    ,ylim=c(0.0,0.2)
    ,col="black"
    ,type="l"
    ,lty=5
    ,lwd=2
    );
lines(2000/nu_oscp_nrm2000$energies,nu_oscp_nrm2000$probabilities
    ,col="red"
    ,lty=3
    ,lwd=2
    ,type="l"
    );
lines(3000/nu_oscp_nrm3000$energies,nu_oscp_nrm3000$probabilities
    ,col="blue"
    ,lty=4
    ,lwd=2
    ,type="l"
    );
lines(3000/nu_oscp_inv3000$energies,nu_oscp_inv3000$probabilities
    ,col="green"
    ,lty=6
    ,lwd=2
    ,type="l"
    );
legend(x=500, y=0.18, legend=leglabels, fill=c("black","red","blue","green"), lty=c(5,3,4,6));
dev.off();



