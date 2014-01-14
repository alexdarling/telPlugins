#ifndef rrAutoDataH
#define rrAutoDataH
#include <ostream>
#include "rrRRAutoExporter.h"
#include "../utils/telStringList.h"
#include "rr/rrRoadRunnerData.h"
#include "telProperty.h"
#include "telProperties.h"
#include "rr/rrLogger.h"
//---------------------------------------------------------------------------

//
using namespace tlp;
using std::ostream;

class RRA_DECLSPEC AutoData
{
    protected:
        string                          mBifurcationDiagram;     //This is the main resulting  data file

    public:
                                        AutoData();
                                       ~AutoData();
                                        AutoData(const AutoData& data);
        AutoData&                       operator=(AutoData& rhs);
        string                          getBifurcationDiagram() const;
        void                            setBifurcationDiagram(const string& str);

        friend RRA_DECLSPEC
        ostream& operator<<(ostream& stream, const AutoData& outMe);
};

template<>
inline string Property< AutoData >::getValueAsString() const
{
    Log(rr::lDebug2)<<"Getting AutoData value as a string is not implemented";
    return "";
}

template<>
inline void Property< AutoData >::setValueFromString(const string& val)
{
    Log(rr::lDebug2)<<"Setting AutoData value from string is not implemented";
    return;
}

template<>
inline void Property< AutoData >::setValue(AutoData* val)
{
    mValue = *(val);
}

namespace tlp{

template<>
inline std::string getPropertyType<AutoData>(const AutoData& val)
{
    return "Auto Data";
}

}
#endif
