#ifndef LUDEI_ADS_NULLADSERVICE_H
#define LUDEI_ADS_NULLADSERVICE_H
#include <iostream>
#include "../AdService.h"

namespace ludei{
namespace ads{

class NullAdService : public AdService
{
public:
	NullAdService(std::string serviceName);

	// AdService interface
public:
	void configure(const AdServiceSettings &settings) override;
	AdBanner *createBanner(const char *adunit, AdBannerSize size) override;
	AdInterstitial *createInterstitial(const char *adunit) override;
	AdRewardedVideo *createRewardedVideo(const char *adunit) override;

protected:
	std::string mServiceName;
	AdServiceSettings mSettings;

};

}
}

#endif // NULLADSERVICE_H
