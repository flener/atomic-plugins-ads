#include "NullAdInterstitial.h"
#include <iostream>

namespace ludei{
namespace ads{


NullAdInterstitial::NullAdInterstitial(std::string adunit)
{
	mAdUnit = adunit;
	mListener = nullptr;
}

void NullAdInterstitial::show()
{
	std::cout << "NullAdInterstitial::show()" << std::endl;
}

void NullAdInterstitial::load()
{
	std::cout << "NullAdInterstitial::load()" << std::endl;

	static int count = 0;

	if(!mListener){
		return;
	}

	switch(count){
	case 0:
		mListener->onLoaded(this);
		break;
	case 1:
		mListener->onFailed(this, -1, "Fake error message");
		break;
	case 2:
		mListener->onClicked(this);
		break;
	case 3:
		mListener->onShown(this);
		break;
	case 4:
		mListener->onHidden(this);
		break;
	}

	count++;
	count%=5;
}

void NullAdInterstitial::setListener(AdInterstitialListener *listener)
{
	std::cout << "NullAdInterstitial::setListener(listener=" << listener << std::endl;
	mListener = listener;
}

}
}
