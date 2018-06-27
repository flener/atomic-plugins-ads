#include "NullAdRewardedVideo.h"
#include <iostream>
#include <jack/log/log.hpp>

namespace ludei{
namespace ads{


NullAdRewardedVideo::NullAdRewardedVideo(std::string adunit)
{
	mAdUnit = adunit;
	mListener = nullptr;
	mLoadSucess = false;
}

void NullAdRewardedVideo::show()
{
	std::cout << "NullAdRewardedVideo(adunit="<< mAdUnit << "::show()" << std::endl;


	if(mListener){
		mListener->onAdOpened(this);
		mListener->onAdStarted(this);
		mListener->onRewarded(this, "fake reward type", 1);
		mListener->onAdLeftApplication(this);
		mListener->onAdClosed(this);
	}

}

void NullAdRewardedVideo::load()
{
	std::cout << "NullAdRewardedVideo(adunit="<< mAdUnit << "::load()" << std::endl;

	mLoadSucess=!mLoadSucess;

	// Commented is useful for testing delayed first load
	// This load is called roughly each second.
//	static int count = 0;
//	count++;
//	JLOGDEBUG("counting tries NullAdRewardedVideo::load() calls: %d", count);
//	if(count > 10){
//		mLoadSucess = true;
//	}else{
//		mLoadSucess = false;
//	}

	if(!mListener){
		return;
	}

	if(mLoadSucess){
		mListener->onAdLoaded(this);
	}else{
		mListener->onAdFailedToLoad(this, -1);
	}

}

void NullAdRewardedVideo::setListener(AdRewardedVideoListener *listener)
{
	std::cout << "NullAdRewardedVideo::setListener(listener=" << listener << std::endl;
	mListener = listener;
}

}
}
