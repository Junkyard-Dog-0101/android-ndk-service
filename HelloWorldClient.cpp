#include <iostream>
#include <binder/IServiceManager.h>
#include "IHelloWorldService.hpp"

using namespace android;

int	main()
{
  sp<IHelloWorldService>	mHelloWorldService;

  if (getService(String16("HelloWorldService"), &mHelloWorldService) != NO_ERROR)
    {
      std::cerr << "HelloWorldService is not available" << std::endl;
      return 1;
    }
  mHelloWorldService->hello();
  return 0;
}
