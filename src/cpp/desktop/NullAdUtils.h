#ifndef LUDEI_ADS_NULLADUTILS_H
#define LUDEI_ADS_NULLADUTILS_H
#include "../AdService.h"
#include <string>

namespace ludei{
namespace ads {

std::string toString(AdProvider provider);

std::string toString(AdBannerSize size);

std::string toString(AdBannerLayout layout);

std::string toString(AdServiceSettings settings);

}
}

#endif // NULLADUTILS_H
