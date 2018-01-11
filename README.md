# fiTQunYN

This framework starts from Andy's work.

++ message from Andy ++

1. Preprocessing - This step takes in the MC and data ROOT files and outputs ROOT files with augmented variables that are used later in the analysis. 

2. Spline generation - Makes splines that encode how each histogram bin changes as the the atmospheric flux and xsec parameters are varied.  This is used to make the MCMC step much faster

3. MCMC fit - Typically this must be done twice, once in MCMC mode, and then again in DE-MCMC mode (which uses a histogram of the results from MCMC mode).

4. ToyMC - Takes throws from the MCMC steps and applies them  to T2K MC.  Used to estimate systematics in each FV region.

5. FV Optimization - Evaluates the figure of merit to determine the FV cuts.

I think that Xiaoyue is working on her own atmospheric fit, which could conceivably replace steps 1-4.
+++++++++++++++++++++++
