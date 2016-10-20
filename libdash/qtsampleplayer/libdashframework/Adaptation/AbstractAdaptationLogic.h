/*
 * AbstractAdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_
#define LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_

#include "libdash.h"
#include "IAdaptationLogic.h"
#include "IMPD.h"
#include "../MPD/AdaptationSetHelper.h"
#include "../../Managers/IStreamObserver.h"

namespace libdash
{
    namespace framework
    {
        namespace adaptation
        {
            class AbstractAdaptationLogic : public IAdaptationLogic
            {
                public:
                    AbstractAdaptationLogic             (sampleplayer::managers::StreamType type, dash::mpd::IMPD *mpd, dash::mpd::IPeriod* period, dash::mpd::IAdaptationSet *adaptationSet);
                    virtual ~AbstractAdaptationLogic    ();

                    virtual uint32_t                    GetPosition         ();
                    virtual void                        SetPosition         (uint32_t segmentNumber);
                    virtual dash::mpd::IAdaptationSet*  GetAdaptationSet    ();
                    virtual dash::mpd::IRepresentation* GetRepresentation   ();
                    virtual void                        SetRepresentation   (dash::mpd::IPeriod *period,
                                                                             dash::mpd::IAdaptationSet *adaptationSet,
                                                                             dash::mpd::IRepresentation *representation);

                    virtual LogicType                   GetType             ()  = 0;
                    virtual double                      EstimateBandwidth   (std::vector<double> &bandwidthVector);
                    virtual void                        DoLogic             ();


                protected:
                    dash::mpd::IMPD                     *mpd;
                    dash::mpd::IPeriod                  *period;
                    dash::mpd::IAdaptationSet           *adaptationSet;
                    dash::mpd::IRepresentation          *representation;

                    //logic
                    std::vector<dash::mpd::IPeriod *>              Periods;
                    std::vector<dash::mpd::IAdaptationSet *>       AdaptationSets;
                    std::vector<dash::mpd::IRepresentation *>      Representations;

                    sampleplayer::managers::StreamType  streamType;
                    uint32_t                            segmentNumber;
                    double                              estimateBandwidth;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_ */
