#pragma once

#include <string>

namespace ludei { namespace ads {

    class AdRewardedVideoListener;

    /**
     * Defines an interstitial ad.
     */
    class AdRewardedVideo {
    public:

        virtual ~AdRewardedVideo(){};

        virtual void show() = 0;

        virtual void load() = 0;

        virtual void setListener(AdRewardedVideoListener * listener) = 0;
    };

    class AdRewardedVideoListener {
    public:

        virtual ~AdRewardedVideoListener(){}

        virtual void onAdLoaded(AdRewardedVideo* adRewardedVideo) = 0;
        virtual void onAdOpened(AdRewardedVideo* adRewardedVideo) = 0;
        virtual void onAdStarted(AdRewardedVideo* adRewardedVideo) = 0;
        virtual void onAdClosed(AdRewardedVideo* adRewardedVideo) = 0;
        virtual void onRewarded(AdRewardedVideo* adRewardedVideo, const std::string & rewardType, int32_t rewardAmount) = 0;
        virtual void onAdLeftApplication(AdRewardedVideo* adRewardedVideo) = 0;
        virtual void onAdFailedToLoad(AdRewardedVideo* adRewardedVideo, int32_t i) = 0;

    };

} }
