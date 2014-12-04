#ifndef __IHELLOWORLDSERVICE_HPP__
#define __IHELLOWORLDSERVICE_HPP__

#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/MemoryHeapBase.h>

using namespace android;

class IHelloWorldService : public IInterface
{
public:
  DECLARE_META_INTERFACE(HelloWorldService);
  virtual void hello() = 0;
};

class BnHelloWorldService : public BnInterface<IHelloWorldService>
{
public:
  enum
    {
      HELLO = IBinder::FIRST_CALL_TRANSACTION,
    };
  BnHelloWorldService();
  virtual status_t onTransact(uint32_t, const Parcel &, Parcel *, uint32_t = 0);
};

#endif
