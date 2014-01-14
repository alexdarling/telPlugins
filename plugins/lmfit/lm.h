#ifndef lmH
#define lmH
#include <vector>
#include "telProperty.h"
#include "telCPPPlugin.h"
#include "rr/rrRoadRunner.h"
#include "rr/c/rrc_types.h"
#include "LMWorker.h"
#include "lib/lmmin.h"
//---------------------------------------------------------------------------

namespace lmfit
{
using namespace rrc;
using namespace tlp;
using rr::RoadRunner;
using std::string;

class LM : public CPPPlugin
{
    friend class LMWorker;

    public:
        Property<string>                        mSBML;                          //This is the model
        Property<RoadRunnerData>				mExperimentalData;
        Property<RoadRunnerData>			    mModelData;
        Property<RoadRunnerData>			    mResidualsData;
        Property<Properties>                    mInputParameterList;            //Parameters to fit
        Property<Properties>                    mOutputParameterList;           //Parameters that was fitted
        Property<tlp::StringList>                mExperimentalDataSelectionList; //Species selection list for observed data
        Property<tlp::StringList>                mModelDataSelectionList;        //Species selection list for observed data
        Property<double>                        mNorm;                          //Part of minimization result
        Property<int>                           mNrOfIter;                      //Part of minimization result

        //LMFIT Tuning parameters
        Property<double>                        ftol;                           /* relative error desired in the sum of squares. */
        Property<double>                        xtol;                           /* relative error between last two approximations. */
        Property<double>                        gtol;                           /* orthogonality desired between fvec and its derivs. */
        Property<double>                        epsilon;                        /* step used to calculate the jacobian. */
        Property<double>                        stepbound;                      /* initial bound to steps in the outer loop. */
        Property<int>                           patience;                       /* maximum number of iterations. */
//        Property<int>                           scale_diag;                   /* UNDOCUMENTED, TESTWISE automatical diag rescaling? */

		//Utility functions for the thread
        string                                  getTempFolder();
        string                                  getSBML();

		lmDataStructure							&mLMData;        //LevenbergMarq.. data structure
    protected:
        //The worker is doing the work
        LMWorker                                mLMWorker;

        lm_status_struct                        mLMStatus;      //Check afterwards.
    public:
                                                LM();
                                               ~LM();

        bool                                    execute(bool inThread = false);
        string                                  getResult();
        bool                                    resetPlugin();
        string                                  getImplementationLanguage();
        string                                  getStatus();
        bool                                    isWorking() const;

        unsigned char*                          getManualAsPDF() const;
        unsigned int                            getPDFManualByteSize();
        tlp::StringList                          getExperimentalDataSelectionList();
        void                                    assignPropertyDescriptions();
};

extern "C"
{
RR_PLUGIN_DECLSPEC LM*         plugins_cc       createPlugin();
RR_PLUGIN_DECLSPEC const char* plugins_cc       getImplementationLanguage();
}
}
#endif
