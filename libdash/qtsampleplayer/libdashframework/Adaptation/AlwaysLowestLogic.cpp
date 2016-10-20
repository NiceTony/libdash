/*
 * AlwaysLowestLogic.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AlwaysLowestLogic.h"

using namespace libdash::framework::adaptation;
using namespace libdash::framework::input;
using namespace dash::mpd;

AlwaysLowestLogic::AlwaysLowestLogic        (sampleplayer::managers::StreamType type, IMPD *mpd, IPeriod *period, IAdaptationSet *adaptationSet) :
                   AbstractAdaptationLogic  (type, mpd, period, adaptationSet)
{
    this->representation = this->adaptationSet->GetRepresentation().at(0);
}
AlwaysLowestLogic::~AlwaysLowestLogic   ()
{
}

LogicType       AlwaysLowestLogic::GetType      ()
{
    return adaptation::AlwaysLowest;
}
