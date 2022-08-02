main()
{
  s = socket(TCP);
  s.bind(any_port);
  s.connect("55.66.77.88:5959");
  s.send("hello");
  s.close();
}

