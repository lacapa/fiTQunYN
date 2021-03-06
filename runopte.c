
{

gROOT->ProcessLine(".L optimusPrime.cxx+");
gROOT->ProcessLine(".L fqProcessedEvent.cxx+");
gROOT->ProcessLine(".L mcLargeArray.cxx+");
gROOT->ProcessLine(".L TH2FV.cxx+");
gROOT->ProcessLine(".L summaryPlots.cxx+");
gROOT->ProcessLine(".L moreUncertainties.cxx+");

///////////////////////////////////////////////////////////////////////////
// parameters /////////////////////////////////////////////////////////////

// file names of processed T2K MC
TString T2KMCFiles = "/nfs/data41/t2k/amissert/t2kmc/processed/feb23pass_1rpi/*.root";
//TString T2KMCFiles = "/nfs/data41/t2k/amissert/t2kmc/processed/feb20pass/*.root";

// card file name for other settings
TString CardFileName = "wetrun.dat";

// file name(s) for MCMC parameters
TString MCMCParFileName = "/nfs/data41/t2k/amissert/atmos/head/atmFitTools/run/results/dryrun/mcmcfit_summary_sample.root";

// directory to find additional uncertainty files (entering bg, etc)
TString DataFileDirectory = "/nfs/data41/t2k/amissert/atmos/head/atmFitTools/data/official/";

// name of uncertainty map file generated by toy MC
TString UncertaintyMapFile = "FVUncMapNuE.root";

// max # of events to use
//int     NMaxMCEvents = 50010;
int     NMaxMCEvents = 2e9;

int IndexPIDPar = 0;
int IndexPi0Par = 1;
int IndexPiPPar = 2;
int IndexRCPar = -1;

//////////////////////////////////////////////////////////////////////////////


// chain setup
TChain ch("h1");
ch.Add(T2KMCFiles.Data());

// optimizer setup
optimusPrime* opt = new optimusPrime(&ch,NMaxMCEvents,DataFileDirectory.Data(),UncertaintyMapFile.Data());
opt->cardFileName = CardFileName.Data();
opt->mcmcParFileName = MCMCParFileName.Data(); 
opt->indexPIDPar = IndexPIDPar;
opt->indexPi0Par = IndexPi0Par;
opt->indexPiPPar = IndexPiPPar;
opt->indexRCPar = IndexRCPar;


}


