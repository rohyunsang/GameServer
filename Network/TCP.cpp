//<11.22.33.44> 
main() //trasmit
{
  s = socket(TCP);
  s.bind(any_port);
  s.connect("55.66.77.88:5959);
  s.send("hello");
  s.close();
}

//<55.66.77.88>
main() //receive
{
  s = socket(TCP);
  s.listen(5959);
  s2 = s.accept();
  print(getpeeraddr(s2));
  while(true){
     r = s2.rev();
     if(r.length ==0)
       break;
    print(r);
  }
}
s2.close();
            

