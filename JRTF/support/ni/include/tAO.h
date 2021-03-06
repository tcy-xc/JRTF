// Copyright 2011 National Instruments
// License: NATIONAL INSTRUMENTS SOFTWARE LICENSE AGREEMENT
//   Refer to "MHDDK License Agreement.pdf" in the root of this distribution.

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// This file is autogenerated!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef ___tAO_h___
#define ___tAO_h___

// includes
#include "osiTypes.h"
#include "osiBus.h"
#include "tOutTimer.h"
#include "tAOValues.h"


#ifndef ___tAOValues_h___
#include "tAOValues.h"
#endif

#ifndef nNIMXRegisterMap120_mBuildFieldId

// Algorithm:
//    Move lowermost 5 bits (4 through 0) of field id to uppermost 5 bits (31
//          through 27)
//    Move bit 5 of field id to bit 26
//    Move bit 6 of field id to bit 25
//    OR in the register id (which is allowed the remaining bits)
//
// Why not move the lowermost 7 bits directly to the uppermost 7 bits? Because
// we originally moved only the lowermost 5, and for backwards compatibility,
// we can't change where those 5 bits end up.
//
// For future expansion purposes, the bits beyond the first 5 are put in reverse
// order in the resulting combined id.
#define nNIMXRegisterMap120_mBuildFieldId(fieldId, regId) \
   ( \
     ((fieldId) << 27) | \
     ((((fieldId) >> 5) & 0x1) << 26) | \
     ((((fieldId) >> 6) & 0x1) << 25) | \
     (regId) \
   )

#endif

#ifndef nNIMXRegisterMap120_mExtractFieldId

// Algorithm: (basically the reverse of mBuildFieldId)
//    Move uppermost 5 bits (31 through 27) to lowermost 5 bits (4 through 0)
//    Move 26th bit to bit 5 (right-shifting by (26 - 5) is like right-shifting
//          by 26 then left-shifting by 5, but it's more efficient)
//    Move 25th bit to bit 6
#define nNIMXRegisterMap120_mExtractFieldId(id) \
   (unsigned int) \
   ( \
     (((id) >> 27) & 0x1F) | \
     (((id) & (0x1 << 26)) >> (26 - 5)) | \
     (((id) & (0x1 << 25)) >> (25 - 6)) \
   )

#endif

class tAO
{
public:
   tOutTimer AO_Timer;

   //---------------------------------------------------------------------------
   // IO Strategies
   //---------------------------------------------------------------------------
   class tReg8IODirect32
   {
   public:
      inline void write(
         tBusSpaceReference addrSpace,
         u32 offset,
         u8 value,
         nMDBG::tStatus2* statusChain = NULL);

      inline u8 read(
         tBusSpaceReference addrSpace,
         u32 offset,
         nMDBG::tStatus2* statusChain = NULL);
   };

   class tReg32IODirect32
   {
   public:
      inline void write(
         tBusSpaceReference addrSpace,
         u32 offset,
         u32 value,
         nMDBG::tStatus2* statusChain = NULL);

      inline u32 read(
         tBusSpaceReference addrSpace,
         u32 offset,
         nMDBG::tStatus2* statusChain = NULL);
   };

   //---------------------------------------------------------------------------
   // AO_DacShadow_t
   //---------------------------------------------------------------------------
   class tAO_DacShadow_t : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      const u32 kOffset;
      const u32 kId;

      tAO_DacShadow_t(u32 offset, u32 id);
      tAO_DacShadow_t();
      void initialize(u32 offset, u32 id);


