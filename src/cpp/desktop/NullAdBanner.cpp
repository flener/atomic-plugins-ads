#include "NullAdBanner.h"
#include <iostream>
#include "NullAdUtils.h"

namespace ludei{
namespace ads{


NullAdBanner::NullAdBanner(std::string adunit, AdBannerSize size)
{
	mAdUnit = adunit;
	mSize = size;
	mLoadSucess = false;
}

void NullAdBanner::show()
{
	std::cout << "NullAdBanner(adunit="<< mAdUnit << "::show()" << std::endl;

	static bool clicked = true;

	if(mListener){
		mListener->onExpanded(this);
		if(clicked){
			mListener->onClicked(this);
		}
		mListener->onCollapsed(this);
	}

	clicked = !clicked;
}

void NullAdBanner::hide()
{
	std::cout << "NullAdBanner::hide()" << std::endl;
}

int32_t NullAdBanner::getWidth() const
{
	std::cout << "NullAdBanner::getWidth()" << std::endl;
	return 0;
}

int32_t NullAdBanner::getHeight() const
{
	std::cout << "NullAdBanner::getHeight()" << std::endl;
	return 0;
}

void NullAdBanner::load()
{
	std::cout << "NullAdBanner(adunit="<< mAdUnit << ")::load()" << std::endl;

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

void NullAdBanner::setListener(AdBannerListener *listener)
{
	std::cout << "NullAdBanner::setListener()" << std::endl;
	this->mListener = listener;
}

void NullAdBanner::setLayout(AdBannerLayout layout)
{
	std::cout << "NullAdBanner::setListener(layout = "  << toString(layout) <<  ")" << std::endl;
}

void NullAdBanner::setPosition(float x, float y)
{
	std::cout << "NullAdBanner::setPosition(x = "  << x  << "y=" << y <<  ")" << std::endl;
}

}
}
