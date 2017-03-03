/*
 * AbstractAdaptationLogic.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AbstractAdaptationLogic.h"

using namespace libdash::framework::adaptation;
using namespace libdash::framework::mpd;
using namespace sampleplayer::managers;
using namespace dash::mpd;

AbstractAdaptationLogic::AbstractAdaptationLogic    (StreamType type, dash::mpd::IMPD *mpd, dash::mpd::IPeriod *period, dash::mpd::IAdaptationSet *adaptationSet) :
                         streamType                 (type),
                         mpd                        (mpd),
                         period                     (period),
                         adaptationSet              (adaptationSet),
                         representation             (NULL)
{
    this->Periods                                       = this->mpd->GetPeriods();
    IPeriod *                       currentPeriod       = Periods.at(0);
    switch(type)
    {
        case AUDIO:
            this->AdaptationSets = AdaptationSetHelper::GetAudioAdaptationSets(currentPeriod);
            break;
        case VIDEO:
            this->AdaptationSets = AdaptationSetHelper::GetVideoAdaptationSets(currentPeriod);
            break;
        default:
            break;
    }
    this->adaptationSet   = this->AdaptationSets.at(0);
    this->Representations = this->adaptationSet->GetRepresentation();
}
AbstractAdaptationLogic::~AbstractAdaptationLogic   ()
{
}

uint32_t            AbstractAdaptationLogic::GetPosition        ()
{
    return 0;
}
void                AbstractAdaptationLogic::SetPosition        (uint32_t segmentNumber)
{
    this->segmentNumber = segmentNumber;
}
IAdaptationSet*     AbstractAdaptationLogic::GetAdaptationSet()
{
    return this->adaptationSet;
}
IRepresentation*    AbstractAdaptationLogic::GetRepresentation  ()
{
    return this->representation;
}
void                AbstractAdaptationLogic::SetRepresentation  (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    this->period            = period;
    this->adaptationSet     = adaptationSet;
    this->representation    = representation;
}
double              AbstractAdaptationLogic::EstimateBandwidth   (std::vector<double> &bandwidthVector)
{
    this->estimateBandwidth = bandwidthVector.back();
    return this->estimateBandwidth;
}
void                AbstractAdaptationLogic::DoLogic             ()
{
    this->adaptationSet     = this->AdaptationSets.at(0);
    this->Representations   = this->adaptationSet->GetRepresentation();
    this->representation    = this->Representations.at(Representations.size());

#if 1  //by li
        FILE *fp;
        fp = fopen("D://logic.txt", "at+");
        if (fp != NULL)
        {
            fprintf(fp, "periods: %d\t\t AdaptationSets: %d\t\t Representations: %d\t\t\n", Periods.size(), AdaptationSets.size(), Representations.size());
        }
        fclose(fp);
#endif
}
