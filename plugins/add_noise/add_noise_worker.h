#ifndef add_noise_workerH
#define add_noise_workerH
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "telExporter.h"
//---------------------------------------------------------------------------

namespace addNoise
{

class AddNoise;

class AddNoiseWorker : public Poco::Runnable
{
    protected:
        Poco::Thread            mThread;
        AddNoise&               mTheHost;

    public:
                                AddNoiseWorker(AddNoise& mTheHost);
        bool                    start(bool runInThread = true);
        void                    run();
        bool                    isRunning() const;
};

}
#endif
