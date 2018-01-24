#include "NullAdRewardedVideo.h"
#include <iostream>

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


	static bool clicked = true;

	if(mListener){
		mListener->onAdOpened(this);
		if(clicked){
			mListener->onRewarded(this, "fake reward type", 1);
			mListener->onAdLeftApplication(this);
		}
		mListener->onAdClosed(this);
	}

	clicked = !clicked;
}

void NullAdRewardedVideo::load()
{
	std::cout << "NullAdRewardedVideo(adunit="<< mAdUnit << "::load()" << std::endl;

	mLoadSucess=!mLoadSucess;

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
