#ifndef PHOTON_ANALYZER_H
#define PHOTON_ANALYZER_H
#include "DataFormats/PatCandidates/interface/Photon.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Event.h"

#include "heavyNeutrino/multilep/plugins/multilep.h"

#include "TTree.h"

class multilep;

class PhotonAnalyzer {
  private:
    static const unsigned nPhoton_max = 5;

    unsigned _nPh;
    double   _phPt[nPhoton_max];
    double   _phEta[nPhoton_max];
    double   _phPhi[nPhoton_max];
    double   _phE[nPhoton_max];
    bool     _phCutBasedLoose[nPhoton_max];
    bool     _phCutBasedMedium[nPhoton_max];
    bool     _phCutBasedTight[nPhoton_max];
    double   _phMva[nPhoton_max];
    double   _phChargedIsolation[nPhoton_max];
    double   _phNeutralHadronIsolation[nPhoton_max];
    double   _phPhotonIsolation[nPhoton_max];
    double   _phSigmaIetaIeta[nPhoton_max];
    double   _phHadronicOverEm[nPhoton_max];
    bool     _phPassElectronVeto[nPhoton_max];
    bool     _phHasPixelSeed[nPhoton_max];
    bool     _phIsPrompt[nPhoton_max];

    void fillPhotonGenVars(const reco::GenParticle*);
    multilep* multilepAnalyzer;

  public:
    PhotonAnalyzer(const edm::ParameterSet& iConfig, multilep* vars);
    ~PhotonAnalyzer();

    void beginJob(TTree* outputTree);
    bool analyze(const edm::Event&);
};

#endif
