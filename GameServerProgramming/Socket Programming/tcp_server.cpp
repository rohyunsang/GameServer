main()
{
  s = socket(TCP);
  s.bind(5959);
  s.listen();
  s2 = s.accept();
  print(getpeeraddr(s2));
  while(true)
  {
    r = s2.recv();
    if(r.length <= 0)
      break;
    print(r);
  }
  s2.close();
}
