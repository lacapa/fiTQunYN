#ifndef T2KHISTOFACTORY_H
#define T2KHISTOFACTORY_H

#include "sharedPars.cxx"
#include "histoManager.h"
#include "t2kfqReader.h"
#include "shared.h"

using namespace std;

//class for building histograms from sorted data and mc trees
class t2kHistoFactory{
  public:

  t2kHistoFactory(int nsampl,int nbins,int ncomp,const char* name=""); //creates blank histogram factory
  t2kHistoFactory(const char* parfile, bool separateneutmode = false);//< initialize using parameters in par file
  t2kHistoFactory(int nsampl,int nbins,int ncomp,int nmode, bool separateneutmode, const std::string name = "");
  histoManager* hManager; 
  TChain* dataTree; //tree containing data events
  TChain* mcTree;  //tree conttaining MC events
  t2kfqReader* fqData;  //reads data tree
  t2kfqReader* fqMC; //reads MC tree
  TString nameTag; //name associated with this instance
  TFile*   fout; //output file for filled histograms
  TH1D*    htmp; //temporary histogram pointer for drawing and comparison
  TH1D*    hnorm;
  int nSamples; //number of data samples
  int nComponents; //number of MC components
  int nAttributes; //number of attributes (fiTQun outputs)
  int nBins;  //number of bins in data
  int nModes;
  bool separateNeutMode;
  int nDataEvents; //number of data events
  int nMCEvents;  //number of MC events
  double normMC; //normalization factor for MC
  double att[NATTMAX]; //array of all attribute values
  //TString attType[NATTMAX];  //array of attribute type codes
  void init();  //initialize after attributes have been set (sets branch addresses, creates histograms)
  //void addAttribute(int iatt);  //add an attribute (fiTQun variable) to list of histograms to be made
  TH1D* getHistogram(int iatt,const char* thename); //returns pointer to MC histogram
  TH1D* getHistogramData(int iatt,const char* thename); //returns pointer to Data histogram
  void fillAttributesData(); //fills all data histograms
  void fillAttributesMC();  //fills all MC histograms
  void fillHistos(); //fills all histograms
  //setters
  void setDataTree(TTree* tr);
  void setDataTree(TChain* ch);
  void setMCTree(TTree* tr);
  void setMCTree(TChain* ch);
  void saveToFile();
  TString outputFileName;
  TString getOutputFileName(){return outputFileName;}
  void setOutputFileName(const char *name){outputFileName=name;}
  void normalizeHistos(double scale=-1.);
  void runHistoFactory();
  TString parFileName;
  sharedPars* runpars;
};


#endif
