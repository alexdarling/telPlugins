#if defined(STATIC_APP)
    #pragma comment(lib, "roadrunner-static.lib")
    #pragma comment(lib, "telplugins-static.lib")
    #pragma comment(lib, "libsbml-static.lib")
    #pragma comment(lib, "libxml2_xe.lib")
    #pragma comment(lib, "sundials_cvode.lib")
    #pragma comment(lib, "sundials_nvecserial.lib")
    #pragma comment(lib, "nleq-static.lib")
    #pragma comment(lib, "libf2c.lib")
    #pragma comment(lib, "lapack.lib")
    #pragma comment(lib, "blas.lib")
    #pragma comment(lib, "rr-libstruct-static.lib")
#else
    #pragma comment(lib, "roadrunner.lib")
    #pragma comment(lib, "telplugins_core.lib")
    #pragma comment(lib, "telplugins_common.lib")
    #pragma comment(lib, "rrAutoInterface-static.lib")
#endif

#pragma comment(lib, "poco_foundation-static.lib")