      typedef enum {
         kRegisterId                          = 0,
         kAO_DacShadow_BitfieldId          = 1,
         kMaxFieldId                          = 1
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Register Accessors (Compile-time selectable)
      inline tAO_DacShadow_t& setRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getRegister(nMDBG::tStatus2* statusChain = NULL) const;

      inline void refresh(nMDBG::tStatus2* statusChain = NULL);

      inline u32 readRegister(nMDBG::tStatus2* statusChain = NULL);

      // Field Accessors (Compile-time selectable)
      inline tAO_DacShadow_t& setAO_DacShadow_Bitfield(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getAO_DacShadow_Bitfield(nMDBG::tStatus2* statusChain = NULL) const;

      inline u32 readAO_DacShadow_Bitfield(nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      u32 _softCopy;

      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_DacShadow_t(const tAO_DacShadow_t&);
      tAO_DacShadow_t& operator=(const tAO_DacShadow_t&);

   };

   //---------------------------------------------------------------------------
   // AO_Direct_Data_t
   //---------------------------------------------------------------------------
   class tAO_Direct_Data_t : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      const u32 kOffset;
      const u32 kId;

      tAO_Direct_Data_t(u32 offset, u32 id);
      tAO_Direct_Data_t();
      void initialize(u32 offset, u32 id);


      typedef enum {
         kRegisterId                          = 0,
         kAO_Direct_Data_BitfieldId        = 1,
         kMaxFieldId                          = 1
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Register Accessors (Compile-time selectable)

      inline void writeRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);


      // Field Accessors (Compile-time selectable)
      inline void writeAO_Direct_Data_Bitfield(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_Direct_Data_t(const tAO_Direct_Data_t&);
      tAO_Direct_Data_t& operator=(const tAO_Direct_Data_t&);

   };

   //---------------------------------------------------------------------------
   // AO_Order_Config_Data_Register
   //---------------------------------------------------------------------------
   class tAO_Order_Config_Data_Register : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      enum {
         kOffset = 0x40,
         kId     = 24
      };
      tAO_Order_Config_Data_Register();


      typedef enum {
         kRegisterId                          = 0,
         kAO_Waveform_Bitfield_OrderId     = 1,
         kMaxFieldId                          = 1
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Register Accessors (Compile-time selectable)

      inline void writeRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);


      // Field Accessors (Compile-time selectable)
      inline void writeAO_Waveform_Bitfield_Order(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_Order_Config_Data_Register(const tAO_Order_Config_Data_Register&);
      tAO_Order_Config_Data_Register& operator=(const tAO_Order_Config_Data_Register&);

   };

   //---------------------------------------------------------------------------
   // AO_Config_Control_Register
   //---------------------------------------------------------------------------
   class tAO_Config_Control_Register : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      enum {
         kOffset = 0x44,
         kId     = 25
      };
      tAO_Config_Control_Register();


      typedef enum {
         kRegisterId                          = 0,
         kAO_Waveform_Order_ClearId        = 1,
         kMaxFieldId                          = 1
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Register Accessors (Compile-time selectable)

      inline void writeRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);


      // Field Accessors (Compile-time selectable)
      inline void writeAO_Waveform_Order_Clear(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_Config_Control_Register(const tAO_Config_Control_Register&);
      tAO_Config_Control_Register& operator=(const tAO_Config_Control_Register&);

   };

   //---------------------------------------------------------------------------
   // AO_Trigger_Select_Register
   //---------------------------------------------------------------------------
   class tAO_Trigger_Select_Register : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      enum {
         kOffset = 0x48,
         kId     = 26
      };
      tAO_Trigger_Select_Register();


      typedef enum {
         kRegisterId                          = 0,
         kAO_External_Gate_EnableId        = 2,
         kAO_External_Gate_PolarityId      = 3,
         kAO_External_Gate_SelectId        = 4,
         kAO_START1_EdgeId                 = 5,
         kAO_START1_PolarityId             = 6,
         kAO_START1_SelectId               = 7,
         kAO_UPDATE_Source_PolarityId      = 9,
         kAO_UPDATE_Source_SelectId        = 10,
         kMaxFieldId                          = 10
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Dirty Tracking
      inline tBoolean isDirty(nMDBG::tStatus2* statusChain = NULL);
      inline void markDirty(nMDBG::tStatus2* statusChain = NULL);
      inline void markClean(nMDBG::tStatus2* statusChain = NULL);

      // Register Accessors (Compile-time selectable)
      inline tAO_Trigger_Select_Register& setRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getRegister(nMDBG::tStatus2* statusChain = NULL) const;

      inline void flush(nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline void writeRegister(u32 value, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u32 readRegister(nMDBG::tStatus2* statusChain = NULL);

      // Field Accessors (Compile-time selectable)
      inline tAO_Trigger_Select_Register& setAO_External_Gate_Enable(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getAO_External_Gate_Enable(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_External_Gate_Enable(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u32 readAO_External_Gate_Enable(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_External_Gate_Polarity(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getAO_External_Gate_Polarity(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_External_Gate_Polarity(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u32 readAO_External_Gate_Polarity(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_External_Gate_Select(nAO::tAO_External_Gate_Select_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_External_Gate_Select_t getAO_External_Gate_Select(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_External_Gate_Select(nAO::tAO_External_Gate_Select_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_External_Gate_Select_t readAO_External_Gate_Select(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_START1_Edge(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getAO_START1_Edge(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_START1_Edge(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u32 readAO_START1_Edge(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_START1_Polarity(nAO::tAO_Polarity_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_Polarity_t getAO_START1_Polarity(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_START1_Polarity(nAO::tAO_Polarity_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_Polarity_t readAO_START1_Polarity(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_START1_Select(nAO::tAO_START1_Select_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_START1_Select_t getAO_START1_Select(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_START1_Select(nAO::tAO_START1_Select_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_START1_Select_t readAO_START1_Select(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_UPDATE_Source_Polarity(nAO::tAO_Polarity_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_Polarity_t getAO_UPDATE_Source_Polarity(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_UPDATE_Source_Polarity(nAO::tAO_Polarity_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_Polarity_t readAO_UPDATE_Source_Polarity(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Trigger_Select_Register& setAO_UPDATE_Source_Select(nAO::tAO_UPDATE_Source_Select_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_UPDATE_Source_Select_t getAO_UPDATE_Source_Select(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_UPDATE_Source_Select(nAO::tAO_UPDATE_Source_Select_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_UPDATE_Source_Select_t readAO_UPDATE_Source_Select(nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      u32 _softCopy;

      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_Trigger_Select_Register(const tAO_Trigger_Select_Register&);
      tAO_Trigger_Select_Register& operator=(const tAO_Trigger_Select_Register&);

   };

   //---------------------------------------------------------------------------
   // AO_Config_Bank_t
   //---------------------------------------------------------------------------
   class tAO_Config_Bank_t : public tReg8IODirect32
   {
   public:
      typedef tReg8IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      const u32 kOffset;
      const u32 kId;

      tAO_Config_Bank_t(u32 offset, u32 id);
      tAO_Config_Bank_t();
      void initialize(u32 offset, u32 id);


      typedef enum {
         kRegisterId                          = 0,
         kAO_OffsetId                      = 1,
         kAO_ReferenceId                   = 2,
         kAO_Update_ModeId                 = 3,
         kAO_BipolarId                     = 4,
         kMaxFieldId                          = 4
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Dirty Tracking
      inline tBoolean isDirty(nMDBG::tStatus2* statusChain = NULL);
      inline void markDirty(nMDBG::tStatus2* statusChain = NULL);
      inline void markClean(nMDBG::tStatus2* statusChain = NULL);

      // Register Accessors (Compile-time selectable)
      inline tAO_Config_Bank_t& setRegister(u8 value, nMDBG::tStatus2* statusChain = NULL);
      inline u8 getRegister(nMDBG::tStatus2* statusChain = NULL) const;

      inline void flush(nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline void writeRegister(u8 value, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u8 readRegister(nMDBG::tStatus2* statusChain = NULL);

      // Field Accessors (Compile-time selectable)
      inline tAO_Config_Bank_t& setAO_Offset(u8 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u8 getAO_Offset(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_Offset(u8 fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u8 readAO_Offset(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Config_Bank_t& setAO_Reference(u8 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u8 getAO_Reference(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_Reference(u8 fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline u8 readAO_Reference(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Config_Bank_t& setAO_Update_Mode(nAO::tAO_Update_Mode_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_Update_Mode_t getAO_Update_Mode(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_Update_Mode(nAO::tAO_Update_Mode_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_Update_Mode_t readAO_Update_Mode(nMDBG::tStatus2* statusChain = NULL);

      inline tAO_Config_Bank_t& setAO_Bipolar(nAO::tAO_Bipolar_t fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline nAO::tAO_Bipolar_t getAO_Bipolar(nMDBG::tStatus2* statusChain = NULL) const;

      inline void writeAO_Bipolar(nAO::tAO_Bipolar_t fieldValue, nMDBG::tStatus2* statusChain = NULL, tBoolean force = kFalse);

      inline nAO::tAO_Bipolar_t readAO_Bipolar(nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      u8 _softCopy;

      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_Config_Bank_t(const tAO_Config_Bank_t&);
      tAO_Config_Bank_t& operator=(const tAO_Config_Bank_t&);

   };

   //---------------------------------------------------------------------------
   // AO_FIFO_Data_Register
   //---------------------------------------------------------------------------
   class tAO_FIFO_Data_Register : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      enum {
         kOffset = 0x58,
         kId     = 35
      };
      tAO_FIFO_Data_Register();


      typedef enum {
         kRegisterId                          = 0,
         kAO_FIFO_DataId                   = 1,
         kMaxFieldId                          = 1
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Register Accessors (Compile-time selectable)

      inline void writeRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);


      // Field Accessors (Compile-time selectable)
      inline void writeAO_FIFO_Data(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_FIFO_Data_Register(const tAO_FIFO_Data_Register&);
      tAO_FIFO_Data_Register& operator=(const tAO_FIFO_Data_Register&);

   };

   //---------------------------------------------------------------------------
   // AO_FIFO_Status_Register
   //---------------------------------------------------------------------------
   class tAO_FIFO_Status_Register : public tReg32IODirect32
   {
   public:
      typedef tReg32IODirect32 tIOStrategy;
      typedef tAO tRegisterMap;

      enum {
         kOffset = 0x58,
         kId     = 36
      };
      tAO_FIFO_Status_Register();


      typedef enum {
         kRegisterId                          = 0,
         kAO_FIFO_StatusId                 = 1,
         kMaxFieldId                          = 1
      } tId;

      inline tRegisterMap* registerMap(void);
      inline void setRegisterMap(tRegisterMap* pRegMap);


      // Register Accessors (Compile-time selectable)
      inline tAO_FIFO_Status_Register& setRegister(u32 value, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getRegister(nMDBG::tStatus2* statusChain = NULL) const;

      inline void refresh(nMDBG::tStatus2* statusChain = NULL);

      inline u32 readRegister(nMDBG::tStatus2* statusChain = NULL);

      // Field Accessors (Compile-time selectable)
      inline tAO_FIFO_Status_Register& setAO_FIFO_Status(u32 fieldValue, nMDBG::tStatus2* statusChain = NULL);
      inline u32 getAO_FIFO_Status(nMDBG::tStatus2* statusChain = NULL) const;

      inline u32 readAO_FIFO_Status(nMDBG::tStatus2* statusChain = NULL);

      // Run-time selectable Register/Field Accessors
   private:
      u32 _softCopy;

      tRegisterMap* _regMap;

      // Usage guidelines
      tAO_FIFO_Status_Register(const tAO_FIFO_Status_Register&);
      tAO_FIFO_Status_Register& operator=(const tAO_FIFO_Status_Register&);

   };

   //----------------------------------------
   // Register Array Sizes
   //----------------------------------------
   enum {
      kAO_DacShadowArraySize = 8,
      kAO_Direct_DataArraySize = 16,
      kAO_Config_BankArraySize = 8
   };

   //---------------------------------------------------------------------------
   // AO_DacShadow
   //---------------------------------------------------------------------------
   tAO_DacShadow_t AO_DacShadow[kAO_DacShadowArraySize];

   //---------------------------------------------------------------------------
   // AO_Direct_Data
   //---------------------------------------------------------------------------
   tAO_Direct_Data_t AO_Direct_Data[kAO_Direct_DataArraySize];

   //---------------------------------------------------------------------------
   // AO_Order_Config_Data_Register
   //---------------------------------------------------------------------------
   tAO_Order_Config_Data_Register AO_Order_Config_Data_Register;

   //---------------------------------------------------------------------------
   // AO_Config_Control_Register
   //---------------------------------------------------------------------------
   tAO_Config_Control_Register AO_Config_Control_Register;

   //---------------------------------------------------------------------------
   // AO_Trigger_Select_Register
   //---------------------------------------------------------------------------
   tAO_Trigger_Select_Register AO_Trigger_Select_Register;

   //---------------------------------------------------------------------------
   // AO_Config_Bank
   //---------------------------------------------------------------------------
   tAO_Config_Bank_t AO_Config_Bank[kAO_Config_BankArraySize];

   //---------------------------------------------------------------------------
   // AO_FIFO_Data_Register
   //---------------------------------------------------------------------------
   tAO_FIFO_Data_Register AO_FIFO_Data_Register;

   //---------------------------------------------------------------------------
   // AO_FIFO_Status_Register
   //---------------------------------------------------------------------------
   tAO_FIFO_Status_Register AO_FIFO_Status_Register;

   //---------------------------------------------------------------------------
   // Register Groups
   //---------------------------------------------------------------------------

   //----------------------------------------
   // Register/Field Ids
   //----------------------------------------
   typedef enum {
      kAO_DacShadow0Id                  = 0,
      kDAC_Shadow0AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow0Id),

      kAO_DacShadow1Id                  = 1,
      kDAC_Shadow1AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow1Id),

      kAO_DacShadow2Id                  = 2,
      kDAC_Shadow2AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow2Id),

      kAO_DacShadow3Id                  = 3,
      kDAC_Shadow3AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow3Id),

      kAO_DacShadow4Id                  = 4,
      kDAC_Shadow4AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow4Id),

      kAO_DacShadow5Id                  = 5,
      kDAC_Shadow5AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow5Id),

      kAO_DacShadow6Id                  = 6,
      kDAC_Shadow6AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow6Id),

      kAO_DacShadow7Id                  = 7,
      kDAC_Shadow7AO_DacShadow_BitfieldId     = nNIMXRegisterMap120_mBuildFieldId(tAO_DacShadow_t::kAO_DacShadow_BitfieldId, kAO_DacShadow7Id),

      kAO_Direct_Data0Id                = 8,
      kDAC0AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data0Id),

      kAO_Direct_Data1Id                = 9,
      kDAC1AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data1Id),

      kAO_Direct_Data2Id                = 10,
      kDAC2AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data2Id),

      kAO_Direct_Data3Id                = 11,
      kDAC3AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data3Id),

      kAO_Direct_Data4Id                = 12,
      kDAC4AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data4Id),

      kAO_Direct_Data5Id                = 13,
      kDAC5AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data5Id),

      kAO_Direct_Data6Id                = 14,
      kDAC6AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data6Id),

      kAO_Direct_Data7Id                = 15,
      kDAC7AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data7Id),

      kAO_Direct_Data8Id                = 16,
      kDAC8AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data8Id),

      kAO_Direct_Data9Id                = 17,
      kDAC9AO_Direct_Data_BitfieldId    = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data9Id),

      kAO_Direct_Data10Id               = 18,
      kDAC10AO_Direct_Data_BitfieldId   = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data10Id),

      kAO_Direct_Data11Id               = 19,
      kDAC11AO_Direct_Data_BitfieldId   = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data11Id),

      kAO_Direct_Data12Id               = 20,
      kDAC12AO_Direct_Data_BitfieldId   = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data12Id),

      kAO_Direct_Data13Id               = 21,
      kDAC13AO_Direct_Data_BitfieldId   = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data13Id),

      kAO_Direct_Data14Id               = 22,
      kDAC14AO_Direct_Data_BitfieldId   = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data14Id),

      kAO_Direct_Data15Id               = 23,
      kDAC15AO_Direct_Data_BitfieldId   = nNIMXRegisterMap120_mBuildFieldId(tAO_Direct_Data_t::kAO_Direct_Data_BitfieldId, kAO_Direct_Data15Id),

      kAO_Order_Config_Data_RegisterId  = 24,
      kAO_Waveform_Bitfield_OrderId     = nNIMXRegisterMap120_mBuildFieldId(tAO_Order_Config_Data_Register::kAO_Waveform_Bitfield_OrderId, kAO_Order_Config_Data_RegisterId),

      kAO_Config_Control_RegisterId     = 25,
      kAO_Waveform_Order_ClearId        = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Control_Register::kAO_Waveform_Order_ClearId, kAO_Config_Control_RegisterId),

      kAO_Trigger_Select_RegisterId     = 26,
      kAO_External_Gate_EnableId        = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_External_Gate_EnableId, kAO_Trigger_Select_RegisterId),
      kAO_External_Gate_PolarityId      = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_External_Gate_PolarityId, kAO_Trigger_Select_RegisterId),
      kAO_External_Gate_SelectId        = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_External_Gate_SelectId, kAO_Trigger_Select_RegisterId),
      kAO_START1_EdgeId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_START1_EdgeId, kAO_Trigger_Select_RegisterId),
      kAO_START1_PolarityId             = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_START1_PolarityId, kAO_Trigger_Select_RegisterId),
      kAO_START1_SelectId               = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_START1_SelectId, kAO_Trigger_Select_RegisterId),
      kAO_UPDATE_Source_PolarityId      = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_UPDATE_Source_PolarityId, kAO_Trigger_Select_RegisterId),
      kAO_UPDATE_Source_SelectId        = nNIMXRegisterMap120_mBuildFieldId(tAO_Trigger_Select_Register::kAO_UPDATE_Source_SelectId, kAO_Trigger_Select_RegisterId),

      kAO_Config_Bank0Id                = 27,
      kBank0AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank0Id),
      kBank0AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank0Id),
      kBank0AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank0Id),
      kBank0AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank0Id),

      kAO_Config_Bank1Id                = 28,
      kBank1AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank1Id),
      kBank1AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank1Id),
      kBank1AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank1Id),
      kBank1AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank1Id),

      kAO_Config_Bank2Id                = 29,
      kBank2AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank2Id),
      kBank2AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank2Id),
      kBank2AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank2Id),
      kBank2AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank2Id),

      kAO_Config_Bank3Id                = 30,
      kBank3AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank3Id),
      kBank3AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank3Id),
      kBank3AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank3Id),
      kBank3AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank3Id),

      kAO_Config_Bank4Id                = 31,
      kBank4AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank4Id),
      kBank4AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank4Id),
      kBank4AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank4Id),
      kBank4AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank4Id),

      kAO_Config_Bank5Id                = 32,
      kBank5AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank5Id),
      kBank5AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank5Id),
      kBank5AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank5Id),
      kBank5AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank5Id),

