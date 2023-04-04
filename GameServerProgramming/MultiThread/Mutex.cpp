std::mutex mx;
mx.lock();
read(x);
write(y);
sum(x);
mx.unlock();
