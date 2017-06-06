#include "NullAdUtils.h"
#include <sstream>

namespace ludei{
namespace ads{


std::string toString(AdProvider provider){

	switch(provider){
	case AdProvider::ADMOB:
		return "ADMOB";
	case AdProvider::AUTO:
		return "AUTO";
	case AdProvider::MOPUB:
		return "MOPUB";
	}

	return "UNKNOWN_PROVIDER";
}

std::string toString(AdBannerSize size)
{
	switch(size){
	case AdBannerSize::SMART_SIZE:
		return "SMART_SIZE";
	case AdBannerSize::BANNER_SIZE:
		return "BANNER_SIZE";
	case AdBannerSize::MEDIUM_RECT_SIZE:
		return "MEDIUM_RECT_SIZE_SIZE";
	case AdBannerSize::LEADERBOARD_SIZE:
		return "LEADERBOARD_SIZE";
	}

	return "UNKNOWN_ADBANNERSIZE";
}

std::string toString(AdBannerLayout layout)
{
	switch(layout){
	case AdBannerLayout::TOP_CENTER:
		return "TOP_CENTER";
	case AdBannerLayout::BOTTOM_CENTER:
		return "BOTTOM_CENTER";
	case AdBannerLayout::CUSTOM:
		return "CUSTOM";
	}

	return "UNKNOWN_ADBANNERLAYOUT";
}

std::string toString(AdServiceSettings settings)
{
	std::stringstream ss;
	ss << "AdServiceSettings:\n";
	ss << "Banner: " << settings.banner << "\n";
	ss << "Interstitial :" << settings.interstitial << "\n";
	ss << "BannerTablet :" << settings.bannerTablet << "\n";
	ss << "InterstitialTablet :" << settings.interstitialTablet << "\n";

	return ss.str();
}

}
}
