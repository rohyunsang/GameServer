std::recursive_mutex mx;
lock_guard<recursize_mutex> lock(mx);
read(x);
write(x);
sum(x);

//이렇게 하면 로컬 변수 lock 객체가 사라질 때 자동으로 mx.unlcok()이 실행됩니다.

//c++ code
std::mutex mx;
{
    std::lock_guard<std::mutex> lock(mx);
    read(x);
    write(y);
    sum(x);
}
