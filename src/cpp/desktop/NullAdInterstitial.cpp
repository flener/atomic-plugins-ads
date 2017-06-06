#include "NullAdInterstitial.h"
#include <iostream>

namespace ludei{
namespace ads{


NullAdInterstitial::NullAdInterstitial(std::string adunit)
{
	mAdUnit = adunit;
	mListener = nullptr;
	mLoadSucess = false;
}

void NullAdInterstitial::show()
{
	std::cout << "NullAdInterstitial(adunit="<< mAdUnit << "::show()" << std::endl;


	static bool clicked = true;

	if(!mListener){
		mListener->onShown(this);
		if(clicked){
			mListener->onClicked(this);
		}
		mListener->onHidden(this);
	}

	clicked = !clicked;
}

void NullAdInterstitial::load()
{
	std::cout << "NullAdInterstitial(adunit="<< mAdUnit << "::load()" << std::endl;

	mLoadSucess=!mLoadSucess;

	if(!mListener){
		return;
	}

	if(mLoadSucess){
		mListener->onLoaded(this);
	}else{
		mListener->onFailed(this, -1, "Fake error message");
	}

}

void NullAdInterstitial::setListener(AdInterstitialListener *listener)
{
	std::cout << "NullAdInterstitial::setListener(listener=" << listener << std::endl;
	mListener = listener;
}

}
}
