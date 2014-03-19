#ifndef telAutoWorkerH
#define telAutoWorkerH
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "rr/rrRoadRunner.h"
#include "rr/rrOSSpecifics.h"
#include "telTelluriumData.h"
#include "auto_utils.h"
//---------------------------------------------------------------------------

namespace telauto
{
class AutoTellurimInterface;
}

typedef void (*ThreadCB)(void*, void*);

class AutoPlugin;
using tlp::TelluriumData;

class AutoWorker : public Poco::Runnable
{
    public:
                                                    AutoWorker(AutoPlugin& host);
                                                   ~AutoWorker();
        bool                                        start(bool runInThread = false);
        void                                        run();
        bool                                        isRunning() const;

    protected:
        Poco::Thread                                mThread;
        AutoPlugin&                                 mTheHost;
        telauto::AutoTellurimInterface&             mRRAuto;        //This class communicate with auto

        bool                                        setup();
};

#endif