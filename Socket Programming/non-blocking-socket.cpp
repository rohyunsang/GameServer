List<Socket> sockets;
void NonBlockSocketOperation(){
  foreach(s in sockets)
  {
    (result, data) = s.receive();
    if(data.length > 0) 
    {
      print(data);
    }
    else if (result != EWOULDBLOCK)
    {
       //
    }
  }
}
