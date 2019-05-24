// Copyright 2011 National Instruments
// License: NATIONAL INSTRUMENTS SOFTWARE LICENSE AGREEMENT
//   Refer to "MHDDK License Agreement.pdf" in the root of this distribution.

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// This file is autogenerated!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef ___tXSeries_ipp___
#define ___tXSeries_ipp___

#ifndef ___tXSeries_h___
#include "tXSeries.h"
#endif

#ifndef ___nNIMXRegistermap_tStatus2Ptr_ipp___
#define ___nNIMXRegistermap_tStatus2Ptr_ipp___

typedef nMDBG::tStatus2 nNIMXRegisterMap120_tStatus2;


namespace nNIMXRegisterMap120 {
namespace {

typedef nNIMXRegisterMap120_tStatus2 tStatus2;

inline void setStatus(tStatus2* s, tStatus newStatus)
{
   if (s) s->setCode(newStatus);
}

inline tStatus* toPALStatusPtr(tStatus2* s)
{
   return s ? s->operator tStatus*() : ((tStatus*)NULL);
}

inline tBoolean statusIsFatal(tStatus2* s)
{
   return s && s->isFatal();
}

} // unnamed namespace
} // namespace nNIMXRegisterMap120

#endif // ___nNIMXRegistermap_tStatus2Ptr_ipp___


inline tBusSpaceReference tXSeries::getBusSpaceReference(void) const
{
   return _addrSpace;
}

inline void tXSeries::setAddressOffset(u32 value, nMDBG::tStatus2* s)
{
   if (s && s->isFatal()) return;
   _addressOffset = value;
}
inline u32 tXSeries::getAddressOffset(nMDBG::tStatus2* s)
{
   if (s && s->isFatal()) return 0UL;
   return _addressOffset;
}
#endif


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// This file is autogenerated!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

