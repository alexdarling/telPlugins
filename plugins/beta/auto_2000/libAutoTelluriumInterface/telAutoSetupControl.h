#ifndef telAutoSetupControlH
#define telAutoSetupControlH
#include "telAutoInputConstants.h"
#include "tai_exporter.h"
//---------------------------------------------------------------------------

namespace rrauto
{

class RRAuto;

class RRA_DECLSPEC SetupControl
{
    friend RRAuto;

    public:
                                    SetupControl();
                                    /** This functions basically creates the auto input file fort.2
                                    */
        string                      getConstantsAsString();

    protected:
        InputConstants              mInputConstants;

        bool                        mCalculateSteadyState;
        bool                        mRunContinuation;
        bool                        mDirectionPositive;
};

}
#endif
