//We only need to give the linker the folder where libs are
//using the pragma comment. Automatic linking, using pragma comment works for MSVC and codegear

#if defined(RRP_STATIC)
    #pragma comment(lib, "roadrunner-static.lib")
    #pragma comment(lib, "roadrunner_c_api-static.lib")
    #pragma comment(lib, "telplugins-static.lib")
#else
    #pragma comment(lib, "roadrunner.lib")
    #pragma comment(lib, "roadrunner_c_api.lib")
    #pragma comment(lib, "telplugins.lib")
#endif

#pragma comment(lib, "telutils-static.lib")
#pragma comment(lib, "sundials_cvode.lib")
#pragma comment(lib, "sundials_nvecserial.lib")
#pragma comment(lib, "nleq-static.lib")
#pragma comment(lib, "rr-libstruct-static.lib")
#pragma comment(lib, "libsbml-static.lib")
#pragma comment(lib, "libxml2_xe.lib")
#pragma comment(lib, "blas.lib")
#pragma comment(lib, "lapack.lib")
#pragma comment(lib, "libf2c.lib")
#pragma comment(lib, "poco_foundation-static.lib")


#if defined(_WIN32)
#pragma comment(lib, "IPHLPAPI.lib") //Becuase of poco needing this
#endif
