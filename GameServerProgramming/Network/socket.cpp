main(){ //transmit
  s = socket(UDP);
  s.bind(any_port);
  s.sendTO("55.66.77.88:5969","hello");
  s.close();
}


main(){  //receive
  s = socket(UDP);
  s.bind(5959);
  r = s.recvfrom();
  prinf(r.srcAddrPort, r.data);
  s.colse();
}

//UDP just pass a socket dont matter that others guys receive or not 
