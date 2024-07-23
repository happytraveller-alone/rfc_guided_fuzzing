//----- (0000000180063860) ----------------------------------------------------
_QWORD *__fastcall CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::`scalar deleting destructor'(
        _QWORD *Block,
        char a2)
{
  CTls13Handshake<CTls13ClientContext,CTls13ExtClient>::~CTls13Handshake<CTls13ClientContext,CTls13ExtClient>(Block);
  if ( (a2 & 1) != 0 )
    operator delete(Block);
  return Block;
}

