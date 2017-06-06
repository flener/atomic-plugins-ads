#ifndef LUDEI_ADS_NULLADBANNER_H
#define LUDEI_ADS_NULLADBANNER_H
#include "../AdBanner.h"

namespace ludei{
namespace ads{

class NullAdBanner : public AdBanner
{
public:
	NullAdBanner(std::string adunit, AdBannerSize size);

	// AdBanner interface
public:
	void show() override;
	void hide() override;
	int32_t getWidth() const override;
	int32_t getHeight() const override;
	void load() override;
	void setListener(AdBannerListener *mListener) override;
	void setLayout(AdBannerLayout layout) override;
	void setPosition(float x, float y) override;

protected:
	AdBannerListener * mListener;
	std::string mAdUnit;
	AdBannerSize mSize;
};

}
}
#endif // NULLADBANNER_H
