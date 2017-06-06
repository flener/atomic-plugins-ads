#include "NullAdBanner.h"
#include <iostream>
#include "NullAdUtils.h"

namespace ludei{
namespace ads{


NullAdBanner::NullAdBanner(std::string adunit, AdBannerSize size)
{
	mAdUnit = adunit;
	mSize = size;
}

void NullAdBanner::show()
{
	std::cout << "NullAdBanner::show()" << std::endl;
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
	std::cout << "NullAdBanner::getLoad()" << std::endl;

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
		mListener->onExpanded(this);
		break;
	case 4:
		mListener->onCollapsed(this);
		break;
	}

	count++;
	count%=5;
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
