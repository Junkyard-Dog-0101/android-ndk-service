#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <string.h>
#include "IHelloWorldService.hpp"

using namespace android;

class BpHelloWorldService : public BpInterface<IHelloWorldService>
{
public:
  BpHelloWorldService(const sp<IBinder> &i) : BpInterface<IHelloWorldService>(i)
  {
  }

  virtual void	hello()
  {
    Parcel	data;
    Parcel	reply;

    data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
    remote()->transact(BnHelloWorldService::HELLO, data, &reply);
  }
};

IMPLEMENT_META_INTERFACE(HelloWorldService, "HelloWorldService");

BnHelloWorldService::BnHelloWorldService()
{
}

status_t	BnHelloWorldService::onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags)
{
  switch (code) {
    case HELLO: {
      CHECK_INTERFACE(IHelloWorldService, data, reply);
      hello();
    } break;
    default:
      return BBinder::onTransact(code, data, reply, flags);
  }
  return NO_ERROR;
}
