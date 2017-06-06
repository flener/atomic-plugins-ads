#include "../AdService.h"
#include <iostream>
#include "NullAdUtils.h"
#include "NullAdService.h"

namespace ludei{
namespace ads{

AdService *AdService::create(AdProvider provider)
{
	std::cout << "Trying to create AdService with AdProvider = " << toString(provider) << std::endl;

	return new NullAdService(toString(provider));
}

AdService *AdService::create(const char *className)
{
	std::cout << "Trying to create AdService with className = " << className << std::endl;

	return new NullAdService(className);
}


}
}
