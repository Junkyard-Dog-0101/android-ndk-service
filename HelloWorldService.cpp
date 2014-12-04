#include <iostream>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include "HelloWorldService.hpp"

using namespace android;

void	HelloWorldService::instantiate()
{
  if (defaultServiceManager()->addService(String16("HelloWorldService"), new HelloWorldService()) != NO_ERROR)
    {
      std::cerr << "Error: can't instantiate HelloWorldService" << std::endl;
      exit(1);
    }
}

HelloWorldService::HelloWorldService()
{

}

HelloWorldService::~HelloWorldService()
{

}

void	HelloWorldService::hello()
{
  std::cout << "Hello World !" << std::endl;
}

int	main()
{
  sp<ProcessState>	processState(ProcessState::self());
  sp<IServiceManager>	sm = defaultServiceManager();

  HelloWorldService::instantiate();
  ProcessState::self()->startThreadPool();
  IPCThreadState::self()->joinThreadPool();
  return 0;
}
