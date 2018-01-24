#include "NullAdService.h"
#include "NullAdUtils.h"
#include "NullAdBanner.h"
#include "NullAdInterstitial.h"
#include "NullAdRewardedVideo.h"

namespace ludei{
namespace ads{

NullAdService::NullAdService(std::string serviceName):
	mServiceName(serviceName){

}

void NullAdService::configure(const AdServiceSettings &settings)
{

	std::cout << "Configuring NullAdService with settings << " << std::endl;
	std::cout << toString(settings);
	mSettings = settings;
}

AdBanner *NullAdService::createBanner(const char *adunit, AdBannerSize size)
{

	if(adunit==nullptr){
		std::cout  << "Null AdUnit, setting default : " << mSettings.banner;
		adunit = mSettings.banner.c_str();
	}

	std::cout << "Creating NullAdBanner : adunit= " << adunit << " AdBannerSize: " << toString(size);

	return new NullAdBanner(adunit,size);
}

AdInterstitial *NullAdService::createInterstitial(const char *adunit)
{
	if(adunit==nullptr){
		std::cout  << "Null AdUnit, setting default : " << mSettings.interstitial;
		adunit = mSettings.interstitial.c_str();
	}

	std::cout << "Creating NullAdInterstitial : adunit= " << adunit;

	return new NullAdInterstitial(adunit);
}

AdRewardedVideo *NullAdService::createRewardedVideo(const char *adunit)
{
	if(adunit==nullptr){
		std::cout  << "Null AdUnit, setting default : " << mSettings.rewardedVideo;
		adunit = mSettings.rewardedVideo.c_str();
	}

	std::cout << "Creating NullAdRewardedVideo : adunit= " << adunit;

	return new NullAdRewardedVideo(adunit);
}

}
}
