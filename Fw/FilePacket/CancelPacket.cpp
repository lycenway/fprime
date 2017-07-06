// ====================================================================== 
// \title  CancelPacket.cpp
// \author bocchino
// \brief  cpp file for FilePacket::CancelPacket
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
// 
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ====================================================================== 

#include <Fw/FilePacket/FilePacket.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

  void FilePacket::CancelPacket ::
    initialize(const U32 sequenceIndex)
  {
    this->header.initialize(FilePacket::T_CANCEL, sequenceIndex);
  }

  U32 FilePacket::CancelPacket ::
    bufferSize(void) const
  {
    return this->header.bufferSize();
  }

  SerializeStatus FilePacket::CancelPacket ::
    toBuffer(Buffer& buffer) const
  {
    SerialBuffer serialBuffer(
        reinterpret_cast<U8*>(buffer.getdata()),
        buffer.getsize()
    );
    return this->header.toSerialBuffer(serialBuffer);
  }

  SerializeStatus FilePacket::CancelPacket ::
    fromSerialBuffer(SerialBuffer& serialBuffer)
  {

    FW_ASSERT(this->header.type == T_CANCEL);

    if (serialBuffer.getBuffLeft() != 0)
      return FW_DESERIALIZE_SIZE_MISMATCH;

    return FW_SERIALIZE_OK;

  }

}