#ifndef LUDEI_ADS_NULLADINTERSTITIAL_H
#define LUDEI_ADS_NULLADINTERSTITIAL_H
#include "../AdInterstitial.h"

namespace ludei{
namespace ads{

class NullAdInterstitial : public AdInterstitial
{
public:
	NullAdInterstitial(std::string adunit);

	// AdInterstitial interface
public:
	void show() override;
	void load() override;
	void setListener(AdInterstitialListener *listener) override;

protected:
	AdInterstitialListener *mListener;
	std::string mAdUnit;
	bool mLoadSucess;
};



}
}

#endif // NULLADINTERSTITIAL_H