      kAO_Config_Bank6Id                = 33,
      kBank6AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank6Id),
      kBank6AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank6Id),
      kBank6AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank6Id),
      kBank6AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank6Id),

      kAO_Config_Bank7Id                = 34,
      kBank7AO_OffsetId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_OffsetId, kAO_Config_Bank7Id),
      kBank7AO_ReferenceId              = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_ReferenceId, kAO_Config_Bank7Id),
      kBank7AO_Update_ModeId            = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_Update_ModeId, kAO_Config_Bank7Id),
      kBank7AO_BipolarId                = nNIMXRegisterMap120_mBuildFieldId(tAO_Config_Bank_t::kAO_BipolarId, kAO_Config_Bank7Id),

      kAO_FIFO_Data_RegisterId          = 35,
      kAO_FIFO_DataId                   = nNIMXRegisterMap120_mBuildFieldId(tAO_FIFO_Data_Register::kAO_FIFO_DataId, kAO_FIFO_Data_RegisterId),

      kAO_FIFO_Status_RegisterId        = 36,
      kAO_FIFO_StatusId                 = nNIMXRegisterMap120_mBuildFieldId(tAO_FIFO_Status_Register::kAO_FIFO_StatusId, kAO_FIFO_Status_RegisterId),


      kMaxRegisterId = 36

   } tId;

   tAO(tBusSpaceReference addrSpace, nMDBG::tStatus2* statusChain = NULL);
   tAO();
   void initialize(tBusSpaceReference addrSpace, u32 addressOffset, nMDBG::tStatus2* statusChain = NULL);
   void reset(nMDBG::tStatus2* statusChain = NULL);
   virtual ~tAO();

   inline tBusSpaceReference getBusSpaceReference(void) const;

   inline void setAddressOffset(u32 value, nMDBG::tStatus2* statusChain = NULL);
   inline u32  getAddressOffset(nMDBG::tStatus2* statusChain = NULL);
   inline tBoolean isDirty(tId id, nMDBG::tStatus2* statusChain = NULL);
   inline void markDirty(tId id, nMDBG::tStatus2* statusChain = NULL);
   inline void markClean(tId id, nMDBG::tStatus2* statusChain = NULL);

   inline void markDirty(nMDBG::tStatus2* statusChain = NULL);
   inline void markClean(nMDBG::tStatus2* statusChain = NULL);

private:
   void _initialize(nMDBG::tStatus2* statusChain = NULL);
   tBusSpaceReference _addrSpace;
   u32 _addressOffset;
   u8 _dirtyVector[37];

};

#ifndef ___tAO_ipp___
#ifndef ___tAO_h_no_inline___
#include "tAO.ipp"
#endif

#endif

#endif


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// This file is autogenerated!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

