#ifndef telSimulateThreadH
#define telSimulateThreadH
#include <list>
#include "Poco/Condition.h"
#include "rreRoadRunnerThread.h"
#include "rreSettings.h"
//---------------------------------------------------------------------------

namespace rre
{

typedef void    (rreCallbackCC *JobStartedCB)(void*);
typedef void    (rreCallbackCC *JobFinishedCB)(void*);

using std::list;
using Poco::Mutex;
using Poco::Condition;

class RRE_DECLSPEC SimulateThread : public RoadRunnerThread
{

    protected:
        static list<RoadRunner*>    mJobs;
        static Mutex                mJobsMutex;
        static Condition            mJobsCondition;
        void                        signalAll();
        void                        signalExit();
        bool                        mSimulateEx;
        static Poco::Mutex          mNrOfWorkersMutex;
        static int                  mNrOfWorkers;        //incremented when entering worker function and decremented when exiting
        JobStartedCB                mJobStartedCB;
        JobFinishedCB               mJobFinishedCB;
        int                         mNrPoints;
        double                      mTimeStart;
        double                      mTimeEnd;
        void*                       mUserData;


    public:
                                    SimulateThread( RoadRunner* rri = NULL,
                                                    const double& ts = 0,
                                                    const double& te = 0,
                                                    const int& nrPoints = 0,
                                                    JobStartedCB f1 = NULL,
                                                    JobFinishedCB f2 = NULL,
                                                    void* userData = NULL,
                                                    bool autoStart = false);
                                   ~SimulateThread();

        void                        worker();
        void                        addJob(RoadRunner* rr);
        unsigned int                getNrOfJobsInQueue();
        bool                        isAnyWorking();
        bool                        isWorking();
};

}
#endif
