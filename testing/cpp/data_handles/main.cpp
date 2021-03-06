#include <iostream>
#include "rrRoadRunner.h"
#include "rrException.h"
#include "rrUtils.h"
#include "rrLogger.h"
using namespace rr;

int main(int argc, char** argv)
{
    const char* rootPath = "r:\\";

    try
    {
        gLog.setLevel(lInfo);
        const string modelFile = joinPath(rootPath, "models", "test_1.xml");

        //Load modelFiles..
        Log(lInfo)<<" ---------- LOADING/GENERATING MODELS ------";

        RoadRunner rr1;
        LoadSBMLOptions opt;
        opt.modelGeneratorOpt |= LoadSBMLOptions::RECOMPILE;
        if(!rr1.load(modelFile, &opt))
        {
            Log(Logger::LOG_ERROR)<<"There was a problem loading model in file: "<<modelFile;
            throw(Exception("Bad things in loadSBMLFromFile function"));
        }

        Log(lInfo)<<" ---------- SIMULATE ---------------------";
        Log(lInfo)<<"Data:"<<*(rr1.simulate());
    }
    catch(const exception& ex)
    {

        Log(Logger::LOG_ERROR)<<"There was a  problem: "<<ex.what();
    }

    return 0;
}


#pragma comment(lib, "roadrunner.lib")

