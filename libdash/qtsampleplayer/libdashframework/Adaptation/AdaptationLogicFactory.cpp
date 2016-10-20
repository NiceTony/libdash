/*
 * AdaptationLogicFactory.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AdaptationLogicFactory.h"

using namespace libdash::framework::adaptation;
using namespace dash::mpd;

IAdaptationLogic* AdaptationLogicFactory::Create(sampleplayer::managers::StreamType type, LogicType logic, IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet)
{
    switch(logic)
    {
        case Manual:            return new ManualAdaptation     (type, mpd, period, adaptationSet);
        case AlwaysLowest:      return new AlwaysLowestLogic    (type, mpd, period, adaptationSet);

        default:                return new ManualAdaptation     (type, mpd, period, adaptationSet);
    }
}
