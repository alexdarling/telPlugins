#if defined(STATIC_APP)
    #pragma comment(lib, "roadrunner-static.lib")
    #pragma comment(lib, "telplugins-static.lib")
#else
    #pragma comment(lib, "roadrunner.lib")
    #pragma comment(lib, "telplugins.lib")
#endif

#if defined(_MSC_VER)
    #pragma comment(lib, "poco_foundation-static.lib")
#endif


