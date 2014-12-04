#ifndef __HELLOWORLDSERVICE_HPP__
#define __HELLOWORLDSERVICE_HPP__

#include "IHelloWorldService.hpp"

using namespace android;

class HelloWorldService : public BnHelloWorldService
{
public:
  HelloWorldService();
  virtual ~HelloWorldService();
  static void	instantiate();
  virtual void	hello();
};

#endif
