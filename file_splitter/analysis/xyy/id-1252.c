//----- (00000001800638A0) ----------------------------------------------------
_QWORD *__fastcall CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::`vector deleting destructor'(
        _QWORD *Block,
        char a2)
{
  CTls13Handshake<CTls13ServerContext,CTls13ExtServer>::~CTls13Handshake<CTls13ServerContext,CTls13ExtServer>(Block);
  if ( (a2 & 1) != 0 )
    operator delete(Block);
  return Block;
}

