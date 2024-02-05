#pragma once
#ifndef UI_PARAMETER_H
#define UI_PARAMETER_H

#include <string>
#include <vector>
#include "../Presenters/NumericSettingsPageItem.h"

namespace developmentKit::library::uiFramework::utilities
{
    using namespace developmentKit::library::uiFramework::presenters;

    class UiParameter
    {
    public:
        enum Curve
        {
            LINEAR,
            EXPONENTIAL,
            LOGARITHMIC,
            CUBE,
            LAST,
        };
        void Init(NumericSettingsPageItem *prmNumericSettingsPageItem, float prmMin, float prmMax, Curve prmCurve);
        float Process();

    private:
        NumericSettingsPageItem *numericSettingsPageItem;
        float min, max;
        float lMin, lMax; 
        Curve curve;
        float value;
    };
}

#endif