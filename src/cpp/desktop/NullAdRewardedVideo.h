#ifndef LUDEI_ADS_NULLADREWARDEDVIDEO_H
#define LUDEI_ADS_NULLADREWARDEDVIDEO_H
#include "../AdRewardedVideo.h"

namespace ludei{
namespace ads{

class NullAdRewardedVideo : public AdRewardedVideo
{
public:
	NullAdRewardedVideo(std::string adunit);

	// AdInterstitial interface
public:
	void show() override;
	void load() override;
	void setListener(AdRewardedVideoListener *listener) override;

protected:
	AdRewardedVideoListener *mListener;
	std::string mAdUnit;
	bool mLoadSucess;
};



}
}

#endif // NULLADREWARDEDVIDEO_H
